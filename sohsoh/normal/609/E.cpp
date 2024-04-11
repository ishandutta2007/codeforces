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

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

int n, m, par[MAXN], ans[MAXN];
vector<pair<int, pll>> edges, edges2;
vector<pll> qr[MAXN];
vector<int> C[MAXN];

inline bool Union(int v, int u, int w) {
	v = par[v];
	u = par[u];
	if (v == u) return false;
	if (C[v].size() > C[u].size()) swap(v, u);
		
	for (int e : C[v]) 
		for (pll e2 : qr[e]) 
			if (par[e2.X] == u)  
				ans[e2.Y] = max(ans[e2.Y], w);
	for (int e : C[v]) {
		par[e] = u;
		C[u].push_back(e);
	}

	C[v].clear();
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i, C[i].push_back(i);

	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
		edges2.push_back({w, {u, v}});
		qr[u].push_back({v, i});
		qr[v].push_back({u, i});
	}

	sort(all(edges));
	ll mst = 0;
	for (int i = 0; i < m; i++)
		if (Union(edges[i].Y.X, edges[i].Y.Y, edges[i].X))	
			mst += edges[i].X;
	for (int i = 0; i < m; i++) cout << mst + edges2[i].X - ans[i + 1] << endl;
	return 0;
}