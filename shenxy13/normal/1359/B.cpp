#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m, x, y, ans = 0;
		scanf("%d %d %d %d", &n, &m, &x, &y);
		char grid[n][m];
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) scanf(" %c", &grid[j][k]);
		}
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (k != m - 1 && grid[j][k] == '.' && grid[j][k + 1] == '.') ans += min(2 * x, y), ++k;
				else if (grid[j][k] == '.') ans += x;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}