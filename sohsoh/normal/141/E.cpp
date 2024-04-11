#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

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

int n, m, E, ES, EM, C_par[MAXN], rt, parpar[MAXN], C, par[MAXN], H[MAXN];
vector<pair<int, char>> adj[MAXN];
vector<pair<pair<int, int>, char>> edges;
bool vis[MAXN];
map<pair<pair<int, int>, char>, int> mp;
vector<int> ans;

void dfs(int v) {
	if (vis[v]) return;
	vis[v] = true;
	C_par[v] = C;
	parpar[v] = rt;
	for (auto e : adj[v]) 
		if (e.Y == 'M') dfs(e.X);
}

bool cmp(pair<pair<int, int>, char> p1, pair<pair<int, int>, char> p2) {
	if (p1.Y == p2.Y) return p1 < p2;
	if (p1.Y == 'S') return true;
	return false;
}

int Find(int v) {
	if (v == par[v]) return v;
	return par[v] = Find(par[v]);
}

int Find2(int v) {
	if (v == parpar[v]) return v;
	return parpar[v] = Find2(parpar[v]);
}

inline void Union2(int u, int v) {
	u = Find2(u);
	v = Find2(v);
	if (u == v) return;
	parpar[v] = u;
}

inline void Union(int u, int v, char c, int ind) {		
	u = Find(u);
	v = Find(v);
	if (u == v) return;
	if (H[v] > H[u]) swap(v, u);
	par[v] = u;
	if (H[v] == H[u]) H[u]++;
	if (c == 'S') ES++;
	ans.push_back(ind);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 0; i < m; i++) {
		int u, v;
		char c;
		cin >> u >> v >> c;
		adj[v].push_back({u, c});
		adj[u].push_back({v, c});
		edges.push_back({{u, v}, c});
		mp[make_pair(make_pair(u, v), c)] = i + 1;
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			rt = i;
			C++;
			dfs(i);
		}
	}

	E = n / 2;
	if (n % 2 == 0 || C - 1 > E) return cout << "-1" << endl, 0;
	sort(all(edges), cmp);


	for (auto e : edges) {
		int u = e.X.X, v = e.X.Y, ind = mp[e];
		char c = e.Y;	
		
		if (Find2(u) != Find2(v) && c == 'S') Union(u, v, c, ind), Union2(u, v);
	}


	for (auto e : edges) {
		int u = e.X.X, v = e.X.Y, ind = mp[e];
		char c = e.Y;
		if (c == 'S' && ES < E) Union(u, v, c, ind);
		if (c == 'M') Union(u, v, c, ind);
	}

	if (ES < E || (int)ans.size() != n - 1) return cout << -1 << endl, 0;
	cout << ans.size() << endl;
	for (int e : ans) cout << e << sep;
	cout << endl;
	return 0;
}