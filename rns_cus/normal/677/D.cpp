#include <bits/stdc++.h>
using namespace std;
#define N 303
#define inf 1e9

pair <int, int> p;
vector < pair <int, int> > v[N*N];
queue < pair <int, int> > q;
int n, m, pp, a[N][N], f[N][N], d[N][N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &pp);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			int x;
			scanf("%d", &x);
			a[i][j] = x;
			v[x].push_back(make_pair(i, j));
		}
	}
	v[0].push_back(make_pair(1, 1));
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) f[i][j] = inf;
	f[1][1] = 0;
	for (int k = 1; k <= pp; k ++) {
		if (v[k-1].size() <= 300) {
			for (int s = 0; s < v[k].size(); s ++) {
				int x = v[k][s].first, y = v[k][s].second;
				for (int t = 0; t < v[k-1].size(); t ++) {
					int X = v[k-1][t].first, Y = v[k-1][t].second;
					f[x][y] = min(f[x][y], f[X][Y] + abs(x - X) + abs(y - Y));
				}
			}
		}
		else {
			while (!q.empty()) q.pop();
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					if (a[i][j] == k - 1) d[i][j] = f[i][j], q.push(make_pair(i, j));
					else d[i][j] = inf;
				}
			}
			while (!q.empty()) {
				p = q.front(); q.pop();
				int x = p.first, y = p.second;
				for (int i = 0; i < 4; i ++) {
					int X = x + dx[i], Y = y + dy[i];
					if (X < 0 || X > n || Y < 0 || Y > m) continue;
					if (d[X][Y] > d[x][y] + 1) d[X][Y] = d[x][y] + 1, q.push(make_pair(X, Y));
				}
			}
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) if (a[i][j] == k) f[i][j] = d[i][j];
			}
		}
        if (a[1][1] == k + 1) f[1][1] = inf;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i][j] == pp) {
				printf("%d\n", f[i][j]); return 0;
			}
		}
	}
	return 0;
}