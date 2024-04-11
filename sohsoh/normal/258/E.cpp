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

int n, m, tin[MAXN], tout[MAXN], t, ans[MAXN], tin_r[MAXN];
vector<int> adj[MAXN], R[MAXN], L[MAXN];
pair<pll, pll> P[MAXN];
pll sg[MAXN];
int lz[MAXN];

void dfs(int v, int p) {
	tin[v] = ++t;
	tin_r[t] = v;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);

	tout[v] = t;
}

void build(int l = 1, int r = n, int v = 1) {
	sg[v] = {0, r - l + 1};
	if (l != r) {
		int mid = (l + r) >> 1;
		build(l, mid, v << 1);
		build(mid + 1, r, v << 1 | 1);
	}
}

inline void push(int v) {
	sg[v].X += lz[v];
	lz[v << 1] += lz[v];
	lz[v << 1 | 1] += lz[v];
	lz[v] = 0;
}

void update(int ql, int qr, int val, int l = 1, int r = n, int v = 1) {
	push(v);
	if (ql > r || qr < l) return;
	if (ql <= l && qr >= r) {
		lz[v] += val;
		push(v);
		return;
	}

	int mid = (l + r) >> 1;
	update(ql, qr, val, l, mid, v << 1);
	update(ql, qr, val, mid + 1, r, v << 1 | 1);

	if (sg[v << 1].X == sg[v << 1 | 1].X) sg[v] = {sg[v << 1].X, sg[v << 1].Y + sg[v << 1 | 1].Y};
	else sg[v] = min(sg[v << 1], sg[v << 1 | 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int v, u;
		cin >> v >> u;
		P[i] = {{tin[v], tout[v]}, {tin[u], tout[u]}};
		L[tin[v]].push_back(i);
		L[tin[u]].push_back(i);
		R[tout[v]].push_back(i);
		R[tout[u]].push_back(i);
	}

	build();
	for (int i = 1; i <= n; i++) {
		for (int ind : L[i]) {
			update(P[ind].X.X, P[ind].X.Y, 1);
			update(P[ind].Y.X, P[ind].Y.Y, 1);
		}

		if (sg[1].X) ans[tin_r[i]] = n - 1;
		else ans[tin_r[i]] = max(n - sg[1].Y - 1, 0ll);

		for (int ind : R[i]) {
			update(P[ind].X.X, P[ind].X.Y, -1);
			update(P[ind].Y.X, P[ind].Y.Y, -1);
		}
	}

	for (int i = 1; i <= n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}