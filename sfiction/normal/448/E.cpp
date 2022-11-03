/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 448E
 */
#include <cstdio>

typedef unsigned long long ull;

const ull limit = 1E5, MAXN = 1E5;

ull n, k;
ull cnt, d[MAXN];
ull outCnt;

void output(int n, int kk){
	if (n == 0 || kk == k){
		printf("%I64u ", d[n]);
		--outCnt;
		return;
	}
	for (int i=0;outCnt && i<=n;++i)
		if (d[n] % d[i] == 0)
			output(i, kk + 1);
}

int main(){
	scanf("%I64u%I64u", &n, &k);
	ull i;
	cnt = 0;
	for (i = 1; i * i < n; ++i)
		if (n % i == 0)
			d[cnt++] = i;
	for (i -= i * i > n; i; --i)
		if (n % i == 0)
			d[cnt++] = n / i;
	outCnt = limit;
	output(cnt - 1, 0);
	return 0;
}