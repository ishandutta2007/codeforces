#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e5 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 20;

int n, q, par[MAXN][LOG], T, tin[MAXN], tout[MAXN], root = 1, D[MAXN], A[MAXN];
ll sg[6 * MAXN], lz[6 * MAXN];
vector<int> adj[MAXN];

inline void Push(int v, int L, int R) {
	sg[v] += lz[v] * (R - L + 1);
	lz[v << 1] += lz[v];
	lz[v << 1 | 1] += lz[v];
	lz[v] = 0;
}

void Update(int v, int L, int R, int ql, int qr, int val) {
	Push(v, L, R);
	if (qr < ql) return;
	if (ql == L && qr == R) {
		lz[v] += val;
		Push(v, L, R);
		return;
	}

	int mid = (L + R) >> 1;
	Update(v << 1, L, mid, ql, min(qr, mid), val);
	Update(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr, val);
	sg[v] = sg[v << 1] + sg[v << 1 | 1];
}

ll Query(int v, int L, int R, int ql, int qr) {
	Push(v, L, R);
	if (qr < ql) return 0;
	if (ql == L && qr == R) return sg[v];
	
	int mid = (L + R) >> 1;
	return Query(v << 1, L, mid, ql, min(qr, mid)) + Query(v << 1 | 1, mid + 1, R, max(ql, mid + 1), qr);
}

void dfs(int v, int p) {
	T++;
	D[v] = D[p] + 1;
	par[v][0] = p;
	for (int i = 1; i < LOG; i++) 
		par[v][i] = par[par[v][i - 1]][i - 1];
	tin[v] = T;
	for (int u : adj[v]) 
		if (u != p)
			dfs(u, v);
	tout[v] = T;
}

bool is_anc(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int kth_par(int v, int k) {
	int j = 0;
	while (k) {
		if (k & 1) v = par[v][j];
		j++;
		k >>= 1;
	}

	return v;
}

int LCA(int u, int v) {
	if (is_anc(u, v)) return u;
	if (is_anc(v, u)) return v;

	for (int i = LOG - 1; i >= 0; i--)
		if (!is_anc(par[u][i], v))
			u = par[u][i];
	
	return par[u][0];
}

int LCA(int u, int v, int root) {
	bool b1 = is_anc(root, v), b2 = is_anc(root, u);
	if (b1 & b2) return LCA(u, v);
	else if (b1 ^ b2) return root;
	
	int t1 = LCA(u, v), t2 = LCA(root, v), t3 = LCA(root, u);
	if (D[t1] >= D[t2] && D[t1] >= D[t3]) return t1;
	else if (D[t2] >= D[t1] && D[t2] >= D[t3]) return t2;
	else return t3;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	tin[0] = -INF, tout[0] = INF;
	
	for (int i = 1; i <= n; i++) cin >> A[i];	

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++) Update(1, 1, n, tin[i], tin[i], A[i]);
		
	while (q--) {
		int c;
		cin >> c;
		if (c == 1) cin >> root;
		else if (c == 2) {
			int u, v, x;
			cin >> u >> v >> x;
			int lca = LCA(u, v, root);
			if (lca == root) Update(1, 1, n, 1, n, x);
			else if (!is_anc(lca, root)) Update(1, 1, n, tin[lca], tout[lca], x);
			else {
				int t = kth_par(root, D[root] - D[lca] - 1);
				Update(1, 1, n, 1, n, x);
				Update(1, 1, n, tin[t], tout[t], -x);
			}	

		} else {
			int v;
			cin >> v;
			if (v == root) cout << Query(1, 1, n, 1, n) << endl;
			else if (!is_anc(v, root)) cout << Query(1, 1, n, tin[v], tout[v]) << endl;
			else {
				int t = kth_par(root, D[root] - D[v] - 1);
				cout << Query(1, 1, n, 1, n) - Query(1, 1, n, tin[t], tout[t]) << endl;
			}
		}
	}

	return 0;
}