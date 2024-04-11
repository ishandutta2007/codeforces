#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
int n, m, k, q, fa[51][N], a[N], b[N], col[N], lst[N], nxt[N], e[N], c[N];
vector<int> T[1 << 20];
bool faw[51][N];
struct node {
	int c, s, t, fas;
};
vector<node> st;
void recover(const node &x) {
	faw[x.c][x.s] = 0, fa[x.c][x.t] -= (fa[x.c][x.s] = x.fas);
}

void link(int c, int u, int v) {
	int *fa = ::fa[c];
	bool *faw = ::faw[c];
	bool wu = 0, wv = 0;
	int s = u, t = v;
	while (fa[s] >= 0) wu ^= faw[s], s = fa[s];
	while (fa[t] >= 0) wv ^= faw[t], t = fa[t];
	if (s == t) return;
	if (-fa[s] > -fa[t]) swap(wu, wv), swap(s, t);
	st.push_back({c, s, t, fa[s]});
	fa[t] += fa[s], fa[s] = t, faw[s] = wu ^ wv ^ 1;
}
bool check(int c, int u, int v) {
	int *fa = ::fa[c];
	bool *faw = ::faw[c];
	bool w = 0;
	while (fa[u] >= 0) w ^= faw[u], u = fa[u];
	while (fa[v] >= 0) w ^= faw[v], v = fa[v];
	return u != v || w;
}

void insert(int u, int l, int r, int ql, int qr, int e) {
	if (l >= ql && r <= qr) {
		T[u].push_back(e);
		return;
	}
	int mid = l + r >> 1;
	if (ql <= mid) insert(u << 1, l, mid, ql, qr, e);
	if (qr > mid) insert(u << 1 | 1, mid + 1, r, ql, qr, e);
}

void dfs(int u, int l, int r) {
	int tmp = st.size();
	for (int e : T[u]) link(col[e], a[e], b[e]);
	if (l == r) {
		if (check(c[l], a[e[l]], b[e[l]])) puts("YES"), col[e[l]] = c[l];
		else puts("NO");
		if (l != q && col[e[l]]) insert(1, 1, q, l + 1, nxt[l], e[l]);
	} else {
		int mid = l + r >> 1;
		dfs(u << 1, l, mid);
		dfs(u << 1 | 1, mid + 1, r);
	}
	while (st.size() > tmp) recover(st.back()), st.pop_back();
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= m; ++i) scanf("%d%d", a + i, b + i);
	memset(fa, -1, sizeof fa);
	fill(nxt + 1, nxt + 1 + q, q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", e + i, c + i);
		if (lst[e[i]]) nxt[lst[e[i]]] = i;
		lst[e[i]] = i;
	}
	dfs(1, 1, q);
}