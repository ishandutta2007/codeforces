#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2000 + 10;
const ll MOD = 1e9 + 7;
const ll F = 500000004;

ll dp[MAXN][MAXN], n, m, k;

inline void solve() {
	for (int i = 0; i < n + 5; i++)
		for (int j = 0; j < n + 5; j++)
			dp[i][j] = 0;

	cin >> n >> m >> k;
	m = n - m;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = (k + dp[i - 1][0]) % MOD;
		for (int j = 1; j <= m; j++) {
			ll delta = (dp[i - 1][j - 1] - dp[i - 1][j] + MOD) % MOD;
			dp[i][j] = (dp[i - 1][j] + delta * F) % MOD;
		}
	}

	cout << dp[n][m] << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}