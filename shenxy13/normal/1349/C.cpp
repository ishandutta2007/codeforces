#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const long long INF = 2000000000000000000LL;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int main() {
	int n, m, t, x, y;
	long long p;
	scanf("%d %d %d", &n, &m, &t);
	char grid[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) scanf(" %c", &grid[i][j]);
	}
	int queue[n * m], fptr = 0, eptr = 0;
	long long visited[n][m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) visited[i][j] = INF;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m && grid[i][j] == grid[i + dx[k]][j + dy[k]]) {
					visited[i][j] = 0;
					queue[eptr++] = i * m + j;
					break;
				}
			}
		}
	}
	while (fptr != eptr) {
		x = queue[fptr] / m, y = queue[fptr] % m;
		++fptr;
		for (int i = 0; i < 4; ++i) {
			if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < m && visited[x + dx[i]][y + dy[i]] == INF) {
				visited[x + dx[i]][y + dy[i]] = visited[x][y] + 1;
				queue[eptr++] = (x + dx[i]) * m + y + dy[i];
			}
		}
	}
	for (int i = 0; i < t; ++i) {
		scanf("%d %d %lld", &x, &y, &p);
		--x, --y;
		if (p < visited[x][y]) printf("%c\n", grid[x][y]);
		else if (p % 2 == visited[x][y] % 2) printf("%c\n", grid[x][y]);
		else printf(grid[x][y] == '1' ? "0\n" : "1\n");
	}
	return 0;
}