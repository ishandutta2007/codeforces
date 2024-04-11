#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 3010
const long long INF = 1e18;

int a[N], b[N], c[N], d[N], n, m;
long long f[N][N], now;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		b[i] = a[i] - i;
		d[i] = b[i];
	}
	sort (d + 1, d + n + 1);
	d[0] = -n;
	for (int i = 1; i <= n; i ++) if (d[i] > d[i-1]) c[++ m] = d[i];
	f[1][0] = INF;
	for (int j = 1; j <= m; j ++) f[1][j] = min(f[1][j-1], 1ll * abs(b[1] - c[j]));
	for (int i = 2; i <= n; i ++) {
		f[i][0] = INF;
		for (int j = 1; j <= m; j ++) {
			f[i][j] = min(f[i][j-1], f[i-1][j] + abs(b[i] - c[j]));
		}
	}
	printf("%I64d\n", f[n][m]);
	return 0;
}