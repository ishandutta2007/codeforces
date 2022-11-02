///	E : Coded by Choe Kwang

#include <bits/stdc++.h>
using namespace std;
#define N 55
#define inf 1e9

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int n, m, d[N][N];
pair <int, int> p;
queue < pair <int, int> > q;
char s[N][N];

int calc(int x, int y) {
	while (!q.empty()) q.pop();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) d[i][j] = inf;
	}
	d[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		p = q.front(); q.pop();
		int x = p.first, y = p.second;
		for (int i = 0; i < 4; i ++) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			int dist = d[x][y] + (s[x][y] != s[xx][yy]);
			if (dist < d[xx][yy]) {
				d[xx][yy] = dist;
				q.push(make_pair(xx, yy));
			}
		}
	}
	int rlt = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) if (s[i][j] == 'B') rlt = max(rlt, d[i][j]);
	}
	return rlt;
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++) scanf("%s", s[i]);
	int ans = inf;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) ans = min(ans, calc(i, j));
	}
	printf("%d\n", ans);
	return 0;
}