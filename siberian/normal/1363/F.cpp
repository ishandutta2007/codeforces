#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int INF = 1e9 + 228 + 1337;

bool check(string s, string t) {
	sort(all(s));
	sort(all(t));
	return s == t;
}

void solve() {
	int n;
	vector<string> a(2);
	cin >> n >> a[0] >> a[1];
	if (!check(a[0], a[1])) {
		cout << -1 << "\n";
		return;
	}
	vector<vector<int>> dp(n + 1, vector<int> (n + 1, INF));
	dp[0][0] = 0;
	vector<vector<vector<int>>> cnt(2, vector<vector<int>> (n + 1, vector<int> (26, 0)));
	reverse(all(a[0]));
	reverse(all(a[1]));
	for (int it = 0; it < 2; it++) {
		for (int i = 1; i <= n; i++) {
			for (int alpha = 0; alpha < 26; alpha++) {
				cnt[it][i][alpha] = cnt[it][i - 1][alpha];
			}
			cnt[it][i][a[it][i - 1] - 'a']++;
		}
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i + 1 <= n && a[0][i] == a[1][j]) {
				assert(j + 1 <= n); 
				chkmin(dp[i + 1][j + 1], dp[i][j]);
			}
			char x = a[1][j] - 'a';
			if (j + 1 <= n && cnt[0][i][x] > cnt[1][j][x]) {
				chkmin(dp[i][j + 1], dp[i][j]);
			}
			if (i + 1 <= n) {
				chkmin(dp[i + 1][j], dp[i][j] + 1);
			}
		}
	}
	int ans = -1;
	if (dp[n][n] != INF) {
		ans = dp[n][n];
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}