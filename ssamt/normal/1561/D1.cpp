#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j;
	int t, n, m;
	scanf("%d %d", &n, &m);
	long long d[n+1];
	long long sum[n+1];
	long long div[n+1];
	d[1] = 1;
	sum[1] = 1;
	div[1] = 0;
	for(i=2; i<=n; i++) {
		div[i] = div[i-1];
		for(j=2; j*j<=i; j++) {
			if(i%j == 0) {
				div[i] = (m+div[i]-d[i/j-1])%m;
				div[i] = (div[i]+d[i/j])%m;
				if(j*j != i) {
					div[i] = (m+div[i]-d[j-1])%m;
					div[i] = (div[i]+d[j])%m;
				}
			}
		}
		div[i]++;
		d[i] = (div[i]+sum[i-1])%m;
		sum[i] = (sum[i-1]+d[i])%m;
	}
	printf("%lld\n", d[n]);
}