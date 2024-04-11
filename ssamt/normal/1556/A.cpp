#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n, m;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		if((n+m)%2 == 1) {
			printf("-1\n");
		} else {
			if(n == 0 && m == 0) {
				printf("0\n");
			} else if(n == m) {
				printf("1\n");
			} else {
				printf("2\n");
			}
		}
	}
}