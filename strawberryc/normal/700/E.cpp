#include <bits/stdc++.h>

// 0830

template <class T>
inline T Abs(const T &a) {return a > 0 ? a : -a;}

const int N = 2e5 + 5, M = N << 1, L = 15e6 + 5;

int n, ecnt, nxt[M], adj[M], go[M], f[M], rt[M], lst = 1, ToT = 1, QAQ, ans;
char s[N];

struct sam
{
	int go[26], fa, maxl, ri;
} T[M];

struct node
{
	int lc, rc, sum;
} tr[L];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void extend(int c)
{
	int x = lst;
	T[lst = ++ToT].maxl = T[x].maxl + 1;
	T[lst].ri = T[lst].maxl;
	for (; x && !T[x].go[c]; x = T[x].fa)
		T[x].go[c] = lst;
	if (!x) return (void) (T[lst].fa = 1);
	int y = T[x].go[c];
	if (T[x].maxl + 1 == T[y].maxl)
		return (void) (T[lst].fa = y);
	int p = ++ToT; T[p] = T[y]; T[p].ri = -Abs(T[p].ri);
	T[lst].fa = T[y].fa = p;
	T[p].maxl = T[x].maxl + 1;
	for (; x && T[x].go[c] == y; x = T[x].fa)
		T[x].go[c] = p;
}

int mer(int x, int y)
{
	if (!x || !y) return x ^ y;
	int u = ++QAQ;
	tr[u].sum = tr[x].sum + tr[y].sum;
	tr[u].lc = mer(tr[x].lc, tr[y].lc);
	tr[u].rc = mer(tr[x].rc, tr[y].rc);
	return u;
}

void change(int l, int r, int pos, int v, int &p)
{
	if (!p) p = ++QAQ; tr[p].sum += v;
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, v, tr[p].lc);
	else change(mid + 1, r, pos, v, tr[p].rc);
}

int ask(int l, int r, int s, int e, int p)
{
	if (!p) return 0;
	if (l == s && r == e) return tr[p].sum;
	int mid = l + r >> 1;
	if (e <= mid) return ask(l, mid, s, e, tr[p].lc);
	else if (s > mid) return ask(mid + 1, r, s, e, tr[p].rc);
	else return ask(l, mid, s, mid, tr[p].lc)
		+ ask(mid + 1, r, mid + 1, e, tr[p].rc);
}

void dfs(int u)
{
	if (T[u].ri >= 0) change(0, n, T[u].ri, 1, rt[u]);
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		dfs(v), rt[u] = mer(rt[u], rt[v]);
}

void dp(int u, int x)
{
	if (x) f[u] = f[x] + (ask(0, n, Abs(T[u].ri) - T[u].maxl + T[x].maxl,
		Abs(T[u].ri), rt[x]) >= 2);
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		dp(v, !x || f[u] > f[x] ? u : x);
	if (f[u] > ans) ans = f[u];
}

int main()
{
	std::cin >> n;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) extend(s[i] - 'a');
	for (int u = 2; u <= ToT; u++) add_edge(T[u].fa, u);
	return std::cout << (dfs(1), dp(1, 0), ans) << std::endl, 0;
}