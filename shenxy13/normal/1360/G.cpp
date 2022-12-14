#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, m, a, b;
		scanf("%d %d %d %d", &n, &m, &a, &b);
		if (n * a == m * b) {
			printf("YES\n");
			char grid[n][m];
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) grid[i][j] = '0';
			}
			int idx = 0;
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < a; ++j) grid[i][(idx / b + j) % m] = '1';
				idx += a;
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) printf("%c", grid[i][j]);
				printf("\n");
			}
		} else printf("NO\n");
	}
	return 0;
}