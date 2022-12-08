#include <bits/stdc++.h>

using namespace std;
const int N = 2005;
char mp[N][N];
bool cir[N][N];
int vis[N][N];
int ans[N][N];
int n, m;

int dfs(int p, int x, int y, bool &c) {
	if (x < 0 || x >= n || y < 0 || y >= m) {
		c = false;
		return 0;
	}
	if (vis[x][y]) {
		if (ans[x][y] == -1) {
			c = true;
			cir[x][y] = true;
			return p - vis[x][y];
		} else {
			c = false;
			return ans[x][y];
		}
	}
	vis[x][y] = p;
	int res;
	bool nc;
	if (mp[x][y] == 'U') res = dfs(p + 1, x - 1, y, nc);
	if (mp[x][y] == 'D') res = dfs(p + 1, x + 1, y, nc);
	if (mp[x][y] == 'L') res = dfs(p + 1, x, y - 1, nc);
	if (mp[x][y] == 'R') res = dfs(p + 1, x, y + 1, nc);
	if (cir[x][y]) c = false;
	else cir[x][y] = c = nc;
	if (!nc) ++res;
	return ans[x][y] = res;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ans[i][j] = -1;
			vis[i][j] = 0;
			cir[i][j] = false;
		}
	}
	for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
	int x, y, r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool c;
			int cur = dfs(1, i, j, c);
			if (cur > r) {
				x = i + 1;
				y = j + 1;
				r = cur;
			}
		}
	}
	printf("%d %d %d\n", x, y, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}