#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int E = N << 1;

int n;
int h[N], to[E], nx[E], et;
int len[N], hs[N];
int cnt[N], mx[N], pos[N], idx;
int ans[N];

void ae(int u, int v)
{
	et++;
	to[et] = v;
	nx[et] = h[u];
	h[u] = et;
}

void decomp(int u = 1, int p = 0)
{
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != p)
		{
			decomp(to[i], u);
			len[u] = max(len[u], len[to[i]]);
			if (len[to[i]] > len[hs[u]])
				hs[u] = to[i];
		}
	len[u]++;
}

void dfs(int u = 1, int p = 0)
{
	pos[u] = ++idx;
	cnt[idx]++;
	mx[u] = idx;
	if (hs[u])
	{
		dfs(hs[u], u);
		if (cnt[mx[hs[u]]] > cnt[mx[u]])
			mx[u] = mx[hs[u]];
	}
	for (int i = h[u]; i; i = nx[i])
		if (to[i] != hs[u] && to[i] != p)
		{
			dfs(to[i], u);
			for (int j = pos[to[i]], k = 1; k <= len[to[i]]; j++, k++)
			{
				cnt[pos[u] + k] += cnt[j];
				if (cnt[pos[u] + k] > cnt[mx[u]]
					|| (cnt[pos[u] + k] == cnt[mx[u]] && k < mx[u] - pos[u]))
					mx[u] = pos[u] + k;
			}
		}
	ans[u] = mx[u] - pos[u];
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		ae(u,v);
		ae(v,u);
	}
	decomp();
	dfs();
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}