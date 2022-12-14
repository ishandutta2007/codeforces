//In the name of God

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

const int N = 1e5 + 5, lgN = 18;

int n, adr[N], res[N << 1], weed[N << 2], nut[N << 2], stamp, par[N][lgN], st[N], ed[N], h[N], ql1[N << 1], ql2[N << 1], qr1[N << 1], qr2[N << 1];
vector<int> proc[N], adj[N];

void give(int v, int x) {
	weed[v] += x;
	nut[v] += x;
}

void sprout(int v, int l, int r) {
	weed[v] = max(weed[l], weed[r]);
}

void absorb(int v, int l, int r) {
	give(l, nut[v]);
	give(r, nut[v]);
	nut[v] = 0;
}

void plant(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		weed[v] = h[adr[b]];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	plant(l, b, m);
	plant(r, m, e);
	sprout(v, l, r);
}

void water(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		give(v, x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	absorb(v, l, r);
	water(i, j, x, l, b, m);
	water(i, j, x, r, m, e);
	sprout(v, l, r);
}

int smoke(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return 0;
	if (i <= b && e <= j)
		return weed[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	absorb(v, l, r);
	return max(smoke(i, j, l, b, m), smoke(i, j, r, m, e));
}

void dfs_order(int v = 0, int p = 0) {
	adr[stamp] = v;
	st[v] = stamp++;
	if (v)
		h[v] = h[p] + 1;
	par[v][0] = p;
	for (int i = 1; i < lgN; ++i)
		par[v][i] = par[par[v][i - 1]][i - 1];
	for (int u : adj[v]) if (u != p)
		dfs_order(u, v);
	ed[v] = stamp;
}

int go_up(int v, int d) {
	for (int i = 0; i < lgN; ++i)
		if (d >> i & 1)
			v = par[v][i];
	return v;
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	u = go_up(u, h[u] - h[v]);
	if (u == v)
		return v;
	for (int i = lgN - 1; i >= 0; --i)
		if (par[v][i] != par[u][i])
			v = par[v][i], u = par[u][i];
	return par[v][0];
}

void getseg(int u, int v, int id) {
	if (h[u] > h[v])
		swap(u, v);
	int p;
	if (st[u] <= st[v] && st[v] < ed[u]) {
		p = go_up(v, (h[v] - h[u]) / 2);
	} else {
		int l = lca(u, v);
		int d = h[u] + h[v] - h[l] - h[l];
		p = go_up(v, d - 1 >> 1);
	}
//	cout << u << ' ' << v << ' ' << p << endl;
	int lid = id << 1, rid = lid | 1;
	ql1[lid] = st[p];
	qr1[lid] = ed[p];
	proc[v].push_back(lid);
	ql1[rid] = 0;
	qr1[rid] = st[p];
	ql2[rid] = ed[p];
	qr2[rid] = n;
	proc[u].push_back(rid);
}

void go(int v = 0, int p = 0) {
	for (int x : proc[v]) {
		smax(res[x >> 1], smoke(ql1[x], qr1[x]));
		smax(res[x >> 1], smoke(ql2[x], qr2[x]));
	}
	for (int u : adj[v]) if (u != p) {
		water(0, n, 1);
		water(st[u], ed[u], -2);
		go(u, v);
		water(st[u], ed[u], 2);
		water(0, n, -1);
	}
}

int read() { int x; cin >> x; return x; }

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read();
	for (int i = 1; i < n; ++i) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs_order();
	plant();
	int m = read();
	for (int i = 0; i < m; ++i) {
		int u = read() - 1, v = read() - 1;
		getseg(u, v, i);
	}
	go();
	for (int i = 0; i < m; ++i)
		cout << res[i] << '\n';
	
	
}