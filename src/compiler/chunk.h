#ifndef scute_chunk_h
#define scute_chunk_h

#include "common.h"
#include "value.h"
#include "hashmap.h"

typedef enum {
	OP_RETURN,
	OP_CONSTANT,
	OP_NEGATE,
	OP_MULTIPLY,
	OP_DIVIDE,
	OP_SUBTRACT,
	OP_ADD,
	OP_MODULO,
	OP_NULL,
	OP_TRUE,
	OP_FALSE,
	OP_NOT,
	OP_LESS,
	OP_GREATER,
	OP_EQUALS,
	OP_LESS_EQUALS,
	OP_GREATER_EQUALS,
	OP_PRINT,
	OP_PI,
	OP_TAU,
	OP_E,
	OP_DRAW,
	OP_POP,
	OP_DEF_GLOBAL,
	OP_GET_GLOBAL,
	OP_DEF_LOCAL,
	OP_GET_LOCAL,
	OP_DEF_CLOSURE,
	OP_GET_CLOSURE,
	OP_JMP_FALSE,
	OP_LIMIT,
	OP_T,
	OP_CLOSURE,
	OP_DEREF,
	OP_DIMS,
	OP_POS
} OpCode;

typedef struct {
	int count;
	int capacity;
	uint8_t* code;
	ValueArray constants;
	int* opsPerLine;
	int* lineNums;
	int lineCount;
	int lineCapacity;
	int previousLine;
	HashMap* map; 
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
void freeChunk(Chunk* chunk);

int getLine(Chunk* chunk, int opIndex);

void writeConstant(Chunk* chunk, Value value, int line);
void writeOperatorBundle(Chunk* chunk, OpCode op, uint64_t value, int line);
uint64_t writeValue(Chunk* chunk, Value value, int line);
int writeVariableData(Chunk* chunk, uint64_t value);
#endif