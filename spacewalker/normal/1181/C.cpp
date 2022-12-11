#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int NMAX = 1005;
constexpr int INF = 1000000000;

char grid[NMAX][NMAX];
int fsbot[NMAX][NMAX], fsright[NMAX][NMAX];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", grid[i]);
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i < n - 1) {
				fsbot[i][j] = (grid[i][j] == grid[i+1][j] ? fsbot[i+1][j] + 1 : 0);
			} 
			if (j < m - 1) {
				fsright[i][j] = (grid[i][j] == grid[i][j+1] ? fsright[i][j+1] + 1 : 0);
			}
		}
	}
	vector<vector<pair<int, int>>> intByCol(m);
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (intByCol[j].empty() || grid[i][j] != grid[i-1][j]) {
				intByCol[j].emplace_back(i, 1);
			} else {
				intByCol[j].back().second++;
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < m; ++j) {
		int ict = intByCol[j].size();
		for (int citv = 1; citv < ict - 1; ++citv) {
			if (intByCol[j][citv-1].second < intByCol[j][citv].second) continue;
			if (intByCol[j][citv+1].second < intByCol[j][citv].second) continue;
			// we now need to check the fsrights
			int ilen = intByCol[j][citv].second;
			int contrib = INF;
			for (int offset = 0; offset < 3*ilen; ++offset) {
				contrib = min(contrib, fsright[intByCol[j][citv].first - ilen + offset][j]);
			}
			ans += contrib + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}