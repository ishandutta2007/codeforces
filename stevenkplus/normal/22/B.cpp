#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 30;
char grid[MAXN][MAXN];

int N, M;

bool check(int x1, int x2, int y1, int y2) {
	for(int x = x1; x < x1 + x2; ++x) {
		for(int y = y1; y < y1 + y2; ++y) {
			if (grid[x][y] == '1') {
				return false;
			}
		}
	}
	return true;
}

int perim(int x1, int x2, int y1, int y2) {
	return 2 * (x2 + y2);
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		scanf("%s", grid[i]);
	}
	int m = 0;
	for(int x = 0; x < N; ++x) {
		for(int x1 = 1; x1 + x <= N; ++x1) {
			for(int y = 0; y < M; ++y) {
				for(int y1 = 1; y1 + y <= M; ++y1) {
					if (check(x, x1, y, y1)) {
						int p = perim(x, x1, y, y1);
						m = max(m, p);
					}
				}
			}
		}
	}
	printf("%d\n", m);
	return 0;
}