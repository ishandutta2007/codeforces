#include <bits/stdc++.h>
using namespace std;
#define N 21

int n, m, d, q, x, col[1<<N], vis[N], bit[1<<N];
bool f[1<<N];

int main() {
//	freopen("a4.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; i ++) {
		scanf("%d", &q);
		while (q --) {
			scanf("%d", &x);
			col[x] = i;
		}
	}
	for (int i = 1; i <= d; i ++) vis[col[i]] ++;
	int x = 0;
	for (int j = 0; j < m; j ++) if (vis[j]) x ^= 1 << j;
	f[x] = 1;
	for (int i = 2; i <= n - d + 1; i ++) {
		vis[col[i-1]] --;
		vis[col[i+d-1]] ++;
		int x = 0;
		for (int j = 0; j < m; j ++) if (vis[j]) x ^= 1 << j;
		f[x] = 1;
	}
	int ans = 0;
	int M = 1 << m;
	for (int i = 1; i < M; i ++) {
		for (int j = 0; j < m; j ++) if (i & (1 << j)) {
			f[i] |= f[i^(1<<j)];
		}
		bit[i] = bit[i^(i&-i)] + 1;
		if (!f[i]) ans = max(ans, bit[i]);
	}
	printf("%d\n", m - ans);
	return 0;
}