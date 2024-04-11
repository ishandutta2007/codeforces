#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 305;

int n, m, f[9][N][N], g[2][N][N];

void clr(int d[N][N]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i == j) d[i][j] = 0;
			else d[i][j] = -inf;
}

bool check(int x) {
	int cur = 0;
	clr(g[cur]);
	for (int s = 0; (1 << s) <= n; s++) {
		if (!(x >> s & 1 )) continue;
		cur ^= 1;
		clr(g[cur]);
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					g[cur][i][j] = max(g[cur][i][j], g[cur ^ 1][i][k] + f[s][k][j]);
	}
	for (int i = 1; i <= n; i++)
		if (g[cur][i][i] > 0) return true;
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int s = 0; (1 << s) <= n; s++)
		clr(f[s]);
	for (int i = 0; i < m; i++) {
		int u, v, a, b;
		scanf("%d%d%d%d", &u, &v, &a, &b);
		f[0][u][v] = a;
		f[0][v][u] = b;
	}
	for (int s = 1; (1 << s) <= n; s++)
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					f[s][i][j] = max(f[s][i][j], f[s - 1][i][k] + f[s - 1][k][j]);
	int l = 1, r = n + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l % (n + 1));
	return 0;
}