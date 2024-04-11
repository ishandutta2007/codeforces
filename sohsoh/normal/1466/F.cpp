#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

int n, m, tmp;
vector<pll> edges;
vector<int> C[MAXN];
int par[MAXN];

inline void Union(int v, int u) {
	v = par[v];
	u = par[u];
	if (C[v].size() > C[u].size()) swap(u, v);
	for (int e : C[v]) {
		par[e] = u;
	       	C[u].push_back(e);	
	}

	C[v].clear();
	tmp--;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	tmp = m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k == 1) {
			int x;
			cin >> x;
			edges.push_back({0, x});
		} else {
			int u, v;
			cin >> u >> v;
			edges.push_back({u, v});
		}
	}

	for (int i = 0; i <= m; i++) par[i] = i, C[i].push_back(i);
	vector<int> ans;
	for (int ind = 0; ind < edges.size(); ind++) {
		int u = edges[ind].X, v = edges[ind].Y;
		if (par[u] == par[v]) continue;
		ans.push_back(ind + 1);
		Union(u, v);
	}
	
	cout << poww(2, m - tmp, MOD) << sep << ans.size() << endl;
	for (int e : ans) {
		cout << e << sep;
	}

	cout << endl;
	return 0;
}