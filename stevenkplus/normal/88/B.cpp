#include <cstdio>

using namespace std;

const int MAXN = 50;
const int MAXC = 30;
const int MAXQ = 500100;

bool poss[MAXC];
bool exist[MAXC];

int conv(char c) {
	if (c == 'S') {
		return 0;
	}
	return c - 'a' + 1;
}

int dist(char c) {
	if (c >= 'a' && c <= 'z') {
		int k = conv(c);
		if (exist[k]) {
			return 0;
		} else {
			return -1;
		}
	} else {
		int k = c - 'A' + 1;
		if (!exist[k] || !exist[0]) {
			return -1;
		} else if (poss[k]) {
			return 0;
		} else {
			return 1;
		}
	}
}

int N, M, X;
char grid[MAXN][MAXN];

int Q;
char query[MAXQ];

int main() {
	scanf("%d %d %d", &N, &M, &X);
	for(int i = 0; i < N; ++i) {
		scanf("%s", grid[i]);
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			exist[conv(grid[i][j])] = true;
			if (grid[i][j] == 'S') {
				for(int x = 0; x < N; ++x) {
					for(int y = 0; y < M; ++y) {
						int dx = x - i;
						int dy = y - j;
						int dst = dx * dx + dy * dy;
						if (dst <= X * X) {
							poss[conv(grid[x][y])] = true;
						}
					}
				}
			}
		}
	}

	scanf("%d", &Q);
	int ans = 0;
	scanf("%s", query);
	for(int i = 0; i < Q; ++i) {
		int tmp = dist(query[i]);
		if (tmp == -1) {
			ans = -1;
			break;
		} else {
			ans += tmp;
		}
	}

	printf("%d\n", ans);
	return 0;
}