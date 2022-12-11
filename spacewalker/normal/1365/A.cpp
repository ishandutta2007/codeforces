#include <bits/stdc++.h>

using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		vector<vector<int>> grid(n, vector<int>(m));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &grid[i][j]);
			}
		}
		int freeRowCount = 0, freeColCount = 0;
		vector<bool> rowFree(n, true), colFree(m, true);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1) {
					rowFree[i] = false;
					colFree[j] = false;
				}
			}
		}
		for (bool b : rowFree) if (b) ++freeRowCount;
		for (bool b : colFree) if (b) ++freeColCount;
		printf("%s\n", min(freeRowCount, freeColCount) % 2 == 0 ? "Vivek" : "Ashish");
	}
	return 0;
}