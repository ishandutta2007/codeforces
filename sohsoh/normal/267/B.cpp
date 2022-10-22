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

int n, vis[MAXN], vis2[MAXN];
vector<pair<pll, int>> adj[MAXN];
vector<pll> ans;

void dfs(int v, int ind, int dir) {
	while (!adj[v].empty()) {
		pair<pll, int> e = adj[v].back();
		adj[v].pop_back();
		if (vis[e.X.Y]) continue;
		vis[e.X.Y] = true;
		dfs(e.X.X, e.X.Y, e.Y);
	}

	ans.push_back({ind, 1 - dir});
}

void dfs2(int v) {
	vis2[v] = true;
	for (auto e : adj[v]) {
		if (!vis2[e.X.X]) dfs2(e.X.X);
	}
}

inline char cv(int x) {
	if (x == 0) return '-';
	return '+';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({{v, i}, 1});
		adj[v].push_back({{u, i}, 0});
	}

	for (int i = 0; i <= 6; i++) {
		if (!adj[i].empty()) {
			dfs2(i);
			for (int j = 1; j <= 6; j++)
				if (!adj[j].empty() && !vis2[j]) return cout << "No solution" << endl, 0; 
			break;
		}
	}	
	
	pll odd_edge = {10, 10};
	for (int i = 0; i <= 6; i++) {
		if (adj[i].size() & 1) {
			if (odd_edge.X == 10) odd_edge.X = i;
			else if (odd_edge.Y == 10) odd_edge.Y = i;
			else return cout << "No solution" << endl, 0;
		}
	}

	adj[odd_edge.X].push_back({{odd_edge.Y, n + 10}, 1});
	adj[odd_edge.Y].push_back({{odd_edge.X, n + 10}, 0});

	for (int i = 0; i <= 6; i++) {
		if (!adj[i].empty()) {
			dfs(i, n + 5, 0);
			break;
		}
	}
	

	
	int bad_ind = -1, bad_ind_val = -1;
	for (int i = 0; i < ans.size(); i++) if (ans[i].X > bad_ind_val) bad_ind = i, bad_ind_val = ans[i].X;
	for (int i = bad_ind + 1; i < ans.size(); i++)
		if (ans[i].X <= n) cout << ans[i].X << sep << cv(ans[i].Y) << endl;
	for (int i = 0; i < bad_ind; i++)
		if (ans[i].X <= n) cout << ans[i].X << sep << cv(ans[i].Y) << endl;
	
	
	return 0;
}