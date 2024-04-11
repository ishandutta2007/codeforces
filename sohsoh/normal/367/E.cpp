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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll SQ = 320;

inline void mkey(int& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int dp[2][SQ][SQ], n, m, x;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> x;
	if (n > m) return cout << 0 << endl, 0;

	dp[0][0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				int r = i & 1;
				dp[r][j][k] = 0;
				if (j) mkey(dp[r][j][k] += dp[1 - r][j - 1][k]); // ()
				if (i != x) mkey(dp[r][j][k] += dp[1 - r][j][k]); // -
				if (i != x && j) mkey(dp[r][j][k] += dp[1 - r][j - 1][k + 1]); // )
				if (k) mkey(dp[r][j][k] += dp[1 - r][j][k - 1]); // (
			}
		}
	}
	
	ll fact = 1;
	for (int i = 1; i <= n; i++) fact = fact * i % MOD;
	cout << dp[m & 1][n][0] * fact % MOD << endl;
	return 0;
}