#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>

/**
 * push - pushes a value onto the stack and updates pointers
 *
 * @top: top of stack
 * @bot: bottom of stack
 * @val: value to push
 * @mode: stack or queue mode (put on top or bottom)
 */

void push(stack_t **top, stack_t **bot, int val, int mode)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		printf("Error: malloc failed\n");
		exitwrap(EXIT_FAILURE, NULL, *top);
	}
	ptr->n = val;
	if (*top == NULL)
	{
		ptr->prev = NULL;
		ptr->next = NULL;
		*top = ptr;
		*bot = ptr;
	}
	else if (mode == STACKMODE)
	{
		ptr->next = NULL;
		ptr->prev = *top;
		(*top)->next = ptr;
		*top = ptr;
	}
	else if (mode == QUEUEMODE)
	{
		ptr->prev = NULL;
		ptr->next = *bot;
		(*bot)->prev = ptr;
		*bot = ptr;
	}
}

/**
 * pop - pop the top element of stack
 *
 * @top: top of the stack
 */

void pop(stack_t **top)
{
	stack_t *ptr = *top;

	if (ptr == NULL)

