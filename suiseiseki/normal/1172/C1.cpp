#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200010;
const int M = 3010;
const int mod = 998244353;
int qpow(int x, int y) {
	int out = 1;
	while (y) {
		if (y & 1) out = (ll) out * x % mod;
		x = (ll) x * x % mod;
		y >>= 1;
	}
	return out;
}
int n, m, a[N], w[N], f[M][M], g[M][M], inv[M << 1], sum[3];
int main() {
	int i,j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) {
		scanf("%d", w + i);
		sum[a[i]] += w[i];
		sum[2] += w[i];
	}
	for (i = max(0, m - sum[0]);i<=2*m; ++i) inv[i] = qpow(sum[2] + i - m, mod - 2);
	for (i = m; i >= 0; --i) {
		f[i][m - i] = g[i][m - i] = 1;
		for (j = min(m - i - 1, sum[0]); j >= 0; --j) {
			f[i][j] = ((ll) (sum[1] + i + 1) * f[i + 1][j] + (ll) (sum[0] - j) * f[i][j + 1]) % mod * inv[i - j + m] % mod;
			g[i][j] = ((ll) (sum[1] + i) * g[i + 1][j] + (ll) (sum[0] - j - 1) * g[i][j + 1]) % mod * inv[i - j + m] % mod;
		}
	}
	for (i = 1; i <= n; ++i) printf("%d\n", int((ll) w[i] * (a[i] ? f[0][0] : g[0][0]) % mod));
	return 0;
}