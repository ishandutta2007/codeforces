#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
int n, k, m;
vector<int> a;
void read() {
	cin >> n >> m >> k;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
}

const int INF = 1e18;
const int MAXN = 3e5 + 10, MAXM = 15;
int dp[MAXN][MAXM];

int ans;

void run() {
	for (int i = 0; i < MAXM; i++)
		dp[0][i] = -INF;
	ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			if (j != 1) {
				dp[i][j] = dp[i - 1][(j - 1 + m) % m] + a[i - 1];
				chkmax(ans, dp[i][j]);
			} 
			else {
				dp[i][j] = max(-k, max(dp[i - 1][0], 0LL) + a[i - 1] - k);
				chkmax(ans, dp[i][j]);
			}
		}
	}

	for (int i = 1; i < m; i++)
		dp[0][i] = -1e18;
	dp[0][0] = -k;
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
			chkmax(ans, dp[i][j]);
		}
 
		dp[i][0] = max(-k, dp[i - 1][m - 1] - k + a[i - 1]);
		chkmax(ans, dp[i - 1][m - 1] - k + a[i - 1]);
		if (m == 1) {
			dp[i][0] = max(-k, max(dp[i - 1][0], 0LL) - k + a[i - 1]);
			chkmax(ans, max(dp[i - 1][0], 0LL) - k + a[i - 1]);
		}
	}

		for (int i = 1; i < m; i++)
		dp[0][i] = -1e18;
	dp[0][0] = -k;
 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			dp[i][j] = max(-k, dp[i - 1][j - 1] + a[i - 1]);
			chkmax(ans, dp[i][j]);
		}
		dp[i][0] = max(-k, dp[i - 1][m - 1] + a[i - 1] - k);
		chkmax(ans, dp[i][0]);
	}

}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}