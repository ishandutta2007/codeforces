#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		for(i=1; i*i<n; i++);
		if(n <= (i-1)*(i-1)+i) {
			printf("%d %d\n", n-(i-1)*(i-1), i);
		} else {
			printf("%d %d\n", i, i*i-n+1);
		}
	}
}