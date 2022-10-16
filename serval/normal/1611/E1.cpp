#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
const int E = N << 1;
const int oo = 1e9;

int n, k;
int h[N], nx[E], to[E], et;
int f[N];

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
}

void dfs1(int u, int p = 0)
{
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
		{
			dfs1(to[i], u);
			f[u] = min(f[u], f[to[i]] + 1);
		}
}

int dfs2(int u, int p = 0, int d = 0)
{
	if (f[u] <= d)
		return 0;
	int sub = 0;
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
		{
			if (dfs2(to[i], u, d + 1))
				return 1;
			sub++;
		}
	return !sub;
}

void solve()
{
	scanf("%d%d", &n, &k);
	et = 0;
	for (int i = 1; i <= n; i++)
	{
		h[i] = 0;
		f[i] = oo;
	}
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		f[x] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u, v);
		ae(v, u);
	}
	dfs1(1);
	if (dfs2(1))
		printf("YES\n");
	else
		printf("NO\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}