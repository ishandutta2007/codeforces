#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 2010;
const int INF = -1e9 - 10;
int n, h, l, r;
int a[MAXN], dp[MAXN][MAXN];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> h >> l >> r;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < h; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int now = 0; now < h; now++) {
			if (dp[i][now] == INF) continue;
			for (int x = -1; x <= 0; x++) {
				int nxt = (now + a[i + 1] + x) % h;
				chkmax(dp[i + 1][nxt], dp[i][now] + (nxt >= l && nxt <= r));
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++)
		chkmax(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}