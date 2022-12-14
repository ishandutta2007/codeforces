//In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 49;

char s[N][N];
int n, m, d[N][N][3], bg[3], ed[3], dis[3][3];
pair<int, int> que[N * N][3];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
void bfs(int ind) {
	while (bg[ind] != ed[ind]) {
		pair<int, int> cur = que[bg[ind]++][ind];
		int i = cur.first, j = cur.second;
		for (int k = 0; k < 4; k++) {
			int x = i + dx[k], y = j + dy[k];
			if (x < 0 || y < 0 || x == n || y == m || s[x][y] == '#')
				continue;
			if (d[x][y][ind] > N * N) {
				d[x][y][ind] = d[i][j][ind] + 1;
				que[ed[ind]++][ind] = {x, y};
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	memset(d, 31, sizeof d);
	memset(dis, 31, sizeof dis);
	for (int i = 0; i < n; i++) {
		scanf("%s", &s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] != '.' && s[i][j] != '#') {
				que[ed[s[i][j] - '1']++][s[i][j] - '1'] = {i, j};
				d[i][j][s[i][j] - '1'] = 0;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		bfs(i);
	for (int st = 0; st < 3; st++) {
		for (int en = 0; en < 3; en++) {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (s[i][j] != '#' && s[i][j] != '.' && s[i][j] - '1' == en)
						dis[st][en] = min(dis[st][en], d[i][j][st]);	
		}
	}
	int res = N * N;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) if (s[i][j] != '#')
			res = min(res, d[i][j][0] + d[i][j][1] + d[i][j][2] - 2);
	res = min(res, dis[0][1] + dis[1][2] - 2);
	res = min(res, dis[0][2] + dis[2][1] - 2);
	res = min(res, dis[1][0] + dis[0][2] - 2);
	cout << ((res == N * N)? -1: res) << endl;
	return 0;
}