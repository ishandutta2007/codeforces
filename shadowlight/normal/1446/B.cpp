#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int N = 5007;
const int INF = 1e9 + 7;

int dp[N][N][2];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	string s, t;
	cin >> s >> t;
	s += '#';
	t += '@';

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			dp[i][j][0] = -INF;
			dp[i][j][1] = -INF;
		}
	}
	dp[0][0][0] = 0;

	int res = 0;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k < 2; ++k) {
				res = max(res, dp[i][j][k]);
				if (dp[i][j][k] == -INF) continue;
				if (i < n) dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (k ? -1 : 0));
				if (j < m) dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + (k ? -1 : 0));
				if (i < n && j < m && s[i] == t[j]) {
					dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][k] + 2);
				}
			}
		}
	}
	cout << res << "\n";

}