#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int NMAX = 2010;
constexpr ll MOD = 1000000007;

char grid[NMAX][NMAX];

int rocksBelow[NMAX][NMAX], rocksAhead[NMAX][NMAX]; // these assume current cell free

int waysDown[NMAX][NMAX], waysRight[NMAX][NMAX];
int waysDownSum[NMAX][NMAX], waysRightSum[NMAX][NMAX];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%s", grid[i]);
	if (n == 1 && m == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			if (i < n - 1) {
				rocksBelow[i][j] = rocksBelow[i+1][j] + (grid[i+1][j] == 'R' ? 1 : 0);
			}
			if (j < m - 1) {
				rocksAhead[i][j] = rocksAhead[i][j+1] + (grid[i][j+1] == 'R' ? 1 : 0);
			}
//			printf("rocks %d %d %d %d\n", i, j, rocksBelow[i][j], rocksAhead[i][j]);
		}
	}
	waysDown[n-1][m-1] = waysRight[n-1][m-1] = waysDownSum[n-1][m-1] = waysRightSum[n-1][m-1] = 1;
	for (int i = n - 1; i >= 0; --i) {
		for (int j = m - 1; j >= 0; --j) {
			// compute waysDown
			if (i < n - 1) {
				int lowReachRow = n - 1 - rocksBelow[i][j];
//				printf("%d %d lrr %d\n", i, j, lowReachRow);
				waysDown[i][j] = (waysRightSum[i + 1][j] - waysRightSum[lowReachRow + 1][j]) % MOD;
			}
			// compute waysRight
			if (j < m - 1) {
				int lowReachCol = m - 1 - rocksAhead[i][j];
//				printf("%d %d lrc %d\n", i, j, lowReachCol);
				waysRight[i][j] = (waysDownSum[i][j + 1] - waysDownSum[i][lowReachCol + 1]) % MOD;
			}
			// update the partial sum arrays
			waysRightSum[i][j] = (waysRight[i][j] + waysRightSum[i+1][j]) % MOD;
			waysDownSum[i][j] = (waysDown[i][j] + waysDownSum[i][j + 1]) % MOD;
//			printf("%d %d wd wr %d %d\n", i, j, waysDown[i][j], waysRight[i][j]);
//			printf("%d %d wds wrs %d %d\n", i, j, waysDownSum[i][j], waysRightSum[i][j]);
		}
	}
	int ans = (waysDown[0][0] + waysRight[0][0]) % MOD;
	printf("%lld\n", (ans + MOD) % MOD);
	return 0;
}