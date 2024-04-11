#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, m;
		scanf("%d %d", &n, &m);
		int grid[n][m];
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) scanf("%d", &grid[i][j]);
		}
		bool can = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) {
					if (grid[i][j] > 2) can = false;
					else grid[i][j] = 2;
				} else if ((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) {
					if (grid[i][j] > 3) can = false;
					else grid[i][j] = 3;
				} else {
					if (grid[i][j] > 4) can = false;
					else grid[i][j] = 4;
				}
			}
		}
		if (can) {
			printf("YES\n");
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					printf("%d", grid[i][j]);
					if (j != m - 1) printf(" ");
				}
				printf("\n");
			}
		} else printf("NO\n");
	}
	return 0;
}