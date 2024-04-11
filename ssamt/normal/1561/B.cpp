#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n, a, b;
	int minb;
	int maxb;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &a, &b);
		n = a+b;
		if(n%2 == 0) {
			minb = abs(a-b)/2;
			maxb = n-minb;
			printf("%d\n", (maxb-minb)/2+1);
			for(i=minb; i<=maxb; i+=2) {
				printf("%d ", i);
			}
			printf("\n");
		} else {
			minb = (abs(a-b)-1)/2;
			maxb = n-minb;
			printf("%d\n", maxb-minb+1);
			for(i=minb; i<=maxb; i+=1) {
				printf("%d ", i);
			}
			printf("\n");
		}
	}
}