#include <bits/stdc++.h>
using namespace std;

int ri[510][510], dw[510][510], f[510][510], g[510][510];

void chmin(int &x, int y) {
	x = min(x, y);
}

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			scanf("%d", &ri[i][j]);
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &dw[i][j]);
		}
	}
	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("-1 ");
			}
			printf("\n");
		}
		return 0;
	}
	memset(g, 0, sizeof(g));
	for (int it = 0; it < k / 2; it++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				f[i][j] = 0x3f3f3f3f;
				if (i) chmin(f[i][j], g[i - 1][j] + dw[i - 1][j]);
				if (j) chmin(f[i][j], g[i][j - 1] + ri[i][j - 1]);
				if (i + 1 < n) chmin(f[i][j], g[i + 1][j] + dw[i][j]);
				if (j + 1 < m) chmin(f[i][j], g[i][j + 1] + ri[i][j]);
			}
		}
		memcpy(g, f, sizeof(f));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", g[i][j] * 2);
		}
		printf("\n");
	}
	return 0;
}