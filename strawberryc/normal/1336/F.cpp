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
typedef std::set<int>::iterator it;

const int N = 15e4 + 5, M = N << 1, L = 1e7 + 5, E = 20;

int n, m, k, ecnt, nxt[M], adj[N], go[M], times, dfn[N], dep[N], fa[N][E],
s[N], t[N], l[N], p[N], A[N], sze[N], cnt[N], son[N], rt[N], ToT, top, stk[M];
ll ans;
std::set<int> orz[N];
std::vector<int> a[N], b[N];

struct node
{
	int lc, rc, sum;
} T[L];

void change(int l, int r, int pos, int v, int &p)
{
	if (!p) p = ++ToT; T[p].sum += v;
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, T[p].lc);
	else change(mid + 1, r, pos, v, T[p].rc);
}

int ask(int l, int r, int s, int e, int p)
{
	if (!p || e < l || s > r) return 0;
	if (s <= l && r <= e) return T[p].sum;
	int mid = l + r >> 1;
	return ask(l, mid, s, e, T[p].lc) + ask(mid + 1, r, s, e, T[p].rc);
}

void change(int x, int v)
{
	for (; x <= n; x += x & -x)
		A[x] += v;
}

void sub(int u) {change(dfn[u], 1); change(dfn[u] + sze[u], -1);}

int ask(int x)
{
	int res = 0;
	for (; x; x -= x & -x) res += A[x];
	return res;
}

inline bool comp(int a, int b)
{
	return dep[l[a]] > dep[l[b]] || (dep[l[a]] == dep[l[b]] && l[a] < l[b]);
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	dep[u] = dep[fa[u][0] = fu] + (sze[u] = 1);
	for (int i = 0; i < 17; i++) fa[u][i + 1] = fa[fa[u][i]][i];
	dfn[u] = ++times;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u), sze[u] += sze[v];
}

int lca(int u, int v)
{
	if (dep[u] < dep[v]) std::swap(u, v);
	for (int i = 17; i >= 0; i--)
		if (dep[fa[u][i]] >= dep[v])
			u = fa[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (fa[u][i] != fa[v][i])
			u = fa[u][i], v = fa[v][i];
	return fa[u][0];
}

int J(int u, int k)
{
	for (int i = 17; i >= 0; i--)
		if ((k >> i) & 1) u = fa[u][i];
	return u;
}

void init(int u, int fu)
{
	int mx = -1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			init(v, u); cnt[u] += cnt[v];
			if (cnt[v] > mx) mx = cnt[v], son[u] = v;
		}
}

void wtf(int u, int i)
{
	if (dfn[l[i]] >= dfn[u] || dfn[u] >= dfn[l[i]] + sze[l[i]]) return;
	int len = dep[u] + dep[t[i]] - dep[l[i]] * 2;
	if (len < k || t[i] == l[i]) return;
	int v = dep[u] - dep[l[i]] >= k ? J(t[i], dep[t[i]] - dep[l[i]] - 1)
		: J(t[i], len - k);
	ans += ask(1, n, dfn[v], dfn[v] + sze[v] - 1, rt[l[i]]);
	if (ask(1, n, dfn[v], dfn[v] + sze[v] - 1, rt[l[i]]));
}

void DFS(int u, int fu)
{
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && v != son[u])
		{
			DFS(v, u);
			for (it x = orz[v].begin(); x != orz[v].end(); x++)
				change(1, n, dfn[t[*x]], -1, rt[l[*x]]);
		}
	if (son[u]) DFS(son[u], u);
	for (it x = orz[u].begin(); x != orz[u].end(); x++)
		wtf(u, *x), change(1, n, dfn[t[*x]], 1, rt[l[*x]]);
	if (son[u])
	{
		for (int e = adj[u], v; e; e = nxt[e])
		{
			if ((v = go[e]) == fu || v == son[u]) continue;
			for (it x = orz[v].begin(); x != orz[v].end(); x++) wtf(u, *x);
			for (it x = orz[v].begin(); x != orz[v].end(); x++)
				change(1, n, dfn[t[*x]], 1, rt[l[*x]]), orz[son[u]].insert(*x);
		}
		for (it x = orz[u].begin(); x != orz[u].end(); x++)
			orz[son[u]].insert(*x);
		std::swap(orz[u], orz[son[u]]);
	}
}

int main()
{
	int x, y;
	read(n); read(m); read(k);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	dfs(1, 0);
	for (int i = 1; i <= m; i++)
	{
		read(s[i]); read(t[i]);
		if (dfn[s[i]] > dfn[t[i]]) std::swap(s[i], t[i]);
		l[i] = lca(s[i], t[i]); p[i] = i;
		orz[s[i]].insert(i); cnt[s[i]]++; a[l[i]].push_back(i);
	}
	std::sort(p + 1, p + m + 1, comp);
	for (int i = 1; i <= m;)
	{
		int nxt = i;
		while (nxt <= m && l[p[i]] == l[p[nxt]]) nxt++;
		for (int j = i; j < nxt; j++)
		{
			int x = p[j], u = s[x], v = t[x], w = l[x];
			ans += ask(dfn[u]) + ask(dfn[v]) - ask(dfn[w]) * 2;
		}
		for (int j = i; j < nxt; j++)
		{
			int x = p[j], u = s[x], v = t[x], w = l[x];
			if (dep[u] - dep[w] >= k) sub(J(u, dep[u] - dep[w] - k));
			if (dep[v] - dep[w] >= k) sub(J(v, dep[v] - dep[w] - k));
		}
		i = nxt;
	}
	memset(A, 0, sizeof(A));
	for (int u = 1; u <= n; u++)
	{
		for (int i = 0; i < a[u].size(); i++)
		{
			int x = a[u][i];
			if (dep[s[x]] - dep[u] >= k)
			{
				ans += A[y = J(s[x], dep[s[x]] - dep[u] - k)]++; stk[++top] = y;
				if (t[x] != u) b[J(t[x], dep[t[x]] - dep[u] - 1)].push_back(y);
			}
			if (dep[t[x]] - dep[u] >= k)
			{
				ans += A[y = J(t[x], dep[t[x]] - dep[u] - k)]++; stk[++top] = y;
				if (s[x] != u) b[J(s[x], dep[s[x]] - dep[u] - 1)].push_back(y);
			}
		}
		while (top--) A[stk[top + 1]] = 0; top = 0;
		for (int e = adj[u], v; e; e = nxt[e])
		{
			if ((v = go[e]) == fa[u][0]) continue;
			for (int i = 0; i < b[v].size(); i++)
				ans -= A[y = b[v][i]]++, stk[++top] = y;
			while (top--) A[stk[top + 1]] = 0; top = 0;
		}
	}
	init(1, 0); DFS(1, 0);
	return std::cout << ans << std::endl, 0;
}