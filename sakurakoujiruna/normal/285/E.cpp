#include <bits/stdc++.h>
using namespace std;

const int N = 1011;
using ll = long long;
const int Mod = (int)1e9 + 7;

int dp[N][N][2][2]; // [i][good pos][i used][i+1 used]
void upd(int &x, int y) {
	if(y >= Mod) y -= Mod;
	x += y;
	if(x >= Mod) x -= Mod;
}

ll fac[N], inv[N];
ll binom(int n, int m) {
	return fac[n] * inv[m] % Mod * inv[n - m] % Mod;
}

int main() {
	fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for(int i = 2; i < N; i ++)
		inv[i] = (Mod - Mod / i) * inv[Mod % i] % Mod;
	for(int i = 2; i < N; i ++) {
		fac[i] = fac[i - 1] * i % Mod;
		inv[i] = inv[i - 1] * inv[i] % Mod;
	}

	ios :: sync_with_stdio(false);
	int n, m; cin >> n >> m;
	dp[1][0][0][0] = 1;
	dp[1][1][0][1] = 1;
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= n; j ++) {
			// bad
			upd(dp[i + 1][j][0][0], dp[i][j][0][0] + dp[i][j][1][0]);
			upd(dp[i + 1][j][1][0], dp[i][j][0][1] + dp[i][j][1][1]);

			// i - 1
			upd(dp[i + 1][j + 1][0][0], dp[i][j][0][0]);
			upd(dp[i + 1][j + 1][1][0], dp[i][j][0][1]);

			// i + 1
			upd(dp[i + 1][j + 1][0][1], dp[i][j][0][0] + dp[i][j][1][0]);
			upd(dp[i + 1][j + 1][1][1], dp[i][j][0][1] + dp[i][j][1][1]);
		}

	ll ans = 0;
	for(int k = m; k <= n; k ++) {
		ll sum = (dp[n][k][0][0] + dp[n][k][1][0]) * fac[n - k] % Mod;
		int sgn = ((k - m) & 1) ? -1 : 1;
		ans += sgn * sum * binom(k, m);
		ans %= Mod;
	}

	cout << (ans + Mod) % Mod << '\n';
	return 0;
}