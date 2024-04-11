#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

typedef long long LL;
LL expmod(LL a, LL b, LL mod) {
	LL rlt = 1;
	for (a %= mod; b; a = a * a % mod, b >>= 1) if (b & 1) rlt = rlt * a % mod;
	return rlt;
}

#define N 1010
typedef pair <int, int> pii;

int n, m, a[N][N];
pii id[N*N];
int r, c;

bool cmp(pii x, pii y) {
	return a[x.first][x.second] < a[y.first][y.second];
}

int q[N*N], s[N*N], f[N*N], g[N*N], ff[N*N], gg[N*N];

int sqr(int x) {
	return 1ll * x * x % mod;
}

int main() {
	//freopen("r.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
	scanf("%d %d", &r, &c);
	int tot = 0;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= m; j ++) id[tot++] = make_pair(i, j);
	sort(id, id + tot, cmp);

	s[0] = q[0] = 0;
	f[0] = id[0].first, g[0] = id[0].second;
	ff[0] = sqr(f[0]), gg[0] = sqr(g[0]);
	if (id[0] == make_pair(r, c)) {
		puts("0");
		return 0;
	}
	int last = -1;
	for (int i = 1; i < tot; i ++) {
		int x = id[i].first, y = id[i].second;
		f[i] = (f[i-1] + x) % mod, ff[i] = (ff[i-1] + sqr(x)) % mod;
		g[i] = (g[i-1] + y) % mod, gg[i] = (gg[i-1] + sqr(y)) % mod;

		if (a[x][y] != a[id[i-1].first][id[i-1].second]) last = i - 1;
		if (last >= 0) {
			q[i] = (s[last] + 1ll * (last + 1) * (sqr(x) + sqr(y))) % mod;
			q[i] = (1ll * q[i] + ff[last] + gg[last]) % mod;
			q[i] = (1ll * q[i] - 2ll * x * f[last] % mod - 2ll * y * g[last] % mod) % mod;
			if (q[i] < 0) q[i] += mod;
			q[i] = 1ll * q[i] * expmod(last + 1, mod - 2, mod) % mod;
		}
		s[i] = (s[i-1] + q[i]) % mod;
		if (x == r && y == c) {
			printf("%d\n", q[i]);
			puts("");
			return 0;
		}
	}

	return 0;
}