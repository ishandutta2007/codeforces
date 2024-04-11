#include <cstdio>

using namespace std;

const int inf = 1 << 30;
const int MAXN = 550;

int grid[MAXN][MAXN];
int sums[MAXN][MAXN];

int N, M;

int get(int x1, int y1, int x2, int y2) {
	return sums[x2][y2] - sums[x1][y2] - sums[x2][y1] + sums[x1][y1];
}

void prec() {
	for(int x = 0; x < N; ++x) {
		int cur = 0;
		for(int y = 0; y < M; ++y) {
			cur += grid[x][y];
			sums[x + 1][y + 1] = sums[x][y + 1] + cur;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < M; ++j) {
			scanf("%d", grid[i] + j);
		}
	}

	prec();

	int ans = -inf;
	for(int x = 0; x < N; ++x) {
		for(int y = 0; y < M; ++y) {
			int cursum = grid[x][y];
			int lx = x - 1, ly = y - 1;
			int ux = x + 2, uy = y + 2;
			while (lx >= 0 && ly >= 0 && ux <= N && uy <= M) {
				cursum = get(lx, ly, ux, uy) - cursum - grid[lx + 1][ly];
				if (cursum > ans) {
					ans = cursum;
//					printf("(%d,%d) to (%d,%d) is %d\n", lx, ly, ux, uy, cursum);
				}
				--lx;
				--ly;
				++ux;
				++uy;

			}
		}
	}

	printf("%d\n", ans);
	return 0;
}