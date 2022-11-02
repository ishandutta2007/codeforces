#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll Mod = 1e9L + 7;

const int N = 2e3L + 11;
ll dp[N][N];

int main() {
	ios :: sync_with_stdio(false);
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i ++)
		dp[i][1] = 1;
	for(int j = 1; j < k; j ++)
		for(int i = 1; i <= n; i ++)
			for(int t = i; t <= n; t += i) {
				dp[t][j + 1] += dp[i][j];
				dp[t][j + 1] %= Mod;
			}

	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		ans += dp[i][k];
	cout << ans % Mod << '\n';
	return 0;
}