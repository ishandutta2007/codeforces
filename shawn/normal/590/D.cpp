#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

const int inf = 0x7f7f7f7f;
int n, m, s, ans;
int a[151], f[151][150 * 150];

int main() {
	n = rd(), m = rd(), s = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd();
	memset(f, 0x7f, sizeof f);
	f[0][0] = 0;
	for (int k = 1; k <= n; k ++)
		for (int i = k - 1; i >= 0; i --)
			for (int j = 0; j <= k * i; j ++) if (f[i][j] != inf) {
					f[i + 1][j + k - i - 1] = min(f[i + 1][j + k - i - 1], f[i][j] + a[k]);
				}
	ans = inf;
	for (int j = 0; j <= min(s, n * (n - 1)); j ++) ans = min(ans, f[m][j]);
	printf("%d\n", ans);
	return 0;
}