#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<vector<int>> grid(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &grid[i][j]);
		}
	}

	vector<set<int>> inRow(n, set<int>());

	for (int i = 0; i < n; ++i) {
		for (int iri : grid[i]) {
			inRow[i].insert(iri);
		}
	}

	bool violatorExists = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			bool canBeRepped = false;
			if (grid[i][j] == 1) {
				continue;
			}
			for (int inSameCol = 0; inSameCol < n; ++inSameCol) {
				if (inRow[i].count(grid[i][j] - grid[inSameCol][j]) > 0) {
					canBeRepped = true;
				}
			}
			if (!canBeRepped) {
				violatorExists = true;
			}
		}
	}

	printf("%s", (violatorExists ? "NO" : "YES"));
	return 0;
}