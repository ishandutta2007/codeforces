#include <stdio.h>
#define N 1002

bool vis[N][N];

int main() {
	int n, m;
	int i, j, k;
	scanf ("%d %d", &n, &m);
	while (m--) {
		scanf ("%d %d", &i, &j);
		vis[i][j] = 1;
		vis[j][i] = 1;
	}

	for (i = 1; i <= n; i ++) {
		for (j = 1; j <= n; j ++) {
			if (vis[i][j]) break;
		}
		if (j > n) break;
	}

	printf ("%d\n", n - 1);
	for (j = 1; j <= n; j ++) {
		if (j == i) continue;
		printf ("%d %d\n", i, j);
	}
	return 0;
}