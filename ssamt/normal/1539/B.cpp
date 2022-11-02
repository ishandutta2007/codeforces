#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main() {
	long long h, i, j;
	long long n, q;
	long long l, r;
	long long answer;
	char s[100001];
	int sum[100001];
	scanf("%lld %lld", &n, &q);
	scanf("%s", s);
	sum[0] = 0;
	for(i=1; i<=n; i++) {
		sum[i] = sum[i-1]+s[i-1]-'a'+1;
	}
	for(h=0; h<q; h++) {
		scanf("%lld %lld", &l, &r);
		printf("%d\n", sum[r]-sum[l-1]);
	}
}