#include <cstdio>

using namespace std;

const int N = 510;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
char mp[N][N];
int vis[N][N], tot, sz, mxsz, X, Y, n, m, k, s, id;

void dfs(int i, int j) {
	vis[i][j] = tot;
	sz ++;
	for (int k = 0; k < 4; k ++) {
		int x = i + dx[k], y = j + dy[k];
		if (x < 1 || y < 1 || x > n || y > m || vis[x][y] || mp[x][y] == '#') continue;
		dfs(x, y);
	}
}

void dfs2(int i, int j) {
	mp[i][j] = '.';
	if (!--s) return;
	for (int k = 0; k < 4; k ++) {
		int x = i + dx[k], y = j + dy[k];
		if (x < 1 || y < 1 || x > n || y > m || vis[x][y] != id || mp[x][y] == '#' || mp[x][y] == '.') continue;
		if (s) dfs2(x, y);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i ++) scanf("%s", mp[i] + 1);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) if (mp[i][j] == '.') s ++, mp[i][j] = 'X';
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) if (vis[i][j] == 0 && mp[i][j] == 'X') {
			sz = 0, tot ++;
			dfs(i, j);
			if (sz > mxsz) mxsz = sz, id = tot, X = i, Y = j;
		}
	}
	s -= k;
	dfs2(X, Y);
	for (int i = 1; i <= n; i ++) printf("%s\n", mp[i] + 1);
	return 0;
}