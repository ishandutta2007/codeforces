#include <bits/stdc++.h>

using namespace std;

int rd() {
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - 48, c = getchar();
	return x;
}

int k, n, m, sum, a[110];
double f[2][1000010], ans;

int main() {
	n = rd(), m = rd();
	for (int i = 1; i <= n; i ++) a[i] = rd(), sum += a[i];
	if (m == 1) return puts("1"), 0;
	f[0][0] = m - 1;
	for (int i = 0; i < n; i ++) {
		k ^= 1;
		memset(f[k], 0, sizeof f[k]);
		for (int j = 0; j <= i * m; j ++) {
			double p = f[k ^ 1][j] / (m - 1);
			f[k][j + 1] += p, f[k][j + m + 1] -= p;
			f[k][j + a[i + 1]] -= p, f[k][j + a[i + 1] + 1] += p;
		}
		for (int j = 1; j <= n * m; j ++) f[k][j] += f[k][j - 1];
	}
	for (int i = 0; i < sum; i ++) ans += f[k][i];
	printf("%.12f\n", ans + 1.);
	return 0;
}