#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t, n, m;
	scanf("%d %d", &n, &m);
	int d[n+1];
	int sum[n+1];
	int div[n+1];
	int diff[n+1];
	d[1] = 1;
	sum[1] = 0;
	div[1] = 0;
	for(i=1; i<=n; i++) {
		diff[i] = 1;
	}
	for(i=2; i<=n; i++) {
		div[i] = div[i-1];
		div[i] = (div[i-1]+diff[i])%m;
		sum[i] = (sum[i-1]+d[i-1])%m;
		d[i] = (div[i]+sum[i])%m;
		for(j=i*2; j<=n; j+=i) {
			diff[j] = ((long long)m+diff[j]+d[i]-d[i-1])%m;
		}
	}
	printf("%d\n", d[n]);
}