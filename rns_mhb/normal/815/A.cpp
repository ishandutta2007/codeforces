#include <bits/stdc++.h>
using namespace std;

#define N 110

int n, m, g[N][N], x, y, num, s[N], t[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) scanf("%d", &g[i][j]);
	g[0][0] = 500;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (g[x][y] >= g[i][j]) x = i, y = j;
	for (int i = 1; i <= n; i ++) s[i] = g[i][y] - g[x][y], num += s[i];
	for (int j = 1; j <= m; j ++) t[j] = g[x][j] - g[x][y], num += t[j];
	num += min(m, n) * g[x][y];
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) g[i][j] -= s[i];
	}
	for (int j = 1; j <= m; j ++) {
		for (int i = 1; i <= n; i ++) g[i][j] -= t[j];
	}
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (g[i][j] != g[x][y]) {
		puts("-1");
		return 0;
	}
	printf("%d\n", num);
	for (int i = 1; i <= n; i ++) for (int step = 1; step <= s[i]; step ++) printf("row %d\n", i);
	for (int j = 1; j <= m; j ++) for (int step = 1; step <= t[j]; step ++) printf("col %d\n", j);
	if (n < m) for (int i = 1; i <= n; i ++) for (int step = 1; step <= g[x][y]; step ++) printf("row %d\n", i);
	else for (int j = 1; j <= m; j ++) for (int step = 1; step <= g[x][y]; step ++) printf("col %d\n", j);
	return 0;
}