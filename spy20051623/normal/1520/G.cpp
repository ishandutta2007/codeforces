#include <bits/stdc++.h>

using namespace std;

long long mp[2005][2005];
long long vis1[2005][2005];
long long vis2[2005][2005];
int n, m;
long long w;

const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};
const long long inf = 0x3f3f3f3f3f3f3f3f;

long long min1 = 0x3f3f3f3f3f3f3f3f;
long long min2 = 0x3f3f3f3f3f3f3f3f;

void bfs1(int sx, int sy) {
	queue<pair<int, int>> q;
	pair<int, int> p;
	vis1[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (mp[p.first][p.second] > 0) {
			min1 = min(min1, mp[p.first][p.second] + w * vis1[p.first][p.second]);
		}
		for (auto i : dir) {
			int x = p.first + i[0];
			int y = p.second + i[1];
			if (x > 0 && x <= n && y > 0 && y <= m && mp[x][y] >= 0 && vis1[x][y] == inf) {
				q.push(make_pair(x, y));
				vis1[x][y] = vis1[p.first][p.second] + 1;
			}
		}
	}
}

void bfs2(int sx, int sy) {
	queue<pair<int, int>> q;
	pair<int, int> p;
	vis2[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (mp[p.first][p.second] > 0) {
			min2 = min(min2, mp[p.first][p.second] + w * vis2[p.first][p.second]);
		}
		for (auto i : dir) {
			int x = p.first + i[0];
			int y = p.second + i[1];
			if (x > 0 && x <= n && y > 0 && y <= m && mp[x][y] >= 0 && vis2[x][y] == inf) {
				q.push(make_pair(x, y));
				vis2[x][y] = vis2[p.first][p.second] + 1;
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	scanf("%d%d%lld", &n, &m, &w);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%lld", &mp[i][j]);
		}
	}
	memset(vis1, 63, sizeof vis1);
	memset(vis2, 63, sizeof vis2);
	bfs1(1, 1);
	bfs2(n, m);
	long long k;
	if (vis1[n][m] != inf) {
		if (min1 != inf && min2 != inf)
			k = min(min1 + min2, w * vis1[n][m]);
		else
			k = w * vis1[n][m];
	} else {
		if (min1 != inf && min2 != inf)
			k = min1 + min2;
		else
			k = -1;
	}
	printf("%lld\n", k);
	return 0;
}