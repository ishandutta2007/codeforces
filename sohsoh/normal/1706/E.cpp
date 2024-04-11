#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, sg[MAXN << 2], m, q, f[MAXN], par[MAXN];
vector<int> C[MAXN];

inline void unite(int u, int v, int k) {
	u = par[u], v = par[v];
	if (u == v) return;
	if (C[u].size() < C[v].size()) swap(u, v);

	for (int e : C[v]) {
		if (par[e - 1] == u) f[e - 1] = k;
		if (par[e + 1] == u) f[e] = k;
	}

	for (int e : C[v]) {
		par[e] = u;
		C[u].push_back(e);
	}

	C[v].clear();
}

void build(int l = 1, int r = n - 1, int v = 1) {
	if (l == r) sg[v] = f[l];
	else {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
		sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
	}
}

int query(int ql, int qr, int l = 1, int r = n - 1, int v = 1) {
	if (ql > r || qr < l) return 0;
	if (ql <= l && qr >= r) return sg[v];

	int mid = (l + r) >> 1;
	return max(query(ql, qr, l, mid, v << 1),
			 query(ql, qr, mid + 1, r, v << 1 | 1));
}

inline void solve() {
	for (int i = 0; i < n + 10; i++)
		par[i] = 0, C[i].clear();

	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		C[i].push_back(i);
	}

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		unite(u, v, i);
	}

	build();
	
	for (int i = 1; i <= q; i++) {
		int l, r;
		cin >> l >> r;
		cout << (r <= l ? 0 : query(l, r - 1)) << sep;
	}

	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}