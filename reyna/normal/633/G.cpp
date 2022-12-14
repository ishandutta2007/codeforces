//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 1e5 + 5, M = 1005;

int read() { int x; cin >> x; return x; }

bitset<M> t[N << 2];
int st[N], ed[N], a[N], adr[N], used, n, m, add[N << 2];
bitset<M> res;
vector<int> adj[N];

void dfs(int v, int p = -1) {
	adr[used] = v;
	st[v] = used++;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);
	ed[v] = used;
}

void pull(int v, int l, int r) {
	t[v] = ((t[l] << add[v]) | (t[l] >> (m - add[v]))) | ((t[r] << add[v]) | (t[r] >> (m - add[v])));
}

void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		t[v][a[adr[b]] % m] = 1;
		return;
	}
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	build(l, b, mid);
	build(r, mid, e);
	pull(v, l, r);
}

void update(int i, int j, int x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		add[v] += x;
		add[v] %= m;
		x %= m;
		t[v] = (t[v] << x) | (t[v] >> (m - x));
		return;
	}
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	update(i, j, x, l, b, mid);
	update(i, j, x, r, mid, e);
	pull(v, l, r);
}

void query(int i, int j, int c = 0, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		c %= m;
		res |= (t[v] << c) | (t[v] >> (m - c));
		return;
	}
	c += add[v];
	c %= m;
	int mid = b + e >> 1, l = v << 1, r = l | 1;
	query(i, j, c, l, b, mid);
	query(i, j, c, r, mid, e);
}

vector<int> p;
int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	n = read(), m = read();
	rep(i, n)
		cin >> a[i];
	rep(i, n - 1) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 2; i < m; ++i) {
		bool ok = 1;
		for (int j = 2; j < i; ++j)
			if (i % j == 0)
				ok = 0;
		if (ok)
			p.push_back(i);
	}
	dfs(0);
	build();
	int q = read();
	rep(_, q) {
		int t;
		cin >> t;
		if (t == 1) {
			int v = read() - 1, x = read();
			update(st[v], ed[v], x);
		} else {
			int v = read() - 1;
			for (int x : p)
				res[x] = 0;
			query(st[v], ed[v]);
			int ans = 0;
			for (int x : p)
				ans += res[x];
			cout << ans << '\n';
		}
	}
	
}