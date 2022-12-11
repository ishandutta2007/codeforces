#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 510;

char grid[NMAX][NMAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int main() {
	int h, w; scanf("%d %d", &h, &w);
	for (int i = 0; i < h; ++i) scanf("%s", grid[i]);
	int cx = -1, cy = -1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == '.') continue;
			bool allStar = true;
			for (int mt = 0; mt < 4; ++mt) {
				int ni = i + dx[mt], nj = j + dy[mt];
				if (0 <= ni && ni < h && 0 <= nj && nj < w) {
					if (grid[ni][nj] == '.') {
						allStar = false;
						break;
					}
				} else {
					allStar = false;
					break;
				}
			}
			if (allStar) {
				cx = i, cy = j;
				break;
			}
		}
	}
	if (cx == -1) {
		printf("NO\n");
		return 0;
	}
	for (int mt = 0; mt < 4; ++mt) {
		grid[cx][cy] = '*';
		int px = cx, py = cy;
		while (0 <= px && px < h && 0 <= py && py < w && grid[px][py] == '*') {
			grid[px][py] = '.';
			px += dx[mt], py += dy[mt];
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (grid[i][j] == '*') {
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}