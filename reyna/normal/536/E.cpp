//In the name of God

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, pair<int, int>> data;
#define suf second.first
#define pre second.second
#define ans first.first
#define size first.second

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

const int N = 1e5 + 5;

int read() { int x; cin >> x; return x; }




int root[N], n, qorder[N], qu[N], qv[N], ql[N], f[N], eu[N], ev[N], ew[N], pos[N], h[N], heavy[N], par[N], eorder[N];
vector<int> adj[N];
data weed[N << 2];
bool qcmp(int a, int b) { return ql[a] > ql[b]; }
bool ecmp(int a, int b) { return ew[a] > ew[b]; }

data merge(data x, data y) {
	return {{x.ans + y.ans - f[x.suf] - f[y.pre] + f[x.suf + y.pre], x.size + y.size}, {y.suf == y.size? y.suf + x.suf: y.suf, x.pre == x.size? x.pre + y.pre: x.pre}};
}

void plant(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		weed[v] = {{0, 1}, {0, 0}};
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	plant(l, b, m);
	plant(r, m, e);
	weed[v] = merge(weed[l], weed[r]);
}

void water(int p, int x, int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		weed[v] = {{f[x], 1}, {x, x}};
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	if (p < m)
		water(p, x, l, b, m);
	else
		water(p, x, r, m, e);
	weed[v] = merge(weed[l], weed[r]);
}

data smoke(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return {{0, 0}, {0, 0}};
	if (i <= b && e <= j)
		return weed[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	return merge(smoke(i, j, l, b, m), smoke(i, j, r, m, e));
}

void add_edge(int e) {
	int u = eu[e], v = ev[e];
//	cout << p << endl;
	if (h[u] < h[v])
		swap(u, v);
	water(pos[u], 1);
}

int dfs_build(int v = 0, int p = -1) {
	par[v] = p;
	if (v)
		h[v] = h[p] + 1;
	int sz = 1, maxsz = 0;
	for (int u : adj[v]) if (u != p) {
		int chsz = dfs_build(u, v);
		sz += chsz;
		if (maxsz < chsz)
			maxsz = chsz, heavy[v] = u;
	}
	return sz;
}

data rev(data x) {
	swap(x.suf, x.pre);
	return x;
}

void build_hld() {
	int stamp = 0;
	for (int v = 0; v < n; ++v) {
		if (par[v] == -1 || heavy[par[v]] != v) {
			for (int u = v; ~u; u = heavy[u])
				pos[u] = stamp++, root[u] = v;
		}
	}
	plant();
}

data getpath(int u, int v) {
	data ud = {{0, 0}, {0, 0}}, vd = {{0, 0}, {0, 0}};
	while (root[u] != root[v]) {
		if (h[root[u]] > h[root[v]]) {
			ud = merge(ud, rev(smoke(pos[root[u]], pos[u] + 1)));
			u = par[root[u]];
		} else {
			vd = merge((smoke(pos[root[v]], pos[v] + 1)), vd);
			v = par[root[v]];
		}
	}
//	cout << u << ' ' << v << ' ' << pos[u] << ' ' << pos[v] << endl;
	if (h[u] > h[v]) {
		ud = merge(ud, rev(smoke(pos[v] + 1, pos[u] + 1)));
	} else {
		vd = merge((smoke(pos[u] + 1, pos[v] + 1)), vd);
	}
	return merge((ud), (vd));
}

int res[N];

int main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(heavy, -1, sizeof heavy);
	n = read();
	int q = read();
	for (int i = 1; i < n; ++i)
		f[i] = read();
	for (int i = 0; i < n - 1; ++i) {
		eu[i] = read() - 1;
		ev[i] = read() - 1;
		ew[i] = read();
		eorder[i] = i;
		adj[eu[i]].push_back(ev[i]);
		adj[ev[i]].push_back(eu[i]);
	}
	for (int i = 0; i < q; ++i) {
		qu[i] = read() - 1;
		qv[i] = read() - 1;
		ql[i] = read();
		qorder[i] = i;
	}
	dfs_build();
	build_hld();
	int pt = 0;
	sort(eorder, eorder + n - 1, ecmp);
	sort(qorder, qorder + q, qcmp);
	for (int _ = 0; _ < q; ++_) {
		int i = qorder[_];
		while (pt < n - 1 && ew[eorder[pt]] >= ql[i])
			add_edge(eorder[pt++]);
//		cout << i << ' ' << pt << endl;
		res[i] = getpath(qu[i], qv[i]).ans;
	}
	for (int i = 0; i < q; ++i)
		cout << res[i] << '\n';
	
	
}