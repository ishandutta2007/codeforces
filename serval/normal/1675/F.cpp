#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int L = 19;
const int E = N << 1;

int n, k;
int h[N], nx[E], to[E], et;
int dep[N], par[L][N];
int pre[N];
int x, y;
int a[N];
int ans;

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
}

void dfs(int u, int p = 0)
{
	dep[u] = dep[p] + 1;
	par[0][u] = p;
	for (int i = 1; i < L; i++)
		par[i][u] = par[i - 1][par[i - 1][u]];
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
			dfs(to[i], u);
}

int lca(int u, int v)
{
	if (dep[u] < dep[v])
		swap(u, v);
	for (int i = L - 1; i >= 0; i--)
		if (dep[par[i][u]] >= dep[v])
			u = par[i][u];
	if (u == v)
		return u;
	for (int i = L - 1; i >= 0; i--)
		if (par[i][u] != par[i][v])
			u = par[i][u], v = par[i][v];
	return par[0][u];
}

void getans(int u, int p = 0)
{
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
		{
			getans(to[i], u);
			pre[u] += pre[to[i]];
		}
	if (pre[u])
		ans += 2;
}

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%d%d", &x, &y);
	for (int i = 1; i <= k; i++)
		scanf("%d", &a[i]);
	et = 0;
	for (int i = 1; i <= n; i++)
		h[i] = pre[i] = 0;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u, v);
		ae(v, u);
	}
	dfs(1);
	for (int i = 1; i <= k; i++)
	{
		int l = lca(a[i], x);
		pre[a[i]]++;
		pre[x]++;
		pre[l] -= 2;
	}
	int l = lca(x, y);
	pre[x]++;
	pre[y]++;
	pre[l] -= 2;
	ans = 0;
	getans(1);
	ans -= dep[x] + dep[y] - 2 * dep[l];
	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}