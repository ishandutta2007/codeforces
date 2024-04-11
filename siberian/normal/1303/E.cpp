#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string s, t;

const int MAXN = 410;

int dp[MAXN][MAXN];

bool check(int len) {
	for (int i = 0; i <= s.size(); i++)
		for (int j = 0; j <= len; j++)
			dp[i][j] = -1e9;
	dp[0][0] = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= min(i, len); j++) {
			chkmax(dp[i + 1][j], dp[i][j]);
			if (j < len && s[i] == t[j]) chkmax(dp[i + 1][j + 1], dp[i][j]);
			if (dp[i][j] + len < t.size() && s[i] == t[dp[i][j] + len]) chkmax(dp[i + 1][j], dp[i][j] + 1); 
		}
	}
	return dp[n][len] == t.size() - len;
}

void solve() {
	cin >> s >> t;
	for (int i = 0; i <= t.size(); i++) {
		if (check(i)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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