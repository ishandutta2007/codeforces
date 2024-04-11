#include <bits/stdc++.h>
using namespace std;
#define M 1111
#define INF 1e8

typedef pair <int, int> PII;
int n, m;
char s[M][M];
int dis[4][M][M];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

inline bool out(int x, int y) {return (x < 0 || y < 0 || x >= n || y >= m);}

void bfs(int ty) {
	vector <PII> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dis[ty][i][j] = INF;
			if (s[i][j] == (ty + '1')) v.push_back(PII(i, j)), dis[ty][i][j] = 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		PII p = v[i];
		for (int j = 0; j < 4; j++) {
			int x = p.first + dx[j], y = p.second + dy[j];
			if (out(x, y) || dis[ty][x][y] < INF || s[x][y] == '#') continue;
			dis[ty][x][y] = dis[ty][p.first][p.second] + 1, v.push_back(PII(x, y));
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < 3; i++) bfs(i);
	int ans = INF;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tp = 1;
			for (int k = 0; k < 3; k++) tp += max(dis[k][i][j] - 1, 0);
			ans = min(ans, tp);
		}
	}
	for (int i = 0; i < 3; i++) {
		int x = 1e9, y = 1e9;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (s[j][k] != (i + '1')) continue;
				x = min(x, dis[(i+1)%3][j][k]);
				y = min(y, dis[(i+2)%3][j][k]);
			}
		}
		ans = min(ans, x + y - 2);
	}
	if (ans >= INF / 10) puts("-1");
	else printf("%d\n", ans);
}