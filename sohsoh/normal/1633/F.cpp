#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int sz[MAXN], hv[MAXN], n, head[MAXN], par[MAXN], id[MAXN], t, t_sz[MAXN], par_id[MAXN];
vector<pll> adj[MAXN];
pair<pll, pll> sg[MAXN];
bool lz[MAXN], B[MAXN];
vector<int> ans_vec;

int dfs_sz(int v, int p) {
	sz[v] = 1;
	par[v] = p;
	for (auto [u, ind] : adj[v]) {
		if (u == p) continue;
		
		par_id[u] = ind;
		sz[v] += dfs_sz(u, v);
		if (sz[u] > sz[hv[v]])
			hv[v] = u;
	}

	return sz[v];
}

void hld(int v, int p) {
	id[v] = ++t;
	if (!head[v]) head[v] = v;

	if (hv[v]) {
		head[hv[v]] = head[v];
		hld(hv[v], v);
	}

	for (auto [u, ind] : adj[v])
		if (u != hv[v] && u != p)
			hld(u, v);
}

inline void push(int v) {
	if (lz[v]) {
		swap(sg[v].X, sg[v].Y);
		if ((v << 1 | 1) < MAXN)
			lz[v << 1] ^= 1, lz[v << 1 | 1] ^= 1;
		lz[v] = false;
	}
}

template<typename T>
inline pair<T, T> operator+ (const pair<T, T>& a, const pair<T, T>& b) {
	return {a.X + b.X, a.Y + b.Y};
}

void add(int ind, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (l == r) sg[v] = {{0, 0}, {1, val}};
	else {
		int mid = (l + r) >> 1;
		if (ind <= mid) add(ind, val, l, mid, v << 1), push(v << 1 | 1);
		else add(ind, val, mid + 1, r, v << 1 | 1), push(v << 1);
		sg[v] = sg[v << 1] + sg[v << 1 | 1];
	}
}

void update(int ql, int qr, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] ^= 1;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, l, mid, v << 1);
	update(ql, qr, mid + 1, r, v << 1 | 1);
	sg[v] = sg[v << 1] + sg[v << 1 | 1];
}

int dfs(int v, int p) {
	t_sz[v] = B[v];
	for (auto [u, ind] : adj[v])
		if (u != p && B[u])
			t_sz[v] += dfs(u, v);
	if (t_sz[v] & 1) {
		ans_vec.push_back(par_id[v]);
	}
	return t_sz[v];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	dfs_sz(1, 0);
	hld(1, 0);

	B[1] = true;
	add(1, 0);
	while (true) {
		int c;
		cin >> c;
		if (c == 3 || c == 0) break;
	
		if (c == 1) {
			int v;
			cin >> v;
			B[v] = true;
			add(id[v], par_id[v]);

			v = par[v];
			while (v) {
				update(id[head[v]], id[v]);
				v = par[head[v]];
			}

			if (sg[1].X.X != sg[1].Y.X) cout << 0 << endl;
			else cout << sg[1].Y.Y << endl;
		} else {
			if (sg[1].X.X != sg[1].Y.X) cout << 0 << endl;
			else {
				ans_vec.clear();
				dfs(1, 0);
				sort(all(ans_vec));
				
				cout << ans_vec.size() << sep;
				for (int e : ans_vec)
					cout << e << sep;
				cout << endl;
			}
		}
	}
	return 0;
}