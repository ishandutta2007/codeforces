#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n, a, b;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &b, &a);
		if(a >= 2*b) {
			printf("%d\n", (a-1)/2);
		} else {
			printf("%d\n", a-b);
		}
	}
}