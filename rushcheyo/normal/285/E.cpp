#include <bits/stdc++.h>
using namespace std;
const int N = 1005, P = 1000000007;
int n, m, dp[N][N][2][2], fac[N], ifac[N];
void upd(int &x, int y) { x = x + y >= P ? x + y - P : x + y; }
int pw(int a, int x) { int ans = 1; for (; x; x >>= 1, a = 1ll * a * a % P) if (x & 1) ans = 1ll * ans * a % P; return ans; }
int C(int n, int m) { return 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P; }
int main() {
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[n] = pw(fac[n], P - 2);
	for (int i = n; i; i--) ifac[i - 1] = 1ll * ifac[i] * i % P;
	dp[0][0][1][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++)
					if (dp[i][j][x][y]) {
						upd(dp[i + 1][j][y][0], dp[i][j][x][y]);
						upd(dp[i + 1][j + 1][y][1], dp[i][j][x][y]);
						if (!x) upd(dp[i + 1][j + 1][y][0], dp[i][j][x][y]);
					}
	int ans = 0;
	for (int i = m, s = 1; i <= n; i++, s *= -1)
		ans = (ans + 1ll * s * (dp[n][i][0][0] + dp[n][i][1][0]) * C(i, m) % P * fac[n - i]) % P;
	printf("%d\n", (ans + P) % P);
	return 0;
}