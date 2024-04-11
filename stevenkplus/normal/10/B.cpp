#include <cstdio>
#include <algorithm>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 110;

bool grid[MAXN][MAXN];

int N, Q;
int center;

int dist(int x, int y) {
	return abs(x - center) + abs(y - center);
}

int main() {
	scanf("%d %d", &Q, &N);
	center = (N + 1) / 2;
	for(int i = 0; i < Q; ++i) {
		int x;
		scanf("%d", &x);

		int best = inf;
		int ansx = -1;
		int ansy = -1;
		for(int row = 1; row <= N; ++row) {
			int numtaken = 0;
			int left = 1;
			int right = x;
			int score = 0;
			for(int i = 1; i <= x; ++i) {
				if (grid[row][i]) {
					++numtaken;
				}
				score += dist(row, i);
			}

			while (right <= N) {
				if (numtaken == 0) {
					if (score < best) {
						best = score;
						ansx = row;
						ansy = left;
					}
				}

				++right;
				if (right > N) break;
				score += dist(row, right);
				if (grid[row][right]) ++numtaken;
				if (grid[row][left]) --numtaken;
				score -= dist(row, left);
				++left;
			}
		}

		if (ansx == -1) {
			printf("-1\n");
		} else {
			int yr = ansy + x - 1;
			for(int i = ansy; i <= yr; ++i) {
				grid[ansx][i] = true;
			}
			printf("%d %d %d\n", ansx, ansy, yr);
		}
	}

	return 0;
}