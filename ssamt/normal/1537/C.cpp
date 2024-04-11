#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int cmp(const void* num1, const void* num2) {
	int a = *(int*)num1;
	int b = *(int*)num2;
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	long long h, i, j;
	long long t;
	long long n;
	int min;
	int idx;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), cmp);
		if(n <= 2) {
			for(i=0; i<n; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
		} else {
			min = a[1]-a[0];
			idx = 0;
			for(i=1; i<n-1; i++) {
				if(a[i+1]-a[i] < min) {
					min = a[i+1]-a[i];
					idx = i;
				}
			}
			for(i=idx+1; i<n; i++) {
				printf("%d ", a[i]);
			}
			for(i=0; i<=idx; i++) {
				printf("%d ", a[i]);
			}
			printf("\n");
		}
	}
}