#include <bits/stdc++.h>
using namespace std;

const int N = 1005, INF = 0x3f3f3f3f;
const int D[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char d[N];
bool vis[3 * N][3 * N], fil[3 * N][3 * N];
int n, t[N], kx[3 * N], sx, ky[3 * N], sy;

void add(int x, int y) {
	kx[++sx] = x - 1, kx[++sx] = x, kx[++sx] = x + 1;
	ky[++sy] = y - 1, ky[++sy] = y, ky[++sy] = y + 1;
}

void dfs(int x, int y) {
	fil[x][y] = true;
	for (int k = 0; k < 4; k++) {
		int i = x + D[k][0], j = y + D[k][1];
		if (i >= 1 && i <= sx && j >= 1 && j <= sy && !fil[i][j] && !vis[i][j]) dfs(i, j);
	}
}

int main() {
	scanf("%d", &n);
	int x = 0, y = 0;
	add(x, y);
	for (int i = 1; i <= n; i++) {
		scanf(" %c%d", d + i, t + i);
		if (d[i] == 'L') x -= t[i];
		if (d[i] == 'R') x += t[i];
		if (d[i] == 'D') y -= t[i];
		if (d[i] == 'U') y += t[i];
		add(x, y);
	}
	kx[++sx] = -INF, kx[++sx] = INF;
	ky[++sy] = -INF, ky[++sy] = INF;
	sort(kx + 1, kx + 1 + sx); sx = unique(kx + 1, kx + 1 + sx) - kx - 1;
	sort(ky + 1, ky + 1 + sy); sy = unique(ky + 1, ky + 1 + sy) - ky - 1;
	x = lower_bound(kx + 1, kx + 1 + sx, 0) - kx;
	y = lower_bound(ky + 1, ky + 1 + sy, 0) - ky;
	vis[x][y] = true;
	for (int i = 1; i <= n; i++) {
		while (d[i] == 'L' && t[i]) t[i] -= kx[x] - kx[x - 1], x--, vis[x][y] = true;
		while (d[i] == 'R' && t[i]) t[i] -= kx[x + 2] - kx[x + 1], x++, vis[x][y] = true;
		while (d[i] == 'D' && t[i]) t[i] -= ky[y] - ky[y - 1], y--, vis[x][y] = true;
		while (d[i] == 'U' && t[i]) t[i] -= ky[y + 2] - ky[y + 1], y++, vis[x][y] = true;
	}
	dfs(1, 1);
	long long ans = 0;
	for (int i = 1; i < sx; i++)
		for (int j = 1; j < sy; j++)
			if (!fil[i][j]) ans += 1ll * (kx[i + 1] - kx[i]) * (ky[j + 1] - ky[j]);
	cout << ans << endl;
	return 0;
}