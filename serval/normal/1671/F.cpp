#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

const int mod = 998244353;
const int LIM = 11;
const int N = 35;
const int M = 13;

int f[N][N][N];
int g[N][N][N];
// len k x

int poly[N][N][M];
// k x coef

int mt[M][M];

int cur[N], vis[N];
int mn[N], mx[N];
void dfs(int len, int d = 1, int k = 0, int x = 0)
{
	if (d == len + 1)
	{
		for (int i = 0; i <= len + 1; i++)
		{
			mn[i] = len + 1;
			mx[i] = 0;
		}
		for (int i = 1; i <= len; i++)
			mx[i] = max(mx[i - 1], cur[i]);
		for (int i = len; i; i--)
			mn[i] = min(mn[i + 1], cur[i]);
		for (int i = 1; i < len; i++)
			if (mx[i] < mn[i + 1])
				return;
		g[len][k][x]++;
		if (g[len][k][x] == mod)
			g[len][k][x] = 0;
		return;
	}
	for (int i = len; i; i--)
		if (!vis[i])
		{
			cur[d] = i;
			vis[i] = 1;
			int nk = k, nx = x;
			if (d > 1)
				nx += cur[d - 1] > cur[d];
			for (int j = 1; j < d; j++)
				nk += cur[j] > cur[d];
			if (nk <= LIM && nx <= LIM)
				dfs(len, d + 1, nk, nx);
			vis[i] = 0;
		}
}

int fpw(int b, int e = mod - 2)
{
	if (e == 0)
		return 1;
	int ret = fpw(b, e >> 1);
	ret = 1ll * ret * ret % mod;
	if (e & 1)
		ret = 1ll * ret * b % mod;
	return ret;
}

int fac[N], inv[N];

void gauss()
{
	for (int i = 1; i < M; i++)
	{
		int x = i;
		for (int j = i; j < M; j++)
			if (mt[j][i] != 0)
			{
				x = j;
				break;
			}
		if (i != x)
			for (int j = 0; j < M; j++)
				swap(mt[x][j], mt[i][j]);
		int inv = fpw(mt[i][i]);
		for (int j = 0; j < M; j++)
			mt[i][j] = 1ll * mt[i][j] * inv % mod;
		assert(mt[i][i] == 1);
		for (int j = i + 1; j < M; j++)
		{
			int cur = mt[j][i];
			for (int k = 0; k < M; k++)
				mt[j][k] = (mt[j][k] + mod - 1ll * cur * mt[i][k] % mod) % mod;
		}
	}
	for (int i = M - 1; i; i--)
	{
		for (int j = i - 1; j; j--)
		{
			mt[j][0] = (mt[j][0] + mod - 1ll * mt[j][i] * mt[i][0] % mod) % mod;
		}
	}
}

int dfs2(int i, int k, int x, int c = 0, int coef = 1)
{
	if (k == 0 || x == 0)
	{
		if (k || x)
			return 0;
		return 1ll * coef * fac[i + c] % mod * inv[i] % mod * inv[c] % mod;
	}
	int ret = 0;
	for (int n = 1; n <= i; n++)
		for (int kk = 1; kk <= k; kk++)
			for (int xx = 0; xx <= x; xx++)
				if (g[n][kk][xx])
				{
					int cur = 1ll * coef * g[n][kk][xx] % mod;
					ret = (ret + dfs2(i - n, k - kk, x - xx, c + 1, cur)) % mod;
				}
	return ret;
}

int main()
{
	fac[0] = inv[0] = 1;
	for (int i = 1; i < N; i++)
	{
		fac[i] = 1ll * fac[i - 1] * i % mod;
		inv[i] = fpw(fac[i]);
	}
	for (int i = 1; i <= LIM + 1; i++)
	{
		dfs(i);
	}
	for (int i = 1; i < N; i++)
	{
		for (int k = 1; k <= LIM; k++)
			for (int x = 1; x <= LIM; x++)
			{
				f[i][k][x] = dfs2(i, k, x);
			}
	}
	for (int k = 1; k <= LIM; k++)
		for (int x = 1; x <= LIM; x++)
		{
			for (int i = N - M + 1, o = 1; i < N && o < M; i++, o++)
			{
				int cur = 1;
				for (int j = 1; j < M; j++)
				{
					mt[o][j] = cur;
					cur = 1ll * cur * i % mod;
				}
				mt[o][0] = f[i][k][x];
			}
			gauss();
			for (int i = 0; i < M; i++)
				poly[k][x][i] = mt[i][0];
		}
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, k, x;
		scanf("%d%d%d", &n, &k, &x);
		if (n < N)
		{
			printf("%d\n", f[n][k][x]);
			continue;
		}
		int ans = 0, cur = 1;
		for (int i = 1; i < M; i++)
		{
			ans = (ans + 1ll * poly[k][x][i] * cur) % mod;
			cur = 1ll * cur * n % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}