#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	int x[200000];
	int y[200000];
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%d", &x[i]);
		}
		for(i=0; i<n; i++) {
			y[i] = 0;
		}
		for(i=1; i<n; i++) {
			for(j=30; j>=0; j--) {
				if((x[i-1]^y[i-1])&(1<<j)) {
					if(!(x[i]&(1<<j))) {
						y[i] |= (1<<j);
					}
				}
			}
		}
		for(i=0; i<n; i++) {
			printf("%d ", y[i]);
		}
		printf("\n");
	}
}