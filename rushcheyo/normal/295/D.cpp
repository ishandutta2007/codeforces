#include <cstdio>

const int N = 2005, P = 1000000007;
int n, m, g[N][N], f[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int j = 2; j <= m; j++) f[1][j] = 1;
	for (int i = 2; i <= n; i++)
		for (int s0 = 0, s1 = 0, j = 2; j <= m; j++) {
			s0 = (s0 + f[i - 1][j]) % P;
			s1 = (s1 + 1ll * f[i - 1][j] * j) % P;
			f[i][j] = (s0 * (j + 1ll) - s1 + P) % P;
		}
	int ans = 0;
	for (int j = 2; j <= m; j++)
		for (int s = 0, i = 1; i <= n; i++) {
			s = (s + f[i][j]) % P;
			ans = (ans + (m - j + 1ll) * s % P * f[n - i + 1][j]) % P;
		}
	printf("%d\n", ans);
	return 0;
}