#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, q, a[N], gas[N], b[N], c[500][N], L, R;

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		if (a[i] <= n) gas[a[i]] ++;
	}
	for (int i = 1; i <= n; i ++) if (gas[i] >= i) b[++m] = i;
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			c[i][j] = c[i][j-1];
			if (a[j] == b[i]) c[i][j] ++;
		}
	}
	while (q --) {
		scanf("%d %d", &L, &R);
		int ans = 0;
		for (int i = 1; i <= m; i ++) {
			if (c[i][R] - c[i][L-1] == b[i]) ans ++;
		}
		printf("%d\n", ans);
	}
	return 0;
}