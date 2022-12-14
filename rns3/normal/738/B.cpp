#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, m, u, a[4][N], x[N], y[N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) a[0][i] = a[1][i] = m;
	for (int j = 1; j <= m; j ++) a[2][j] = a[3][j] = n;
	for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
			scanf("%d", &u);
			if (u) {
				a[0][i] = min(a[0][i], j - 1);
				a[1][i] = min(a[1][i], m - j);
				a[2][j] = min(a[2][j], i - 1);
				a[3][j] = min(a[3][j], n - i);
				x[i] ++;
				y[j] ++;
			}
        }
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (x[i]) ans += 2 * m - 2 * x[i] - a[0][i] - a[1][i];
	}
	for (int j = 1; j <= m; j ++) {
		if (y[j]) ans += 2 * n - 2 * y[j] - a[2][j] - a[3][j];
	}
	printf("%d\n", ans);
	return 0;
}