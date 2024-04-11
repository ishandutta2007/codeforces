#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
	long long i, j, k;
	int t;
	int n;
	int m;
	long long max;
	long long temp;
	scanf("%d", &t);
	for(i=0; i<t; i++) {
		scanf("%d %d", &n, &m);
		int a[n];
		for(j=0; j<n; j++) {
			scanf("%d", &a[j]);
		}
		max = LLONG_MIN;
		for(j=n; j>1; j--) {
			for(k=j-1; k>0 && j*k>max; k--) {
				temp = (long long)j*k-(long long)m*(a[j-1]|a[k-1]);
				if(temp > max) {
					max = temp;
				}
			}
		}
		printf("%lld\n", max);
	}
}