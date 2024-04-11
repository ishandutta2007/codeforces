#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = 1e9L + 7;

const int N = 121, M = 1211;

int x[N], y[N];
ll dp[N][M];

ll c[M][M];

int main() {
	for(int i = 0; i < M; i ++) {
		c[i][0] = 1;
		for(int j = 1; j <= i; j ++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	}
	ios :: sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) cin >> x[i];
	for(int i = 1; i <= n; i ++) cin >> y[i];

	dp[0][0] = 1;
	for(int i = 0; i <= n; i ++)
		for(int j = 0; j < M; j ++)
			for(int k = 0; k <= y[i + 1] && j + x[i + 1] - k >= 0; k ++) {
				dp[i + 1][j + x[i + 1] - k] += dp[i][j] * c[j + x[i + 1]][k];
				dp[i + 1][j + x[i + 1] - k] %= mod;
			}

	ll ans = dp[n + 1][0];
	int m = accumulate(x, x + n + 1, 0);
	for(int i = 1; i <= n; i ++) {
		ans *= c[m][x[i]];
		ans %= mod;
		m -= x[i];
	}
	cout << ans << '\n';
}