#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 200005, Q = 500005;
int n, q, trans[2 * N][26], fail[2 * N], dep[2 * N], tot = 1, lst = 1, sz, root[2 * N], pos[N], l[Q], r[Q], k[Q];
ll ans[Q];
vector<int> qry[2 * N], g[2 * N];
char in[N];

int extend(int p, int c) {
	if (trans[p][c]) {
		int q = trans[p][c];
		if (dep[q] == dep[p] + 1) return q;
		int nq = ++tot;
		dep[nq] = dep[p] + 1;
		fail[nq] = fail[q];
		copy(trans[q], trans[q] + 26, trans[nq]);
		fail[q] = nq;
		for (; p && trans[p][c] == q; p = fail[p])
			trans[p][c] = nq;
		return nq;
	}
	int np = ++tot;
	dep[np] = dep[p] + 1;
	for (; p && !trans[p][c]; p = fail[p])
		trans[p][c] = np;
	if (!p) fail[np] = 1;
	else {
		int q = trans[p][c];
		if (dep[q] == dep[p] + 1)
			fail[np] = q;
		else {
			int nq = ++tot;
			dep[nq] = dep[p] + 1;
			fail[nq] = fail[q];
			copy(trans[q], trans[q] + 26, trans[nq]);
			fail[q] = fail[np] = nq;
			for (; p && trans[p][c] == q; p = fail[p])
				trans[p][c] = nq;
		}
	}
	return np;
}

struct node {
	int ls, rs;
	ll size;
} T[N * 19];

void update(int &x, int l, int r, int pos) {
	if (!x) x = ++sz;
	++T[x].size;
	if (l == r) return;
	int mid = (l + r) / 2;
	if (pos <= mid) update(T[x].ls, l, mid, pos);
	else update(T[x].rs, mid + 1, r, pos);
}
int merge(int x, int y) {
	if (!x || !y) return x ^ y;
	T[x].size += T[y].size;
	T[x].ls = merge(T[x].ls, T[y].ls);
	T[x].rs = merge(T[x].rs, T[y].rs);
	return x;
}
ll query(int x, int l, int r, int ql, int qr) {
	if (!x || l >= ql && r <= qr) return T[x].size;
	int mid = (l + r) / 2, res = 0;
	if (ql <= mid) res += query(T[x].ls, l, mid, ql, qr);
	if (qr > mid) res += query(T[x].rs, mid + 1, r, ql, qr);
	return res;
}

void dfs(int u) {
	for (int v : g[u]) {
		dfs(v);
		root[u] = merge(root[u], root[v]);
	}
	for (int x : qry[u]) ans[x] = query(root[u], 1, n, l[x], r[x]);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", in);
		lst = 1;
		for (int j = 0; in[j]; ++j) {
			lst = extend(lst, in[j] - 'a');
			update(root[lst], 1, n, i);
		}
		pos[i] = lst;
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d%d", l + i, r + i, k + i);
		qry[pos[k[i]]].push_back(i);
	}
	for (int i = 2; i <= tot; ++i)
		g[fail[i]].push_back(i);
	dfs(1);
	for (int i = 1; i <= q; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}