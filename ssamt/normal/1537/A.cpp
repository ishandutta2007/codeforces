#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j;
	long long t, n;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		int num;
		int sum = 0;
		for(i=0; i<n; i++) {
			scanf("%d", &num);
			sum += num;
		}
		if(sum == n) {
			printf("0\n");
		} else if(sum < n) {
			printf("1\n");
		} else {
			printf("%d\n", sum-n);
		}
	}
}