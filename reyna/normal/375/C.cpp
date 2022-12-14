//In the name of God
// Break through! I screamed forth from my soul!

#include <bits/stdc++.h>

using namespace std;

const int N = 20;
const int maxbit = 8;

int dis[N][N][1 << maxbit][4][4], mark[N][N][1 << maxbit][4][4], t, h, sz, bomb[maxbit], val[maxbit];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
pair<int, int> p[maxbit];
pair<pair<int, int>, pair<pair<int, int>, int>>  q[N * N * (1 << maxbit) * 4 * 4];
string s[N];

int get_mask(int x, int y, int ndir, int cdir) {
	if (!(ndir & 1) || !(cdir & 1) || ndir != cdir)
		return 0;
	int mask = 0;
	for (int k = 0; k < sz; k++) {
		int i = p[k].first, j = p[k].second;
		if (i == x && j < y)
			mask |= 1 << k;
	}
	return mask;
}

int main() {
	memset(dis, 63, sizeof (dis));
	int n, m, sx, sy, cnt = 0; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'S') {
				for (int k = 2; k < 3; k++)
					dis[i][j][0][k][0] = 0, mark[i][j][0][k][0] = 1, q[t++] = {{i, j}, {{0, k}, 0}};
				sx = i, sy = j;
			}
			if (s[i][j] != 'S' && s[i][j] != '.' && s[i][j] != '#') {
				p[sz++] = {i, j};
				if (s[i][j] != 'B')
					cnt++;
			}
		}
	}
	
	while (h != t) {
		auto cur = q[h++];
		int i = cur.first.first, j = cur.first.second, cmask = cur.second.first.first, cdir = cur.second.first.second, ss = cur.second.second;
		for (int k = 0; k < 4; k++) {
			int x = i + dx[k], y = j + dy[k], ndir = k, ns = ss;
			if (cdir == 2 && (k & 1))
				ns = k;
			if (x < 0 || y < 0 || x == n || y == m || (s[x][y] != '.' && s[x][y] != 'S'))
				continue;
			int nmask = cmask ^ get_mask(i, j, ndir, cdir);
			ndir = (ndir & 1)? ndir: cdir;
			if (mark[x][y][nmask][ndir][ns]++) 
				continue;
//			if (x == 3 && y == 8 && nmask == 0 && ndir == 1 && ns == 0) {
//				cout << i << ' ' << j << ' ' << cmask << ' ' << cdir << ' ' << ss << endl;
//			}
			dis[x][y][nmask][ndir][ns] = dis[i][j][cmask][cdir][ss] + 1;
			q[t++] = {{x, y}, {{nmask, ndir}, ns}};
		}
	}
	int ans = 0;
	for (int i = 0; i < cnt; i++)
		cin >> val[i];
	for (int fdir = 0; fdir < 4; fdir++)
		for (int dir = 0; dir < 4; dir++)
			for (int ms = 0; ms < (1 << sz); ms++) {
				int mask = ms;
				if (fdir == 1 && dir == 1 || fdir == 3 && dir == 3)
					mask ^= get_mask(sx, sy, 1, 1);
				bool flag = 0;
				for (int i = 0; i < sz; i++) if (ms >> i & 1)
					if (s[p[i].first][p[i].second] == 'B')	
						flag = 1;
				if (flag) continue;
				int sum = 0;
				for (int i = 0; i < sz; i++) if (ms >> i & 1)
					sum += val[s[p[i].first][p[i].second] - '1'];
				ans = max(ans, sum - dis[sx][sy][mask][dir][fdir]);
//				if (sum - dis[sx][sy][mask][dir][fdir] == 52) {
//					cout << ms << ' ' << mask << ' ' << sum << ' ' << dis[sx][sy][mask][dir][fdir] << ' ' << dir << ' ' << fdir << endl;
//				}
			}
	cout << ans << endl;
}