#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int n, m;
const int maxN = 1100;
int d[maxN][maxN][4];
char s[maxN][maxN];

inline bool val(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

#define mp(a, b, c) make_pair(a, make_pair(b, c))

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0, 1, 0,-1};

int solve() {
	deque < pair < int, pair < int, int > > > q;
	q.push_back(mp(0, 0, 1));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (int k = 0; k < 4; ++k)
				d[i][j][k] = 1000000000;
	d[0][0][1] = 0;
	while (!q.empty()) {
		pair < int, pair < int, int > > p = q.front(); q.pop_front();
		int x = p.first, y = p.second.first, dir = p.second.second;
		if (val(x + dx[dir], y + dy[dir]) && d[x + dx[dir]][y + dy[dir]][dir] > d[x][y][dir]) {
			d[x + dx[dir]][y + dy[dir]][dir] = d[x][y][dir];
			q.push_front(mp(x + dx[dir], y + dy[dir], dir));
		}

		if (s[x][y] == '#') {
			for (int i = 0; i < 4; ++i)
				if (d[x][y][i] > d[x][y][dir] + 1) {
					d[x][y][i] = d[x][y][dir] + 1;
					q.push_back(mp(x, y, i));
				}
		}
	}

	return d[n - 1][m - 1][1] == 1000000000 ? -1 : d[n - 1][m - 1][1];
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d\n", &n, &m);
	for (int i = 0; i < n; ++i)
		gets(s[i]);

	printf("%d\n", solve());

	return 0;
}