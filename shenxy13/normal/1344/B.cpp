#include <cstdio>
#include <algorithm>
#include <queue>
#define F first
#define S second
using namespace std;
typedef pair<int, int> ii;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main() {
	int n, m, ans = 0;
	scanf("%d %d", &n, &m);
	char grid[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) scanf(" %c", &grid[i][j]);
	}
	bool rowblank = false, colblank = false;
	for (int i = 0; i < n; ++i) {
		int tier = 0;
		for (int j = 0; j < m; ++j) {
			if (grid[i][j] == '#') {
				if (tier == 0) tier = 1;
				else if (tier == 2) {
					printf("-1");
					return 0;
				}
			} else if (tier == 1) tier = 2;
		}
		if (tier == 0) rowblank = true;
	}
	for (int i = 0; i < m; ++i) {
		int tier = 0;
		for (int j = 0; j < n; ++j) {
			if (grid[j][i] == '#') {
				if (tier == 0) tier = 1;
				else if (tier == 2) {
					printf("-1");
					return 0;
				}
			} else if (tier == 1) tier = 2;
		}
		if (tier == 0) colblank = true;
	}
	if (rowblank != colblank) {
		printf("-1");
		return 0;
	}
	bool visited[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) visited[i][j] = false;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!visited[i][j] && grid[i][j] == '#') {
				++ans;
				visited[i][j] = true;
				queue<ii> bfs;
				bfs.push(ii(i, j));
				while (!bfs.empty()) {
					ii a = bfs.front();
					bfs.pop();
					for (int i = 0; i < 4; ++i) {
						if (a.F + dx[i] >= 0 && a.F + dx[i] < n && a.S + dy[i] >= 0 && a.S + dy[i] < m && !visited[a.F + dx[i]][a.S + dy[i]] && grid[a.F + dx[i]][a.S + dy[i]] == '#') {
							visited[a.F + dx[i]][a.S + dy[i]] = true;
							bfs.push(ii(a.F + dx[i], a.S + dy[i]));
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}