#include <bits/stdc++.h>
using namespace std;
#define N 505

int n, sum, c[N], cnt, prt[N];
bool f[N][N][N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d %d", &n, &sum);
	for (int i = 1; i <= n; i ++) scanf("%d", &c[i]);
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j <= sum; j ++) {
			for (int k = 0; k <= sum; k ++) f[i][j][k] = f[i-1][j][k];
		}
		for (int j = 0; j <= sum; j ++) {
			for (int k = 0; k <= sum; k ++) if (f[i-1][j][k]) {
				if (j + c[i] <= sum) f[i][j+c[i]][k] = 1;
				if (k + c[i] <= sum) f[i][j][k+c[i]] = 1;
			}
		}
	}
	for (int i = 0; i <= sum; i ++) {
		if (f[n][i][sum-i]) prt[cnt++] = i;
	}
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i ++) printf("%d ", prt[i]);
	return 0;
}