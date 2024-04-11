#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

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
	int h, i, j;
	int t, n, l, r;
	int lp, rp;
	long long answer;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d %d", &n, &l, &r);
		int a[n];
		for(i=0; i<n; i++) {
			scanf("%d", &a[i]);
		}
		qsort(a, n, sizeof(int), cmp);
		lp = n;
		rp = n;
		answer = 0;
		for(i=0; i<n; i++) {
			while(a[lp-1]+a[i] >= l && lp > 0) {
				lp--;
			}
			while(a[rp-1]+a[i] > r && rp > 0) {
				rp--;
			}
			answer += rp-lp;
			if(lp <= i && i < rp) {
				answer--;
			}
		}
		printf("%lld\n", answer/2);
	}
}