#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

#define INF 10000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, k; cin >> n >> m >> k;
	vector<string> grid(n, "");
	for (int i = 0; i < n; ++i) {
		cin >> grid[i];
	}
	vector<vector<int>> minSkipRange(n, vector<int>(k+1, INF));
	for (int i = 0; i < n; ++i) {
		vector<int> prefCounts(m+1, 0);
		for (int j = 1; j <= m; ++j) {
			prefCounts[j] = prefCounts[j-1] + (grid[i][j-1] - '0');
		}
		if (prefCounts[m] <= k) {
			minSkipRange[i][prefCounts[m]] = 0; // skipping all the classes? don't attend!
		}
		for (int l = 0; l < m; ++l) {
			for (int r = l; r < m; ++r) {
				int skipCount = prefCounts[m] - (prefCounts[r+1] - prefCounts[l]);
				if (skipCount <= k) {
					minSkipRange[i][skipCount] = min(minSkipRange[i][skipCount], r - l + 1);
				}
			}
		}
	}
	vector<vector<int>> bestSkip(n + 1, vector<int>(k + 1, INF));
	for (int i = 0; i <= k; ++i) {
		bestSkip[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		for (int sc = 0; sc <= k; ++sc) {
			for (int skipCount = 0; skipCount <= sc; ++skipCount) {
				bestSkip[i][sc] = min(bestSkip[i][sc], bestSkip[i-1][sc - skipCount] + minSkipRange[i-1][skipCount]);
			}
		}
	}
	cout << *min_element(bestSkip[n].begin(), bestSkip[n].end()) << endl;
	return 0;
}