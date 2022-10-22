#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dp[MAXN][2][2][2];

inline void upd(int& a, int b) {
	a = min(a, b);
}

inline int solve() {
	string s;
	cin >> s;
	s = "12" + s;
	for (int i = 2; i <= s.size(); i++) {
		for (int a = 0; a < 2; a++) for (int b = 0; b < 2; b++) for (int c = 0; c < 2; c++) dp[i][a][b][c] = INF;	
		bool d_2 = (s[i] == s[i - 2]);
		bool d_1 = (s[i] == s[i - 1]);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				upd(dp[i][j][k][0], dp[i - 1][0][j][k]);
				upd(dp[i][j][k][0], dp[i - 1][1][j][k]);
				upd(dp[i][j][k][1], dp[i - 1][0][j][k] + 1);
				upd(dp[i][j][k][1], dp[i - 1][1][j][k] + 1);
			}
		}

		if (d_2) dp[i][0][0][0] = dp[i][0][1][0] = INF;
		if (d_1) dp[i][0][0][0] = dp[i][1][0][0] = INF;
	}

	int ans = INF;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++) ans = min(ans, dp[s.size() - 1][i][j][k]);
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}