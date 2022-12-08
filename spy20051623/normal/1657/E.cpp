#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

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

long long C[300][300], dp[300][300];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	--n;
	C[0][0] = 1;
	for (int i = 1; i < 300; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j <= n; ++j) {
			long long x = quickpow(k - i, j * (j - 1) / 2);
			long long y = quickpow(k - i, j);
			for (int l = 0; l <= n - j; ++l) {
				dp[i + 1][l + j] = (dp[i + 1][l + j] + dp[i][l] * C[n - l][j] % mod * x) % mod;
				x = x * y % mod;
			}
		}
	}
	cout << dp[k][n];
	return 0;
}