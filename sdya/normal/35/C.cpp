#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 2100;
int d[maxN][maxN];
int n, m;

bool valid(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int dx[] = {-1, 0, 0, 1};
int dy[] = { 0,-1, 1, 0};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	queue < pair < int, int > > q;
	int k;
	scanf("%d", &k);
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= k; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		d[u][v] = 0;
		q.push(make_pair(u, v));
	}

	while (!q.empty()) {
		pair < int, int > p = q.front();
		q.pop();
		int x = p.first;
		int y = p.second;
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (valid(nx, ny) && d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}

	int res = 0;
	int x = 1, y = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (d[i][j] >= res) {
				res = d[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << x << " " << y << endl;

	return 0;
}