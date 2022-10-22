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

typedef long long ll;

const int N = 5005, M = 680, L = N << 1;

int tm, n, cnt[L], tot, pri[N], id[L], top, m, ecnt, nxt[L], adj[L], go[L], fa[L],
sze[L], maxs[L], G;
bool mark[N];
ll ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void sieve()
{
	mark[0] = mark[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!mark[i]) pri[++tot] = i;
		for (int j = 1; j <= tot; j++)
		{
			if (1ll * i * pri[j] > n) break;
			mark[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}

struct node
{
	int cnt[M];
	
	void get(int k)
	{
		for (int i = 1; i <= tot; i++) cnt[i] = 0;
		for (int i = 1; i <= tot; i++)
			for (int j = k / pri[i]; j; j /= pri[i])
				cnt[i] += j;
	}
	
	friend inline bool operator == (node a, node b)
	{
		for (int i = 1; i <= tot; i++)
			if (a.cnt[i] != b.cnt[i]) return 0;
		return 1;
	}
} stk[L], pt[L];

node lca(node a, node b)
{
	node res;
	for (int i = 1; i <= tot; i++) res.cnt[i] = 0;
	for (int i = tot; i >= 1; i--)
	{
		res.cnt[i] = std::min(a.cnt[i], b.cnt[i]);
		if (a.cnt[i] != b.cnt[i]) break;
	}
	return res;
}

int dep(node a)
{
	int res = 0;
	for (int i = 1; i <= tot; i++) res += a.cnt[i];
	return res;
}

void dfs(int u)
{
	sze[u] = cnt[u]; maxs[u] = 0;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		dfs(v), sze[u] += sze[v], maxs[u] = std::max(maxs[u], sze[v]);
}

void dfs2(int u)
{
	if (std::max(maxs[u], tm - sze[u]) < std::max(maxs[G], tm - sze[G]))
		G = u;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		dfs2(v);
}

int main()
{
	int x;
	read(tm);
	for (int i = 1; i <= tm; i++)
	{
		read(x); if (!x) x = 1; cnt[x]++;
		n = std::max(n, x);
	}
	sieve(); m = n;
	for (int i = 1; i <= n; i++)
	{
		node tmp; tmp.get(i); pt[i] = tmp;
		if (!top) {stk[++top] = tmp; id[top] = i; continue;}
		node u = lca(stk[top], tmp);
		while (top && dep(stk[top]) > dep(u))
		{
			if (top == 1 || dep(stk[top - 1]) < dep(u))
				pt[fa[id[top]] = ++m] = u;
			top--;
		}
		if (!(u == stk[top])) fa[m] = id[top], stk[++top] = u, id[top] = m;
		stk[++top] = tmp; id[top] = i; fa[i] = id[top - 1];
	}
	int rt;
	for (int i = 1; i <= m; i++)
		if (fa[i]) add_edge(fa[i], i); else rt = i;
	dfs(rt); G = rt; dfs2(rt);
	for (int i = 1; i <= n; i++) ans += 1ll * (dep(pt[G]) + dep(pt[i])
		- dep(lca(pt[G], pt[i])) * 2) * cnt[i];
	return std::cout << ans << std::endl, 0;
}