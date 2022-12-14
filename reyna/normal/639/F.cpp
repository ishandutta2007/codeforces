//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e6 + 6, lg = 20;

int lastn, n, ss[N], tt[N], anc[N][lg], m, query_count, h[N], comp[N], used, mark[N], cut[N], st[N], ed[N], stamp, q[N], t, top, stk[N], dsu_comp[N], dsu[N], up[N], d[N], upmost[N];
vector<int> g[N];

int read() { int x; cin >> x; return x; }

int ycnt = 0;
int rotate(int &x) {
	x += ycnt;
	x %= lastn;
	if (!x)
		x = lastn;
	x--;
}

int find(int v, int *par) { return v == par[v]? v: par[v] = find(par[v], par); }
void unite(int u, int v, int *par, bool is = 0) { 
	u = find(u, par);
	v = find(v, par);
	if (is && d[u] > d[v])
		swap(u, v);
	par[v] = u;
} 

int dfs1(int v, int ep = -1) {
	if (mark[v]++)
		return h[v];
	int res = h[v];
	for (int e : g[v]) if (e != ep) {
		int u = ss[e] + tt[e] - v;
		if (h[u] == -1)
			h[u] = h[v] + 1;
		res = min(res, dfs1(u, e));
	}
//	cout << v << ' ' << h[v] << ' ' << res << endl;
	if (res == h[v] && ep != -1) {
		cut[ep] = 1;
	}
	return res;
}

void dfs2(int v, int cc) {
	if (mark[v]++)
		return;
	comp[v] = cc;
//	cout << v << " :D " << cc << endl;
	for (int e : g[v]) if (!cut[e]) {
		int u = ss[e] + tt[e] - v;
//		cout << v << " -> " << u << '\n';
		dfs2(u, cc);
	}
}

void dfs_lca(int v, int p) {
	if (p != v)
		h[v] = h[p] + 1;
	else
		h[v] = 0;
	st[v] = stamp++;
	anc[v][0] = p;
	for (int i = 1; i < lg; ++i)
		anc[v][i] = anc[anc[v][i - 1]][i - 1];
	for (int u : g[v]) if (u != p) {
		dfs_lca(u, v);
	}
	ed[v] = stamp;
}

void dfs4(int v, int p = -1) {
	mark[v] = 1;
//	cout << v << ' ' << p << endl;
	for (int u : g[v]) if (u != p) {
		d[u] = d[v] + 1;
		up[u] = v;
		dfs4(u, v);
	}
}

int lca(int u, int v) {
	if (h[u] < h[v])
		swap(u, v);
	rep(i, lg)
		if ((h[u] - h[v]) >> i & 1)
			u = anc[u][i];
	if (u == v)
		return v;
	for (int i = lg - 1; i >= 0; --i)
		if (anc[v][i] != anc[u][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0] == anc[v][0]? anc[v][0]: -1;
}


bool ispar(int p, int v) { return (st[p] <= st[v]) && (st[v] < ed[p]); }
int cmp(int x, int y) { return st[x] < st[y]; }

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(anc, -1, sizeof anc);
	memset(h, -1, sizeof h);
	rep(i, N)
		dsu_comp[i] = i;
	n = read();
	lastn = n;
	m = read();
	query_count = read();
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
		g[u].push_back(i);
		g[v].push_back(i);
		ss[i] = u;
		tt[i] = v;
	}
	rep(v, n) if (!mark[v]) {
		h[v] = 0;
		dfs1(v);
	}
	memset(mark, 0, sizeof mark);
	rep(v, n) if (!mark[v]) {
		dfs2(v, used);
		used++;
	} 
//	return 0;
//	cout << '\n';
	rep(v, n) {
//		cout << v << ' ' << comp[v] << '\n';
		g[v].clear();
	}
	rep(e, m) {
		int u = ss[e], v = tt[e];
		u = comp[u];
		v = comp[v];
		if (u != v) {
			unite(u, v, dsu_comp);
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	n = used; used = 0;
	memset(h, 0, sizeof h);
	rep(v, n) if (anc[v][0] == -1) {
		dfs_lca(v, v);
	}
	rep(v, n)
		g[v].clear();
//	return 0;
//	ycnt++;
	rep(qq, query_count) {
		t = 0;
		int ni = read(), mi = read();
		vector<int> imp, fav;
		vector<pair<int, int>> query, edges;
		rep(i, ni) {
			int v = read();
			rotate(v);
			v = comp[v];
			q[t++] = v;
			fav.push_back(v);
		}
		rep(i, mi) {
			int u = read(), v = read();
			rotate(u);
			rotate(v);
			u = comp[u];
			v = comp[v];
			edges.push_back({u, v});
			q[t++] = u;
			q[t++] = v;
		}
		sort(q, q + t);
		t = unique(q, q + t) - q;
		sort(q, q + t, cmp);
		int sz = t;
		rep(i, sz - 1) if (lca(q[i], q[i + 1]) != -1)
			q[t++] = lca(q[i], q[i + 1]);
		sort(q, q + t);
		t = unique(q, q + t) - q;
		sort(q, q + t, cmp);
		top = 0;
		rep(i, t) {
			int v = q[i];
			while (top > 0 && !ispar(stk[top - 1], v))
				top--;
			if (top)
				g[stk[top - 1]].push_back(v), g[v].push_back(stk[top - 1]);
			stk[top++] = v;
		}
		rep(i, t)
			dsu[find(q[i], dsu_comp)] = find(q[i], dsu_comp);
		
		for (auto e : edges) {
			int u = find(e.first, dsu_comp), v = find(e.second, dsu_comp);
			if (find(u, dsu) == find(v, dsu))
				query.push_back({e.first, e.second});
			else
				unite(u, v, dsu), g[e.first].push_back(e.second), g[e.second].push_back(e.first);
		}
		rep(i, t)
			mark[q[i]] = 0, upmost[q[i]] = q[i];
		rep(i, t) {
			int v = q[i];
			if (!mark[v]) {
				dfs4(v);
			}
		}
		rep(i, t)
			g[q[i]].clear();
		for (auto e : query) {
			int u = e.first, v = e.second;
//			cout << u << ' ' << v << endl;
			while (u != v) {
				u = find(u, upmost);
				v = find(v, upmost);
				if (u == v)
					break;
				if (d[u] > d[v])
					swap(u, v);
				unite(v, up[v], upmost, 1);
				v = find(v, upmost);
			}
		}
		int flag = 0;
		for (int i = 1; i < (int) fav.size(); ++i) {
			int u = fav[i - 1], v = fav[i];
			if (find(u, upmost) != find(v, upmost)) {
				cout << "NO\n";
				flag = 1;
				break;
			}
		}
		if (flag)
			continue;
		cout << "YES\n";
		ycnt += qq + 1; ycnt %= lastn;
	}
}
/*
6 5 1
1 2
2 3
3 4
2 4
5 6
3 2
6 3 4
2 5
4 6




2 1
6 2
3 4
*/