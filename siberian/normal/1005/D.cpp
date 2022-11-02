#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 1e6 + 10;
int dp[MAXN][3];
string s;
int n;
void solve() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < 3; j++) dp[i][j] = -1e9;
	dp[0][0] = 0; 
	for (int i = 1; i <= n; i++) {
		int x = (s[i - 1] - '0') % 3;
		for (int j = 0; j < 3; j++)
			chkmax(dp[i][x], dp[i - 1][j]);
		for (int j = 0; j < 3; j++) {
			chkmax(dp[i][(x + j) % 3], dp[i - 1][j]);
			if ((x + j) % 3 == 0) 
				dp[i][(x + j) % 3]++;
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 3; j++)
		chkmax(ans, dp[i][j]);
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}