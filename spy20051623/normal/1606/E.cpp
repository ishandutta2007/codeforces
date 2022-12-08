#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int mod = 998244353;
int n, x;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv[1000];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 1000; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[1000], ifac[1000];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 1000; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

ll C(int N, int M) {
	return fac[N] * ifac[M] % mod * ifac[N - M] % mod;
}

ll dp[505][505];
ll qp[505][505];

ll dfs(int cnt, int mx) {
	if (dp[cnt][mx] != -1) return dp[cnt][mx];
	if (mx > x) return 0;
	dp[cnt][mx] = 0;
	if (cnt == n) dp[cnt][mx] = 1;
	if (cnt > 1) dp[cnt][mx] += dfs(cnt, mx + cnt - 1);
	for (int i = 1; i <= n - cnt; ++i) {
		dp[cnt][mx] += C(n - cnt, i) * qp[cnt + i - 1][i] % mod * dfs(cnt + i, mx + cnt + i - 1) % mod;
	}
	dp[cnt][mx] %= mod;
	return dp[cnt][mx];
}

int main() {
//	freopen("in.txt", "r", stdin);
	invWork();
	facWork();
	for (int i = 0; i < 505; ++i) {
		for (int j = 0; j < 505; ++j) {
			qp[i][j] = quickpow(i, j);
		}
	}
	memset(dp, -1, sizeof dp);
	scanf("%d%d", &n, &x);
	ll ans = quickpow(x, n);
	for (int i = 1; i <= x; ++i) {
		ans -= n * dfs(1, i) % mod;
	}
	printf("%lld\n", (ans % mod + mod) % mod);
	return 0;
}