#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 500 + 10;
const ll MAXK = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXK][MAXN][MAXN], n, m, k, cost[2][MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			cin >> cost[0][i][j];
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			cin >> cost[1][i][j];

	for (int t = 2; t <= k; t += 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				dp[t][i][j] = INF;
				if (i < n) dp[t][i][j] = min(dp[t][i][j], dp[t - 2][i + 1][j] + 2 * cost[1][i][j]);
				if (i > 1) dp[t][i][j] = min(dp[t][i][j], dp[t - 2][i - 1][j] + 2 * cost[1][i - 1][j]);	
				if (j < m) dp[t][i][j] = min(dp[t][i][j], dp[t - 2][i][j + 1] + 2 * cost[0][i][j]);
				if (j > 1) dp[t][i][j] = min(dp[t][i][j], dp[t - 2][i][j - 1] + 2 * cost[0][i][j - 1]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (k & 1) cout << -1 << sep;
			else cout << dp[k][i][j] << sep;
		}

		cout << endl;
	}
	return 0;
}