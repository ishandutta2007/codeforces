///	D : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 111
#define mod 1000000007

typedef long long LL;

int n, m, x[N], y[N];
LL f[N][N*N], c[N*N][N];

LL expmod(LL a, int b) {
	LL rlt = 1, x = a;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	c[0][0] = 1;
	for (int i = 1; i < N * N; i ++) {
		c[i][0] = 1;
		for (int j = 1; j <= i && j < N; j ++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &x[i]), m += x[i];
	for (int i = 1; i <= n; i ++) scanf("%d", &y[i]);
	for (int j = x[n]; j <= y[n]; j ++) f[n][j] = 1;
	for (int i = n - 1; i >= 1; i --) {
		for (int j = x[i]; j <= m; j ++) {
			for (int k = 0; k <= j && k <= y[i]; k ++) {
				f[i][j] = (f[i][j] + c[j][k] * f[i+1][x[i+1]+j-k]) % mod;
			}
		}
	}
	LL ans = f[1][x[1]];
	for (int i = 1; i <= m; i ++) ans = ans * i % mod;
	for (int i = 1; i <= n; i ++) {
		LL rlt = 1;
		for (int j = 1; j <= x[i]; j ++) rlt = rlt * j % mod;
		ans = ans * expmod(rlt, mod - 2) % mod;
	}
	cout << ans << endl;
	return 0;
}