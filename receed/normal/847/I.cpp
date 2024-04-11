
#include <bits/stdc++.h>

using namespace std;

char a[250][251];
int now[250][250];
long long lev[250][250];
int t[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() {
#ifdef FLOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int Q, p, n, m, x, y, x1, y1;
	scanf("%d%d%d%d", &n, &m, &Q, &p);
	for (int i = 0; i < n; i++)
		scanf("%s", &a[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.' || a[i][j] == '*')
				continue;
			queue<pair<int, int>> q;
			q.push({i, j});
			now[i][j] = Q * (a[i][j] - 'A' + 1);
			while (!q.empty()) {
				x = q.front().first;
				y = q.front().second;
				q.pop();
				lev[x][y] += now[x][y];
				for (int k = 0; k < 4; k++) {
					x1 = x + t[k][0];
					y1 = y + t[k][1];
					if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m || a[x1][y1] == '*' || now[x1][y1] > 0)
						continue;
					now[x1][y1] = now[x][y] / 2;
					if (now[x1][y1]) {
						q.push({x1, y1});
					}
				}
			}
			int lx = max(i - 27, 0), rx = min(i + 27, n), ly = max(0, j - 27), ry = min(m, j + 27);
			for (int x0 = lx; x0 < rx; x0++)
				for (int y0 = ly; y0 < ry; y0++)
					now[x0][y0] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (lev[i][j] > p)
				ans++;
	printf("%d\n", ans);
}