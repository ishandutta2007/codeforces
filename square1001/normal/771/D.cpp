#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int dp[85][85][85][3];
int main() {
	int n; string s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'V') a[i] = 0;
		else if (s[i] == 'K') a[i] = 1;
		else a[i] = 2;
	}
	vector<int> c(3);
	vector<vector<int> > g(3);
	for (int i = 0; i < n; ++i) ++c[a[i]], g[a[i]].push_back(i);
	for (int i = 0; i <= c[0]; ++i) {
		for (int j = 0; j <= c[1]; ++j) {
			for (int k = 0; k <= c[2]; ++k) {
				for (int l = 0; l < 3; ++l) {
					if (i + j + k >= 1) dp[i][j][k][l] = inf;
				}
			}
		}
	}
	for (int i = 0; i <= c[0]; ++i) {
		for (int j = 0; j <= c[1]; ++j) {
			for (int k = 0; k <= c[2]; ++k) {
				for (int x = 0; x < 3; ++x) {
					int r = (x == 0 ? i : (x == 1 ? j : k));
					if (r == 0) continue;
					int cnt = 0;
					for (int l = 1; l <= 2; ++l) {
						int rd = ((x + l) % 3 == 0 ? i : ((x + l) % 3 == 1 ? j : k));
						for (int y = 0; y < rd; ++y) {
							if (g[(x + l) % 3][y] > g[x][r - 1]) ++cnt;
						}
					}
					for (int y = 0; y < 3; ++y) {
						if (x == 1 && y == 0) continue;
						dp[i][j][k][x] = min(dp[i][j][k][x], dp[i - (x == 0 ? 1 : 0)][j - (x == 1 ? 1 : 0)][k - (x == 2 ? 1 : 0)][y] + cnt);
					}
				}
			}
		}
	}
	int ans = inf;
	for (int i = 0; i < 3; ++i) {
		ans = min(ans, dp[c[0]][c[1]][c[2]][i]);
	}
	cout << ans << endl;
	return 0;
}