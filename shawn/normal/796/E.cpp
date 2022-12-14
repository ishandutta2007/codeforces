#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}
int a[1005], b[1005], f[2][1005][55][55], n, p, k, ans;
inline int ab(int x) {
	return max(x, 0);
}

int main() {
	n = rd(), p = rd(), k = rd(), p = min(p, 2 * (n + k - 1) / k);
	int r = rd(); for (int i = 1; i <= r; i ++) a[rd()] = 1;
	int s = rd(); for (int i = 1; i <= s; i ++) b[rd()] = 1;
	memset(f, -0x7f, sizeof f);
	f[0][0][0][0] = 0;
	for (int i = 1; i <= n; memset(f[~i & 1], -0x7f, sizeof f[~i & 1]), i ++) for (int j = 0; j <= p; j ++) {
			for (int x = 0; x < k; x ++) for (int y = 0; y < k; y ++) 
					f[i & 1][j][ab(x - 1)][ab(y - 1)] = max(f[i & 1][j][ab(x - 1)][ab(y - 1)], f[~i & 1][j][x][y] + (x && a[i] || y && b[i]));
			for (int y = 0; y < k; y ++) f[i & 1][j + 1][k - 1][ab(y - 1)] = max(f[i & 1][j + 1][k - 1][ab(y - 1)], f[~i & 1][j][0][y] + (a[i] || y && b[i]));
			for (int x = 0; x < k; x ++) f[i & 1][j + 1][ab(x - 1)][k - 1] = max(f[i & 1][j + 1][ab(x - 1)][k - 1], f[~i & 1][j][x][0] + (x && a[i] || b[i]));
	}
	for(int j = 0; j <= p; j++) for (int x = 0; x < k; x ++) for (int y = 0; y < k; y ++) ans = max(ans, f[n & 1][j][x][y]);
	printf("%d", ans);
	return 0;
}