#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define inf 1000000000

int n, a[N], cnt[N], id[N], pos[N][N], f[N][256][N/8];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		a[i] = --x;
		pos[x][++cnt[x]] = i;
		id[i] = cnt[x];
	}
	for (int j = 1; j < 256; j ++) {
		for (int k = 1; k <= n / 8; k ++) f[0][j][k] = -inf;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < 256; j ++) {
			for (int k = 0; k <= n / 8; k ++) {
				f[i][j][k] = f[i-1][j][k];
				int x = a[i];
				if (!(j & (1 << x))) continue;
				if (k && id[i] >= k) {
					int I = pos[x][id[i]-k+1] - 1;
					f[i][j][k] = max(f[i][j][k], f[I][j^(1<<x)][k] + k);
				}
				if (id[i] >= k + 1) {
					int I = pos[x][id[i]-k] - 1;
					f[i][j][k] = max(f[i][j][k], f[I][j^(1<<x)][k] + k + 1);
				}
			}
		}
	}
	int ans = 0;
	for (int k = 0; k <= n / 8; k ++) ans = max(ans, f[n][255][k]);
	printf("%d\n", ans);
	return 0;
}