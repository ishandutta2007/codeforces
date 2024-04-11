#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

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

const int N = 55e4 + 5, M = 11e5 + 5, L = 1e7 + 5, LogN = 22;

char s[N];
int m, q, trie[N][26], top[N], totTrie, totSam, totTree, ends[N],
ecnt, nxt[M], adj[M], go[M], rt[M], fa[M][LogN];

std::vector<int> col[M];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

struct SAM
{
	int fa, maxl, go[26];
} sam[M];

struct data
{
	int col, maxv;
	
	friend inline bool operator > (data a, data b)
	{
		return a.maxv > b.maxv || (a.maxv == b.maxv && a.col < b.col);
	}
};

struct SegTree
{
	int lc, rc; data val;
} T[L];

int extend(int c, int lst)
{
	int x = lst;
	sam[lst = ++totSam].maxl = sam[x].maxl + 1;
	for (; x && !sam[x].go[c]; x = sam[x].fa)
		sam[x].go[c] = lst;
	if (!x) return sam[lst].fa = 1, lst;
	int y = sam[x].go[c];
	if (sam[x].maxl + 1 == sam[y].maxl)
		return sam[lst].fa = y, lst;
	int p; sam[p = ++totSam] = sam[y];
	sam[lst].fa = sam[y].fa = p;
	sam[p].maxl = sam[x].maxl + 1;
	for (; x && sam[x].go[c] == y; x = sam[x].fa)
		sam[x].go[c] = p;
	return lst;
}

void ins(int x)
{
	int i, n = strlen(s + 1), u = 1;
	for (int i = 1; i <= n; i++)
	{
		int c = s[i] - 'a';
		if (!trie[u][c])
			top[trie[u][c] = ++totTrie] = extend(c, top[u]);
		u = trie[u][c];
		if (x) col[top[u]].push_back(x);
		else ends[i] = top[u];
	}
}

void add(int l, int r, int pos, int &p)
{
	if (!p) p = ++totTree;
	if (l == r) return (void) (T[p].val.col = l, T[p].val.maxv++);
	int mid = l + r >> 1;
	if (pos <= mid) add(l, mid, pos, T[p].lc);
	else add(mid + 1, r, pos, T[p].rc);
	if (T[p].lc && T[p].rc) T[p].val = Max(T[T[p].lc].val, T[T[p].rc].val);
	else T[p].val = T[p].lc ? T[T[p].lc].val : T[T[p].rc].val;
}

data query(int l, int r, int s, int e, int p)
{
	if (!p) return (data) {s, 0};
	if (l == s && r == e) return T[p].val;
	int mid = l + r >> 1;
	if (e <= mid) return query(l, mid, s, e, T[p].lc);
	else if (s >= mid + 1) return query(mid + 1, r, s, e, T[p].rc);
	else return Max(query(l, mid, s, mid, T[p].lc),
		query(mid + 1, r, mid + 1, e, T[p].rc));
}

int merge_tree(int l, int r, int x, int y)
{
	if (!x || !y) return x ^ y;
	if (l == r) return T[++totTree].val.maxv = T[x].val.maxv + T[y].val.maxv,
		T[totTree].val.col = l, totTree;
	int mid = l + r >> 1, p = ++totTree;
	T[p].lc = merge_tree(l, mid, T[x].lc, T[y].lc);
	T[p].rc = merge_tree(mid + 1, r, T[x].rc, T[y].rc);
	if (T[p].lc && T[p].rc) T[p].val = Max(T[T[p].lc].val, T[T[p].rc].val);
	else T[p].val = T[p].lc ? T[T[p].lc].val : T[T[p].rc].val;
	return p;
}

void dfs(int u)
{
	int sz = col[u].size();
	for (int i = 0; i < sz; i++)
		add(1, m, col[u][i], rt[u]);
	for (int i = 0; i < 20; i++)
		fa[u][i + 1] = fa[fa[u][i]][i];
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		fa[v][0] = u, dfs(v), rt[u] = merge_tree(1, m, rt[u], rt[v]);
}

int get_substr(int l, int r)
{
	int u = ends[r];
	for (int i = 20; i >= 0; i--)
		if (sam[fa[u][i]].maxl >= r - l + 1)
			u = fa[u][i];
	return u;
}

int main()
{
	int pl, pr, l, r;
	top[totTrie = totSam = 1] = 1;
	scanf("%s", s + 1);
	ins(0);
	m = read();
	for (int i = 1; i <= m; i++)
		scanf("%s", s + 1), ins(i);
	for (int i = 2; i <= totSam; i++)
		add_edge(sam[i].fa, i);
	q = read();
	dfs(1);
	while (q--)
	{
		l = read(); r = read(); pl = read(); pr = read();
		data res = query(1, m, l, r, rt[get_substr(pl, pr)]);
		printf("%d %d\n", res.col, res.maxv);
	}
	return 0;
}