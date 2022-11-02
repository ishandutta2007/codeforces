#include <bits/stdc++.h>
using namespace std;
#define N 1010

int n, m, q, f[N][N], T, vis[N][N], ans;
char s[N][N];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

void dfs(int x, int y) {
	vis[x][y] = T;
	for (int i = 0; i < 4; i ++) {
		int X = x + dx[i], Y = y + dy[i];
		if (X < 1 || X > n || Y < 1 || Y > m) continue;
		if (s[X][Y] == '*') ans ++;
		else if (vis[X][Y] != T) dfs(X, Y);
	}
}

void DFS(int x, int y) {
	vis[x][y] = T;
	f[x][y] = ans;
	for (int i = 0; i < 4; i ++) {
		int X = x + dx[i], Y = y + dy[i];
		if (X < 1 || X > n || Y < 1 || Y > m) continue;
		if (s[X][Y] == '.' && vis[X][Y] != T) DFS(X, Y);
	}
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	memset(f, -1, sizeof f);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) if (s[i][j] == '.') {
			if (f[i][j] != -1) continue;
			T ++;
			ans = 0;
			dfs(i, j);
			T ++;
			DFS(i, j);
		}
	}
	while (q --) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", f[x][y]);
	}
	return 0;
}