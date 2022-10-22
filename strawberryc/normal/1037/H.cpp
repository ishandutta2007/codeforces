#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2e5 + 5, M = 1e7 + 5;

int n, q, m, lst, ToT, ecnt, nxt[N], adj[N], go[N], inx[N], rt[N], QAQ, pt[N];
char s[N], t[N], ans;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

struct sam
{
	int fa, go[26], maxl;
	
	void init()
	{
		memset(go, 0, sizeof(go));
		fa = maxl = 0;
	}
} T[N];

struct node
{
	int lc, rc, ri;
} Tr[M];

int extend(int c)
{
	int u = lst; T[lst = ++ToT].init();
	T[lst].maxl = T[u].maxl + 1;
	for (; u && !T[u].go[c]; u = T[u].fa)
		T[u].go[c] = lst;
	if (!u) return T[lst].fa = 1, lst;
	int v = T[u].go[c];
	if (T[u].maxl + 1 == T[v].maxl)
		return T[lst].fa = v, lst;
	int p = ++ToT; T[p] = T[v];
	T[lst].fa = T[v].fa = p;
	T[p].maxl = T[u].maxl + 1;
	for (; u && T[u].go[c] == v; u = T[u].fa)
		T[u].go[c] = p;
	return lst;
}

void change(int l, int r, int pos, int &p)
{
	if (!p) p = ++QAQ;
	Tr[p].ri = Max(Tr[p].ri, pos);
	if (l == r) return;
	int mid = l + r >> 1;
	if (pos <= mid) change(l, mid, pos, Tr[p].lc);
	else change(mid + 1, r, pos, Tr[p].rc);
}

int ask(int l, int r, int pos, int p)
{
	if (!p) return 0;
	if (l == r) return l;
	int mid = l + r >> 1, tmp;
	if (pos <= mid) return ask(l, mid, pos, Tr[p].lc);
	tmp = ask(mid + 1, r, pos, Tr[p].rc);
	return tmp ? tmp : Tr[Tr[p].lc].ri;
}

int mer(int u, int v)
{
	if (!u || !v) return u + v;
	int p = ++QAQ;
	Tr[p].ri = Max(Tr[u].ri, Tr[v].ri);
	Tr[p].lc = mer(Tr[u].lc, Tr[v].lc);
	Tr[p].rc = mer(Tr[u].rc, Tr[v].rc);
	return p;
}

void dfs(int u)
{
	if (inx[u]) change(1, n, inx[u], rt[u]);
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		dfs(v), rt[u] = mer(rt[u], rt[v]);
}

bool check(int u, int len, int l, int r)
{
	return ask(1, n, r, rt[u]) >= l + len - 1;
}

int query(int l, int r)
{
	int u = 1; pt[0] = 1;
	for (int i = 1; i <= m; i++)
	{
		int c = t[i] - 'a';
		u = T[u].go[c];
		pt[i] = u;
	}
	for (int i = m; i >= 0; i--) if (pt[i])
	{
		int u = pt[i];
		for (int c = t[i + 1] - 'a' + 1; c < 26; c++)
			if (T[u].go[c] && check(T[u].go[c], i + 1, l, r))
				return ans = c + 'a', i;
	}
	return -1;
}

int main()
{
	T[lst = ToT = 1].init();
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++) inx[extend(s[i] - 'a')] = i;
	for (int u = 2; u <= ToT; u++) add_edge(T[u].fa, u);
	dfs(1);
	q = read();
	int l, r;
	while (q--)
	{
		l = read(); r = read();
		scanf("%s", t + 1);
		m = strlen(t + 1);
		t[m + 1] = 'a' - 1;
		int res = query(l, r);
		if (res == -1) puts("-1");
		else for (int i = 1; i <= res + 2; i++)
			putchar(i <= res ? t[i] : (i == res + 1 ? ans : '\n'));
	}
	return 0;
}