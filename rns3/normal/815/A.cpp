#include <bits/stdc++.h>
using namespace std;
#define N 105

int n, m, g[N][N], sum, a[N], b[N], ans;

int main() {
	int i, j, k, mx = 1e9, mn = 0;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i ++) for(j = 1; j <= m; j ++) scanf("%d", &g[i][j]);
	for(i = 2; i <= n; i ++) {
		for(j = 1; j <= m; j ++) {
			if(g[i][1] - g[1][1] + g[1][j] == g[i][j]) continue;
			else break;
		}
		if(j <= m) break;
	}
	if(i <= n) {
		puts("-1");
		return 0;
	}
	for(i = 1; i <= m; i ++) mx = min(mx, g[1][i]);
	for(i = 2; i <= n; i ++) if(g[i][1] - g[1][1] < 0) mn = max(mn, g[1][1] - g[i][1]);
	if(m >= n) a[1] = mx;
	else a[1] = mn;
	for(i = 1; i <= m; i ++) b[i] = g[1][i] - a[1];
	for(i = 2; i <= n; i ++) a[i] = g[i][1] - g[1][1] + a[1];
	for(i = 1; i <= m; i ++) ans += b[i];
	for(i = 1; i <= n; i ++) ans += a[i];
	printf("%d\n", ans);
	for(i = 1; i <= n; i ++) for(j = 0; j < a[i]; j ++) printf("row %d\n", i);
	for(i = 1; i <= m; i ++) for(j = 0; j < b[i]; j ++) printf("col %d\n", i);
}