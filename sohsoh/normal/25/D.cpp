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
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

set<pll> st;
vector<ll> adj[MAXN];
vector<pll> ans1;
bool vis[MAXN] = {false};
ll tin[MAXN], low[MAXN], timer, n, c = 0, C[MAXN];

void dfs(ll v, ll p = 0) {
	vis[v] = true;
	tin[v] = low[v] = timer++;
	for (ll u : adj[v]) {
		if (u == p) continue;
		if (vis[u]) {
			low[v] = min(low[v], tin[u]);
		} else {
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if (low[u] > tin[v]) st.erase({u, v}), st.erase({v, u});
		}
	}
}

void dfs2(ll v) {
	vis[v] = true;
	C[c] = v;
	for (ll u : adj[v]) if (!vis[u]) dfs2(u);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		st.insert({u, v});
	}

	while (!st.empty()) {
		fill(vis, vis + MAXN, false);
		timer = 0;
		for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
		if (st.empty()) break;
		pll br = *st.begin();
		st.erase(st.begin());
		ans1.push_back(br);
		adj[br.X].erase(find(all(adj[br.X]), br.Y));
		adj[br.Y].erase(find(all(adj[br.Y]), br.X));
	}

	fill(vis, vis + MAXN, false);
	for (int i = 1; i <= n; i++)
		if (!vis[i]) c++, dfs2(i);

	cout << c - 1 << endl;
	for (int i = 2; i <= c; i++)
		cout << ans1[i - 2].X << sep << ans1[i - 2].Y << sep << C[1] << sep << C[i] << endl;	
	return 0;
}