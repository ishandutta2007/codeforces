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

const ll MAXN = 2e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

vector<int> leafs, adj[MAXN];
int ans, ans_d, n, dist1[MAXN], dist2[MAXN], deg[MAXN], par[MAXN];

void dfs(int v, int p, int d) {
	if (d > ans_d) {
		ans_d = d;
		ans = v;
	}

	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v, d + 1);
	}
}

void dfs2(int v, int p, int d, int* dist) {
	dist[v] = d;
	par[v] = p;
	for (int u : adj[v]) 
		if (u != p)
			dfs2(u, v, d + 1, dist);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}

	pll diam;
	dfs(1, 0, 0);
	diam.X = ans;
	ans = ans_d = 0;
	dfs(diam.X, 0, 0);
	diam.Y = ans;

	for (int i = 1; i <= n; i++)
		if (deg[i] == 1 && i != diam.X && i != diam.Y)
			leafs.push_back(i);

	dfs2(diam.Y, 0, 0, dist2);
	dfs2(diam.X, 0, 0, dist1);

	ll ans = 0;
	vector<pll> ans_v;
	while (!leafs.empty()) {
		int v = leafs.back();
		leafs.pop_back();
		if (dist1[v] > dist2[v]) {
			ans += dist1[v];
			ans_v.push_back({v, diam.X});
		} else {
			ans += dist2[v];
			ans_v.push_back({v, diam.Y});
		}
		
		deg[v] = -1;
		for (int u : adj[v]) {
			deg[u]--;
			if (deg[u] == 1) leafs.push_back(u);
		}
	}
	
	while (diam.X != diam.Y) {
		ans += dist1[diam.Y];
		ans_v.push_back({diam.Y, diam.X});
		
		deg[diam.Y] = -1;
		diam.Y = par[diam.Y];

	}	

	cout << ans << endl;
	for (pll e : ans_v) 
		cout << e.X << sep << e.Y << sep << e.X << endl;
	return 0;
}