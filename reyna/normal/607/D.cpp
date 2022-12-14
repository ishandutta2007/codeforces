//In the name of God

#include <bits/stdc++.h>

using namespace std;


typedef long long int49;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


constexpr int N = 2e5 + 5;
constexpr int mod = 1e9 + 7;

int pw(int a, int b) {
	return b? pw(a * 1LL * a % mod, b >> 1) * 1LL * (b & 1? a: 1) % mod: 1;	
}

int read() { int x; cin >> x; return x; }

int49 fen[N], lval[N], val[N], ch[N << 2], sum[N << 2], z[N << 2], inv[N], vni[N];
int st[N], ed[N], tot, deg[N], par[N], adr[N], n = 1;
pii ask[N];
vector<int> adj[N];

int49 fenq(int m, int res = 1) { m++;
	while (m < N)
		res = res * 1LL * fen[m] % mod, m += m & -m;
	return res;
}

void fenu(int m, int x) { m++;
	while (m > 0)
		fen[m] = fen[m] * x % mod, m -= m & -m;
}

void dfs(int v) {
	adr[tot] = v;
	val[tot] = lval[v];
	st[v] = tot++;
	for (int u : adj[v])
		dfs(u);
	ed[v] = tot;
}

void pull(int v, int l, int r) {
	z[v] = (z[l] + z[r]) % mod;
	sum[v] = (sum[l] + sum[r]) % mod;
}


void build(int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		sum[v] = 0;
		z[v] = val[b];
		return;
	}
	int m = (b + e) >> 1, l = v << 1, r = l | 1;
	build(l, b, m);
	build(r, m, e);
	pull(v, l, r);
}

void add(int v, int49 x) {
	ch[v] = ch[v] * x % mod;
	sum[v] = sum[v] * x % mod;
	z[v] = z[v] * x % mod;
}

void push(int v, int l, int r) {
	add(l, ch[v]);
	add(r, ch[v]);
	ch[v] = 1;	
}

void do_count(int pos, int v = 1, int b = 0, int e = n) {
	if (b + 1 == e) {
		sum[v] = z[v];
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, l, r);
	if (pos < m)
		do_count(pos, l, b, m);
	else
		do_count(pos, r, m, e);
	pull(v, l, r);
}

void update(int i, int j, int49 x, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return;
	if (i <= b && e <= j) {
		add(v, x);
		return;
	}
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, l, r);
	update(i, j, x, l, b, m);
	update(i, j, x, r, m, e);
	pull(v, l, r);
}

int49 query(int i, int j, int v = 1, int b = 0, int e = n) {
	if (i >= e || b >= j)
		return 0;
	if (i <= b && e <= j)
		return sum[v];
	int m = b + e >> 1, l = v << 1, r = l | 1;
	push(v, l, r);
	return (query(i, j, l, b, m) + query(i, j, r, m, e)) % mod; 	
}

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fill(fen, fen + N, 1);
	fill(ch, ch + N * 4, 1);
	fill(deg, deg + N, 1);
	lval[0] = read();
	for (int i = 1; i < N; ++i)
		inv[i] = pw(i, mod - 2), vni[i] = pw(inv[i], mod - 2);
	int q = read(), m = 0;
	while (q--) {
		int c = read();
		if (c == 1) {
			par[n] = read() - 1;
			lval[n] = read();
			adj[par[n]].push_back(n);
			++n;
		} else {
			ask[m++] = {read() - 1, n};
		}
	}
	dfs(0);
	build();
	do_count(0);
	int pt = 1;
	for (int i = 0; i < m; ++i) {
		int v = ask[i].first, till = ask[i].second;
		while (pt < till) {
			int u = pt, p = par[pt], &d = deg[p];
			do_count(st[u]);
			fenu(ed[p] - 1, inv[d]);
			fenu(ed[p] - 1, d + 1);
			fenu(st[p] - 1, d);
			fenu(st[p] - 1, inv[d + 1]);
//			cout << p << ' ' << ed[p] - 1 << ' ' << st[p] - 1 << ' ' << inv[d] << ' ' << d + 1 << ' ' << d << ' ' << inv[d + 1] << endl;
			update(st[p], ed[p], inv[d]);
			update(st[p], ed[p], d + 1);
			deg[p]++;
			pt++;
		}
//		cout << query(1, 2) << endl;
		cout << query(st[v], ed[v]) * (v? pw(fenq(st[par[v]]), mod - 2) % mod: 1) % mod<< '\n';
	}
//	for (int i = 0; i < n; ++i)
//		cout << i << ' ' << fenq(st[i]) << endl;
}