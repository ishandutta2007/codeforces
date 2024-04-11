#include <bits/stdc++.h>
using namespace std;
#define N 4040
#define M 1001001

int n, m, x, mp[M], a[N], nxt[N][N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		if (!mp[x]) mp[x] = ++m;
		a[i] = mp[x];
	}
	for (int i = 1; i <= m; i ++) nxt[n+1][i] = n + 1;
	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= m; j ++) nxt[i][j] = nxt[i+1][j];
		nxt[i][a[i]] = i;
	}
	int ans = 0;
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) {
			int rlt = 0, x = 1, y;
			for (int k = 1; k <= n + 1; k ++) {
				if (k & 1) y = nxt[x][i];
				else y = nxt[x][j];
				if (y == n + 1) {
					rlt = k - 1; break;
				}
				x = y + 1;
			}
			ans = max(ans, rlt);
		}
	}
	printf("%d\n", ans);
	return 0;
}