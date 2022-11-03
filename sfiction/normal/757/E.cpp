#include <cstdio>

const int MAXN = 1E6 + 10, MAXD = 20, MAXR = 1E6 + 10;
const int MOD = 1E9 + 7;

int np, prime[MAXN];
int isnp[MAXN], md[MAXN];
int f[MAXR][MAXD];

void getPrime(int n = MAXN - 1){
	np = 0;
	isnp[0] = isnp[1] = 1;
	for (int i = 2; i <= n; ++i){
		if (!isnp[i])
			prime[np++] = md[i] = i;
		for (int t = n / i, j = 0; prime[j] <= t; ++j){
			isnp[prime[j] * i] = 1;
			md[prime[j] * i] = prime[j];
			if (i % prime[j] == 0)
				break;
		}
	}
}

int main(){
	getPrime();
	for (int i = 0; i < MAXD; ++i)
		f[0][i] = 1 + !!i;
	for (int i = 1; i < MAXR; ++i){
		f[i][0] = 1;
		for (int j = 1; j < MAXD; ++j)
			if ((f[i][j] = f[i][j - 1] + f[i - 1][j]) >= MOD)
				f[i][j] -= MOD;
	}

	int q, r, n;
	scanf("%d", &q);
	while (q--){
		scanf("%d%d", &r, &n);
		int ans = 1;
		for (; n > 1; ){
			int d = md[n], cnt = 0;
			for (; md[n] == d; ++cnt, n /= md[n]);
			ans = 1ll * ans * f[r][cnt] % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}