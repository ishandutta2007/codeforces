#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int INF = 1000000007;
using llint = long long;
int a[505][505], b[505][505], dp[505][505][15];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) cin >> a[i][j];
	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) cin >> b[i][j];
	if (k % 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) cout << -1 << ' ';
			cout << endl;
		}
		return 0;
	}
	k /= 2;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		dp[i][j][0] = 0;
		for (int s = 1; s <= k; s++) {
			int si = max(1, i - s), ei = min(n, i + s);
			for (int ii = si - 1; ii <= ei + 1; ii++) {
				int sj = max(1, j - s + abs(i - ii));
				int ej = min(m, j + s - abs(i - ii));
				if (ii == si - 1) for (int jj = sj - 1; jj <= ej + 1; jj++) dp[ii][jj][s - 1] = INF;
				if (ii == ei + 1) for (int jj = sj - 1; jj <= ej + 1; jj++) dp[ii][jj][s - 1] = INF;
				dp[ii][sj - 1][s - 1] = dp[ii][ej + 1][s - 1] = INF;
			}
			for (int ii = si; ii <= ei; ii++) {
				int sj = max(1, j - s + abs(i - ii));
				int ej = min(m, j + s - abs(i - ii));
				for (int jj = sj; jj <= ej; jj++) {
					dp[ii][jj][s] = INF;
					if ((abs(ii - i) + abs(jj - j) + s) & 1) continue;
					dp[ii][jj][s] = min(dp[ii][jj][s], dp[ii + 1][jj][s - 1] + b[ii][jj]);
					dp[ii][jj][s] = min(dp[ii][jj][s], dp[ii - 1][jj][s - 1] + b[ii - 1][jj]);
					dp[ii][jj][s] = min(dp[ii][jj][s], dp[ii][jj + 1][s - 1] + a[ii][jj]);
					dp[ii][jj][s] = min(dp[ii][jj][s], dp[ii][jj - 1][s - 1] + a[ii][jj - 1]);
				}
			}
		}
		int mn = INF;
		for (int ii = i - k; ii <= i + k; ii++) for (int jj = j - k; jj <= j + k; jj++) {
			if (ii < 1 || jj < 1 || ii > n || jj > m) continue;
			if (abs(ii - i) + abs(jj - j) > k) continue;
			mn = min(mn, dp[ii][jj][k]);
		}
		cout << mn * 2 << ' ';
		if (j == m) cout << endl;
	}
	
	return 0;
}