#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

const int P = 1000000007;
const int maxN = 310;

int n, m;
int d[2][maxN][maxN][2][2];
int s[maxN][maxN][2][2];

inline int getSum(int lx, int rx, int ly, int ry, int dx, int dy) {
	if (lx > rx || ly > ry) {
		return 0;
	}
	int buffer = s[rx][ry][dx][dy] + s[lx - 1][ly - 1][dx][dy];
	buffer -= s[lx - 1][ry][dx][dy] + s[rx][ly - 1][dx][dy];
	while (buffer < 0) {
		buffer += P;
	}
	while (buffer >= P) {
		buffer -= P;
	}
	return buffer;
}

int main() {
	scanf("%d%d", &n, &m);
	int u = 0, v = 1;
	long long res = 0;
	for (int step = 1; step <= n; ++step, swap(u, v)) {
		for (int i = 1; i <= m; ++i) {
			for (int j = i; j <= m; ++j) {
				d[v][i][j][1][1] = getSum(i, j, i, j, 1, 1) + 1;
				if (d[v][i][j][1][1] >= P) {
					d[v][i][j][1][1] -= P;
				}

				d[v][i][j][1][0] = getSum(i, j, j + 1, m, 1, 1) + getSum(i, j, j, m, 1, 0);
				if (d[v][i][j][1][0] >= P) {
					d[v][i][j][1][0] -= P;
				}

				d[v][i][j][0][1] = getSum(1, i - 1, i, j, 1, 1) + getSum(1, i, i, j, 0, 1);
				if (d[v][i][j][0][1] >= P) {
					d[v][i][j][0][1] -= P;
				}

				d[v][i][j][0][0] = getSum(1, i - 1, j + 1, m, 1, 1);
				if (d[v][i][j][0][0] >= P) {
					d[v][i][j][0][0] -= P;
				}
				
				d[v][i][j][0][0] += getSum(1, i, j + 1, m, 0, 1);
				if (d[v][i][j][0][0] >= P) {
					d[v][i][j][0][0] -= P;
				}

				d[v][i][j][0][0] += getSum(1, i - 1, j, m, 1, 0);
				if (d[v][i][j][0][0] >= P) {
					d[v][i][j][0][0] -= P;
				}

				d[v][i][j][0][0] += getSum(1, i, j, m, 0, 0);
				if (d[v][i][j][0][0] >= P) {
					d[v][i][j][0][0] -= P;
				}
			}
		}

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= m; ++j) {
				for (int dx = 0; dx < 2; ++dx) {
					for (int dy = 0; dy < 2; ++dy) {
						res += d[v][i][j][dx][dy];

						s[i][j][dx][dy] = d[v][i][j][dx][dy];
						s[i][j][dx][dy] += s[i - 1][j][dx][dy];
						if (s[i][j][dx][dy] >= P) {
							s[i][j][dx][dy] -= P;
						}
						s[i][j][dx][dy] += s[i][j - 1][dx][dy];
						if (s[i][j][dx][dy] >= P) {
							s[i][j][dx][dy] -= P;
						}
						s[i][j][dx][dy] -= s[i - 1][j - 1][dx][dy];
						if (s[i][j][dx][dy] < 0) {
							s[i][j][dx][dy] += P;
						}
					}
				}
			}
		}
	}

	res %= P;
	printf("%d\n", (int)(res));

	return 0;
}