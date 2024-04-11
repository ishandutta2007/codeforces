#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 311;
const int M = 101, K = (int)2e5 + 911;
using ll = long long;
const ll Mod = (ll)1e9 + 7;

ll fac[K], inv[K];
ll binom(int n, int m) {
	if(m < 0) return 0;
	return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

ll a[N];
ll dp[M][N];

int main() {
	fac[0] = inv[0] = fac[1] = inv[1] = 1;
	for(int i = 2; i < K; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < K; i ++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = inv[i - 1] * inv[i] % Mod;
	}
	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> a[i];
	while(m --) {
		int l, r, k; cin >> l >> r >> k;
		if(r - l + 1 >= k) {
			for(int i = 0; i <= k; i ++) {
				dp[100 - k + i][l] += binom(k, i);
				dp[100 - k + i][r + 1 - k + i] -= binom(r - l + i, i);
			}
		} else {
			int d = r - l;
			dp[100 - d][l] += binom(k, k - d);
			dp[100 - d][l + 1] -= binom(k, k - d);
			for(int i = k - d + 1; i <= k; i ++) {
				dp[100 - k + i][l] += binom(k, i);
				dp[100 - k + i][r + 1 - k + i] -= binom(r - l + i, i);
			}
		}
	}
	/*
	for(int i = 100; i >= 96; i --) {
		for(int j = 0; j <= 15; j ++)
			cout << dp[i][j] << ' ';
		cout << '\n';
	}
	*/
	for(int i = 0; i < M; i ++) {
		for(int j = 1; j < N; j ++) {
			dp[i][j] += dp[i][j - 1];
			if(i != 0)
				dp[i][j] += dp[i - 1][j - 1];
			dp[i][j] %= Mod;
		}
	}
	for(int i = 1; i <= n; i ++) {
		a[i] += dp[M - 1][i];
		cout << (a[i] % Mod + Mod) % Mod << ' ';
	}
	cout << '\n';
	return 0;
}