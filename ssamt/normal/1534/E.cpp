#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int cmp(const void* num1, const void* num2) {
	int* a = *(int**)num1;
	int* b = *(int**)num2;
	if(a[1] > b[1]) {
		return -1;
	} else if(a[1] < b[1]) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j;
	int t, n, k;
	int r, q;
	scanf("%d %d", &n, &k);
	if(n%2 == 1 && k%2 == 0) {
		printf("-1\n");
	} else {
		q = (n-1)/k+1;
		if((q*k-n)%2 == 1) {
			q++;
		}
		r = (q*k-n)/2;
		if(r > 0) {
			while(((r-1)/n+1)*2+1 > q) {
				if(k%2 == 0) {
					q++;
					r += k/2;
				} else {
					q += 2;
					r += k;
				}
			}
		}
		int* ask[n];
		for(i=0; i<n; i++) {
			ask[i] = (int*)malloc(2*sizeof(int));
			ask[i][0] = i;
			ask[i][1] = r/n*2+1;
		}
		for(i=0; i<r%n; i++) {
			ask[i][1] += 2;
		}
		int answer = 0;
		for(i=0; i<q; i++) {
			printf("? ");
			for(j=0; j<k; j++) {
				printf("%d ", ask[j][0]+1);
				ask[j][1]--;
			}
			printf("\n");
			fflush(stdout);
			scanf("%d", &t);
			answer ^= t;
			qsort(ask, n, sizeof(int*), cmp);
		}
		printf("! %d\n", answer);
	}
}