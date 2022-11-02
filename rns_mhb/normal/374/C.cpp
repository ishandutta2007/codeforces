#include <iostream>
using namespace std;

#define N 1010
#define inf 1e9

int n, m, vis[N][N], dp[N][N], ans;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char grid[N][N], str[] = "DIMA";

int dfs(int x, int y, int k) {
	if (!(x >= 0 && x < n && y >= 0 && y < m) || grid[x][y] != str[k]) return 0;
	if (vis[x][y] == 2) return dp[x][y];
	if (vis[x][y] == 1) return inf;
	vis[x][y] = 1;
	int &ret = dp[x][y];
	for (int i = 0; i < 4; i ++) ret = max(ret, dfs(x + dx[i], y + dy[i], (k + 1) % 4));
	vis[x][y] = 2;
	return ++ ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%s", grid[i]);
	for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) if (!vis[i][j]) ans = max(ans, dfs(i, j, 0));
	if (ans >= inf) puts("Poor Inna!");
	else if (ans / 4 == 0) puts("Poor Dima!");
	else printf("%d", ans / 4);
}