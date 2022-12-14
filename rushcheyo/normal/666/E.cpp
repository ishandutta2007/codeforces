#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 600005;
int n, m, q, trans[2 * N][26], fa[2 * N][20], dep[2 * N], tot = 1, lst, sz, root[2 * N], pos[N], l[N], r[N];
vector<int> qry[2 * N], g[2 * N];
pair<int, int> ans[N];
char s[N], in[N];

int extend(int p, int c) {
	if (trans[p][c]) {
		int q = trans[p][c];
		if (dep[q] == dep[p] + 1) return q;
		int nq = ++tot;
		dep[nq] = dep[p] + 1;
		fa[nq][0] = fa[q][0];
		copy(trans[q], trans[q] + 26, trans[nq]);
		fa[q][0] = nq;
		for (; p && trans[p][c] == q; p = fa[p][0])
			trans[p][c] = nq;
		return nq;
	}
	int np = ++tot;
	dep[np] = dep[p] + 1;
	for (; p && !trans[p][c]; p = fa[p][0])
		trans[p][c] = np;
	if (!p) fa[np][0] = 1;
	else {
		int q = trans[p][c];
		if (dep[q] == dep[p] + 1)
			fa[np][0] = q;
		else {
			int nq = ++tot;
			dep[nq] = dep[p] + 1;
			fa[nq][0] = fa[q][0];
			copy(trans[q], trans[q] + 26, trans[nq]);
			fa[q][0] = fa[np][0] = nq;
			for (; p && trans[p][c] == q; p = fa[p][0])
				trans[p][c] = nq;
		}
	}
	return np;
}

struct node {
	int ls, rs;
	pair<int, int> info;
} T[2 * N];

void update(int &x, int l, int r, int pos) {
	if (!x) x = ++sz;
	if (l == r) { ++T[x].info.first; T[x].info.second = -l; return; }
	int mid = (l + r) / 2;
	if (pos <= mid) update(T[x].ls, l, mid, pos);
	else update(T[x].rs, mid + 1, r, pos);
	T[x].info = max(T[T[x].ls].info, T[T[x].rs].info);
}
int merge(int x, int y) {
	if (!x || !y) return x ^ y;
	if (!T[x].ls && !T[x].rs)
		T[x].info.first += T[y].info.first;
	else {
		T[x].ls = merge(T[x].ls, T[y].ls);
		T[x].rs = merge(T[x].rs, T[y].rs);
		T[x].info = max(T[T[x].ls].info, T[T[x].rs].info);
	}
	return x;
}
pair<int, int> query(int x, int l, int r, int ql, int qr) {
	if (!x || (l >= ql && r <= qr)) return T[x].info;
	int mid = (l + r) / 2;
	pair<int, int> res(0, 0);
	if (ql <= mid) res = max(res, query(T[x].ls, l, mid, ql, qr));
	if (qr > mid) res = max(res, query(T[x].rs, mid + 1, r, ql, qr));
	return res;
}

void dfs(int u) {
	for (int v : g[u]) {
		dfs(v);
		root[u] = merge(root[u], root[v]);
	}
	for (int x : qry[u]) ans[x] = query(root[u], 1, m, l[x], r[x]);
}

int main() {
	scanf("%s", in + 1);
	n = strlen(in + 1);
	lst = 1;
	for (int j = n; j; --j)
		pos[j] = lst = extend(lst, in[j] - 'a');
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%s", in);
		n = strlen(in);
		lst = 1;
		for (int j = n - 1; j >= 0; --j) {
			lst = extend(lst, in[j] - 'a');
			update(root[lst], 1, m, i);
		}
	}
	for (int j = 1; j <= 19; ++j)
		for (int i = 1; i <= tot; ++i)
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
	scanf("%d", &q);
	for (int i = 1, pl, pr; i <= q; ++i) {
		scanf("%d%d%d%d", l + i, r + i, &pl, &pr);
		int x = pos[pl];
		for (int j = 19; j >= 0; --j)
			if (fa[x][j] && dep[fa[x][j]] >= pr - pl + 1)
				x = fa[x][j];
		qry[x].push_back(i);
	}
	for (int i = 2; i <= tot; ++i)
		g[fa[i][0]].push_back(i);
	dfs(1);
	for (int i = 1; i <= q; ++i) {
		if (ans[i].first == 0) ans[i].second = -l[i];
		printf("%d %d\n", -ans[i].second, ans[i].first);
	}
	return 0;
}