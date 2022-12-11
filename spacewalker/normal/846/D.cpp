#include <bits/stdc++.h>

using namespace std;

int rowRange[510][510], colRange[510][510], sqRange[510][510];

int main() {
	int n, m, k, q; scanf("%d %d %d %d", &n, &m, &k, &q);
	vector<vector<int>> grid(n, vector<int>(m, 1000000001));
	for (int b = 0; b < q; ++b) {
		int x, y, t; scanf("%d %d %d", &x, &y, &t);
		grid[--x][--y] = t;
	}
	int lo = 0;
	int hi = 1000000005;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		memset(rowRange, 0, sizeof rowRange);
		memset(colRange, 0, sizeof colRange);
		memset(sqRange, 0x3f, sizeof sqRange);
		for (int i = 0; i < n; ++i) {
			for (int j = m - 1; j >= 0; --j) {
				rowRange[i][j] = (grid[i][j] <= mid ? rowRange[i][j+1] + 1 : 0);
			}
		}
		for (int j = 0; j < m; ++j) {
			for (int i = n - 1; i >= 0; --i) {
				colRange[i][j] = (grid[i][j] <= mid ? colRange[i+1][j] + 1 : 0);
			}
		}
		for (int i = n - 1; i >= 0; --i) {
			for (int j = m - 1; j >= 0; --j) {
				sqRange[i][j] = min(rowRange[i][j], colRange[i][j]);
				if (i < n - 1 && j < n - 1) sqRange[i][j] = min(sqRange[i][j], sqRange[i+1][j+1] + 1);
			}
		}
		int fans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				fans = max(fans, sqRange[i][j]);
			}
		}
		if (fans >= k) hi = mid;
		else lo = mid + 1;
	}
	if (lo == 1000000001) printf("-1\n");
	else printf("%d\n", lo);	
	return 0;
}