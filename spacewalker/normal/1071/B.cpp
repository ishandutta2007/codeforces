#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

char grid[2010][2010];
int leastAs[2010][2010];
bool inRound[2010][2010];

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		// for (int j = 0; j < n; ++j) {
			scanf("%s", grid[i]);
		// }
	}
	// printf("here\n");
	int bpCount = 0;
	for (int i = 0; i < 2010; ++i) {
		for (int j = 0; j < 2010; ++j) {
			leastAs[i][j] = 1000000000;
		}
	}
	leastAs[1][0] = leastAs[0][1] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			leastAs[i+1][j+1] = (grid[i][j] == 'a' ? 0 : 1) + min(leastAs[i][j+1], leastAs[i+1][j]);
			if (leastAs[i+1][j+1] <= k) bpCount = max(bpCount, i+j+1);
			// printf("%d ", leastAs[i+1][j+1]);
		}
		// printf("\n");
	}
	vector<pair<int, int>> cRound;
	vector<pair<int, int>> nextRound;
	vector<char> ans(bpCount, 'a');
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (leastAs[i+1][j+1] <= k && i+j+1 == bpCount) {
				// printf("STARTOFF %d %d\n", i, j);
				inRound[i][j] = true;
				cRound.emplace_back(i, j);
			}
		}
	}
	if (bpCount == 0) {
		ans.push_back(grid[0][0]);
		cRound.emplace_back(0, 0);
	}
	// printf("here\n");
	while (ans.size() < 2*n-1) {
		char bestNext = 'z';
		for (auto cd : cRound) {
			if (cd.first < n-1) bestNext = min(bestNext, grid[cd.first+1][cd.second]);
			if (cd.second < n-1) bestNext = min(bestNext, grid[cd.first][cd.second+1]);
		}
		ans.push_back(bestNext);
		nextRound.clear();
		for (auto cd : cRound) {
			int x = cd.first, y = cd.second;
			if (x < n-1 && grid[x+1][y] == bestNext && !inRound[x+1][y]) {
				inRound[x+1][y] = true;
				nextRound.emplace_back(x+1, y);
			}
			if (y < n-1 && grid[x][y+1] == bestNext && !inRound[x][y+1]) {
				inRound[x][y+1] = true;
				nextRound.emplace_back(x, y+1);
			}
		}
		cRound = nextRound;
	}
	for (char c : ans) printf("%c", c);
	printf("\n");
	return 0;
}