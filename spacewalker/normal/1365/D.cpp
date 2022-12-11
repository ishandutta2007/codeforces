#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 55;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
char grid[NMAX][NMAX];
bool reachable[NMAX][NMAX];

bool inRange(int x, int y) {
	return (0 <= x && 0 <= y && x < n && y < m);
}

bool solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] != 'B') continue;
			for (int mt = 0; mt < 4; ++mt) {
				int nx = i + dx[mt], ny = j + dy[mt];
				if (inRange(nx, ny) && grid[nx][ny] == '.') grid[nx][ny] = '#';
			}
		}
	}
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) printf("%c", grid[i][j]);
//		printf("\n");
//	}
	queue<pair<int, int>> q;
	q.emplace(n - 1, m - 1);
	memset(reachable, 0, sizeof reachable);
	while (!q.empty()) {
		int cx, cy; tie(cx, cy) = q.front(); q.pop();
		if (grid[cx][cy] == '#' || reachable[cx][cy]) continue;
		reachable[cx][cy] = true;
		for (int mt = 0; mt < 4; ++mt) {
			int nx = cx + dx[mt], ny = cy + dy[mt];
			if (inRange(nx, ny) && !reachable[nx][ny]) q.emplace(nx, ny);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == 'G' && !reachable[i][j]) return false;
			if (grid[i][j] == 'B' && reachable[i][j]) return false;
		}
	}
	return true;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) printf("%s\n", solve() ? "Yes" : "No");
	return 0;
}