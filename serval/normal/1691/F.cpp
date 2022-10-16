#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int E = N << 1;
const int mod = 1e9 + 7;

int n, k;
int h[N], nx[E], to[E], et;
int fac[N], inv[N];

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
}

int fpw(int b, int e = mod - 2)
{
	if (e == 0) return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1) ret = 1ll * ret * b % mod;
	return ret;
}

int C(int n, int m)
{
	if (n < 0 || m < 0 || m > n)
		return 0;
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int ans;

int sz[N];
vector <int> sub[N];

void dfs(int u, int p = 0)
{
	sz[u] = 1;
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
		{
			dfs(to[i], u);
			sz[u] += sz[to[i]];
			sub[u].emplace_back(sz[to[i]]);
		}
	if (sz[u] != n)
		sub[u].emplace_back(n - sz[u]);
	int f = C(n, k), s = 0;
	for (auto i : sub[u])
		s = (s + C(i, k)) % mod;
	f = (f + mod - s) % mod;
	ans = (ans + 1ll * f * n) % mod;
	for (auto i : sub[u])
	{
		int g = C(n - i, k);
		int t = (s + mod - C(i, k)) % mod;
		g = (g + mod - t) % mod;
		ans = (ans + 1ll * g * (n - i) % mod * i) % mod;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u, v);
		ae(v, u);
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	inv[n] = fpw(fac[n]);
	for (int i = n; i; i--)
		inv[i - 1] = 1ll * inv[i] * i % mod;
	dfs(1);
	printf("%d\n", ans);
	return 0;
}