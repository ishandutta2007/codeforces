#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int cmp(const void* num1, const void* num2) {
	long long* a = *(long long**)num1;
	long long* b = *(long long**)num2;
	if(a[1] > b[1]) {
		return 1;
	} else if(a[1] < b[1]) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j;
	int t, n;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		int k[n];
		int* a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &k[i]);
			a[i] = (int*)malloc(sizeof(int)*k[i]);
			for(j=0; j<k[i]; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		long long* r[n];
		for(i=0; i<n; i++) {
			r[i] = (long long*)malloc(sizeof(long long)*2);
			r[i][0] = k[i];
			r[i][1] = 0;
			for(j=0; j<k[i]; j++) {
				if(r[i][1]+j < a[i][j]+1) {
					r[i][1] = a[i][j]+1-j;
				}
			}
		}
		qsort(r, n, sizeof(long long*), cmp);
		for(i=n-2; i>=0; i--) {
			if(r[i+1][1]-r[i][0] > r[i][1]) {
				r[i][1] = r[i+1][1]-r[i][0];
			}
		}
		printf("%lld\n", r[0][1]);
	}
}