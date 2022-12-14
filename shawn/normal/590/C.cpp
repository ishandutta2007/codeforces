#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

#define X first
#define Y second
#define mk make_pair
const int inf = 10000000;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
int dis[3][1010][1010], n, m, ans;
char mp[1010][1010];

void bfs(int d[1010][1010], int op) {
	queue <pii> q;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (mp[i][j] == op) q.push(mk(i, j)), d[i][j] = 0;//, printf("%c %d %d\n", op, i, j);
			else d[i][j] = inf;
		}
	}
	while (!q.empty()) {
		pii u = q.front(), v; q.pop();
	//	printf("%d %d\n", u.X, u.Y);
		for (int i = 0; i < 4; i ++) {
			v.X = u.X + dx[i], v.Y = u.Y + dy[i];
			if (v.X < 1 || v.Y < 1 || v.X > n || v.Y > m || mp[v.X][v.Y] == '#') continue;
		//	puts("FUCK");
			if (mp[v.X][v.Y] == '.') {
				if (d[v.X][v.Y] > d[u.X][u.Y] + 1) d[v.X][v.Y] = d[u.X][u.Y] + 1, q.push(v);
			}
			else {
				if (d[v.X][v.Y] > d[u.X][u.Y]) d[v.X][v.Y] = d[u.X][u.Y], q.push(v);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%s", mp[i] + 1);
	for (int i = 0; i < 3; i ++) bfs(dis[i], 49 + i);
	int b = inf, c = inf;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (mp[i][j] == '2') b = min(b, dis[0][i][j]);
			else if (mp[i][j] == '3') c = min(c, dis[0][i][j]);
		}
	}
	if (!b && !c) ans = 0;
	else {
		ans = inf;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) if (mp[i][j] == '.')
				ans = min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - 2);//, printf("%d %d %d %d %d\n", i, j, dis[0][i][j], dis[1][i][j], dis[2][i][j]);
				//printf("%d %d %d\n", i, j, ans);
		}
	}
	printf("%d\n", ans == inf ? -1 : ans);
	return 0;
}