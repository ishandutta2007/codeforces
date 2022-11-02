#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	long long i, j, k;
	int t;
	int n, m;
	int a, b;
	long long sum;
	int r;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d", &n);
		int a[n];
		sum = 0;
		for(j=0; j<n; j++) {
			scanf("%d", &a[j]);
			sum += a[j];
		}
		r = sum%n;
		printf("%lld\n", (long long)(n-r)*r);
	}
}