#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, m;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &m);
		int a[2][m];
		for(i=0; i<2; i++) {
			for(j=0; j<m; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		if(m == 1) {
			printf("0\n");
			continue;
		}
		int answer = INT_MAX;
		int up = 0, down = 0;
		for(i=0; i<m; i++) {
			up += a[0][i];
		}
		for(i=0; i<m; i++) {
			up -= a[0][i];
			if(max(up, down) < answer) {
				answer = max(up, down);
			}
			down += a[1][i];
		}
		printf("%d\n", answer);
	}
}