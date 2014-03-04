/*
 ============================================================================
 Name        : ZeroOneKnapsack.c
 Author      : Somshubra Majumdar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

void createList(int n);
void sort(int n);
double select(int cap, int n);

typedef struct Obj {
	int w;
	double p;
} Object;

Object *cmp1, *cmp2;
int objectCompare(const void *a, const void *b){
	cmp1 = (Object*) a;
	cmp2 = (Object*) b;
	return (int) cmp2->p/cmp2->w - cmp1->p/cmp1->w;
}
Object a[SIZE];

int main(void) {
	double profit;
	int n, capacity;

	setbuf(stdout, NULL);

	printf("Enter no of objects : ");
	scanf("%d", &n);

	createList(n);
	sort(n);

	printf("Enter maximum capacity : ");
	scanf("%d", &capacity);

	profit = select(capacity, n);
	printf("Profit is : %lf", profit);

	return EXIT_SUCCESS;
}

void createList(int n){
	int i;

	for(i = 0; i < n; i++){
		printf("Enter Weight and Profit:\n");
		scanf("%d%lf", &a[i].w, &a[i].p);
	}
}

void sort(int n){
	qsort(a, n, sizeof(Object), objectCompare);
}

double select(int cap, int n){
	double profit = 0.0;
	int currentCap = 0, i;

	for(i = 0; i < n; i++){
		if(currentCap + a[i].w <= cap){
			printf("%d\t%lf\n", a[i].w, a[i].p);
			currentCap += a[i].w;
			profit += a[i].p;
		}

		if(currentCap == cap)
			break;
	}
	return profit;
}
