#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 1e5 + 5, M = N << 1;

int n, m, ecnt, nxt[M], adj[N], st[M], go[M], tot, ow[M], ToT, dfn[N],
sze[N], seq[N], dep[N], f[N], cnt[N];
bool vis[N], ans[N], siv[M];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; st[ecnt] = u; go[ecnt] = v;
}

void dfs(int u)
{
	vis[u] = 1; seq[dfn[u] = ++ToT] = u; sze[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) dep[v] = dep[u] + 1, dfs(v), sze[u] += sze[v], siv[e] = 1;
		else ow[++tot] = e;
}

void work()
{
	int x, y, T = 100;
	read(n); read(m); ecnt = 0;
	for (int i = 1; i <= n; i++) adj[i] = 0;
	while (m--) read(x), read(y), add_edge(x, y);
	while (T--)
	{
		for (int i = 1; i <= n; i++) vis[i] = 0, cnt[i] = 0;
		for (int i = 1; i <= ecnt; i++) siv[i] = 0;
		int rt = (rand() << 15 | rand()) % n + 1, res = 1;
		tot = ToT = 0; dep[rt] = 1; dfs(rt); bool is = 1;
		for (int i = 1; i <= tot; i++)
		{
			int e = ow[i]; cnt[st[e]]++; cnt[go[e]]--;
			if (dfn[go[e]] > dfn[st[e]] || dfn[st[e]] >= dfn[go[e]] + sze[go[e]])
				{is = 0; break;}
		}
		if (!is) continue;
		for (int i = 1; i <= n; i++) f[i] = 0;
		ans[rt] = 1;
		for (int i = n; i >= 1; i--)
		{
			int u = seq[i];
			for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
				if (siv[e])
				{
					cnt[u] += cnt[v];
					if (f[v] && (!f[u] || dep[f[v]] < dep[f[u]]))
						f[u] = f[v];
				}
				else if (!f[u] || dep[go[e]] < dep[f[u]]) f[u] = go[e];
		}
		for (int i = 2; i <= n; i++)
			res += (ans[seq[i]] = cnt[seq[i]] == 1 && ans[f[seq[i]]]);
		if (res >= (n + 4) / 5)
		{
			for (int i = 1; i <= n; i++) if (ans[i]) printf("%d ", i);
			puts("");
		}
		else puts("-1");
		return;
	}
	puts("-1");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}