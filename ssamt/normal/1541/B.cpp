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
		int a[n+1];
		for(i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		int answer = 0;
		for(i=1; i<=n; i++) {
			for(j=a[i]-i%a[i]; j<=n; j += a[i]) {
				if(i < j && (long long)a[i]*a[j] == i+j) {
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}