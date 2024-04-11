#include <bits/stdc++.h>
using namespace std;
#define N 22

int f[N][N][N][5][5];

void solve() {
	for (int i = 1; i <= 4; i ++) {
		for (int j = 1; j <= 4; j ++) if (i != j) f[2][0][0][i][j] = 1;
	}
	for (int i = 3; i <= 20; i ++) {
		for (int j = 0; j <= i - 3; j ++) {
			for (int k = 0; k <= i - 3; k ++) {
				for (int a = 1; a <= 4; a ++) {
					for (int b = 1; b <= 4; b ++) if (b != a) {
						for (int c = 1; c <= 4; c ++) if (c != b) {
							if (a < b && b > c) f[i][j+1][k][b][c] += f[i-1][j][k][a][b];
							else if (a > b && b < c) f[i][j][k+1][b][c] += f[i-1][j][k][a][b];
							else f[i][j][k][b][c] += f[i-1][j][k][a][b];
						}
					}
				}
			}
		}
	}
}

int main() {
//	freopen("e.in", "r", stdin);
	solve();
	int n, t;
	scanf("%d %d", &n, &t);
	int ans = 0;
	for (int i = 1; i <= 4; i ++) for (int j = 1; j <= 4; j ++) ans += f[n][t][t-1][i][j];
	printf("%d\n", ans);
	return 0;
}