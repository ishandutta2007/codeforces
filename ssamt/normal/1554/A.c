#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	int t;
	int n;
	long long max;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d", &n);
		long long a[n];
		for(j=0; j<n; j++) {
			scanf("%lld", &a[j]);
		}
		max = 0;
		for(j=0; j<n-1; j++) {
			if(a[j]*a[j+1] > max) {
				max = a[j]*a[j+1];
			}
		}
		printf("%lld\n", max);
	}
}