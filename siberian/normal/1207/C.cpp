#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int INF = 1e18;

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	s += "0";
	vector<vector<int> > dp(n + 10, vector<int> (2, INF));
	dp[0][0] = b;
	for (int i = 1; i <= n; i++) {
		chkmin(dp[i][1], dp[i - 1][1] + a + 2 * b);
		if (s[i - 1] == '0') {
			chkmin(dp[i][1], dp[i - 1][0] + 2 * a + 2 * b);
			chkmin(dp[i][0], dp[i - 1][0] + a + b);
			chkmin(dp[i][0], dp[i - 1][1] + 2 * a + b);
		} 
	}

	/*cout << "dp = " << endl;
	for (int i = 0; i <= n; i++) {
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}*/

	cout << dp[n][0] << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}