#include <bits/stdc++.h>
using namespace std;
#define N 303

int f[N*2][N][N], n, a[N][N];

int dx[] = {-1, 0};
int dy[] = {0, -1};

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) scanf("%d", &a[i][j]);
	for (int i = 0; i <= 2 * n; i ++) for (int j = 0; j <= n; j ++) for (int k = 0; k <= n; k ++) f[i][j][k] = -(1 << 30);
	f[2][1][1] = a[1][1];
	for (int dis = 3; dis <= 2 * n; dis ++) {
		for (int i1 = 1; i1 <= n && i1 < dis; i1 ++) {
			for (int i2 = 1; i2 <= n && i2 < dis; i2 ++) {
				int j1 = dis - i1, j2 = dis - i2;
				for (int k = 0; k < 2; k ++) {
					int I1 = i1 + dx[k], J1 = j1 + dy[k];
					if (I1 < 1 || I1 > n || J1 < 1 || J1 > n) continue;
					for (int l = 0; l < 2; l ++) {
						int I2 = i2 + dx[l], J2 = j2 + dy[l];
						if (i2 < 1 || I2 > n || J2 < 1 || J2 > n) continue;
						if (i1 == i2) f[dis][i1][i2] = max(f[dis][i1][i2], f[dis-1][I1][I2] + a[i1][j1]);
						else f[dis][i1][i2] = max(f[dis][i1][i2], f[dis-1][I1][I2] + a[i1][j1] + a[i2][j2]);
					}
				}
			}
		}
	}
	printf("%d\n", f[2*n][n][n]);
	return 0;
}