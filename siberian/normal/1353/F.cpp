#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int INF = 4e18;
const int MAXN = 110;
int a[MAXN][MAXN];
int n, m;
int dp[MAXN][MAXN];

int calc(int start) {
	if (start > a[0][0]) return INF;
	dp[0][0] = a[0][0] - start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			dp[i][j] = INF;
			if (i > 0 && start + i + j <= a[i][j] && dp[i - 1][j] != INF) chkmin(dp[i][j], dp[i - 1][j] + a[i][j] - start - i - j);
			if (j > 0 && start + i + j <= a[i][j] && dp[i][j - 1] != INF) chkmin(dp[i][j], dp[i][j - 1] + a[i][j] - start - i - j);
		}
	}
	return dp[n - 1][m - 1];
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = calc(a[0][0]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			chkmin(ans, calc(a[i][j] - i - j));
		}
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