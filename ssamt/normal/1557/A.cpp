#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j, k;
	long long t, n;
	scanf("%lld", &t);
	for(h=0; h<t; h++) {
		scanf("%lld", &n);
		long long a[n];
		for(i=0; i<n; i++) {
			scanf("%lld", &a[i]);
		}
		long long max = a[0];
		long long sum = a[0];
		for(i=1; i<n; i++) {
			sum += a[i];
			if(a[i] > max) {
				max = a[i];
			}
		}
		printf("%.10f\n", (double)max+(double)(sum-max)/(n-1));
	}
}