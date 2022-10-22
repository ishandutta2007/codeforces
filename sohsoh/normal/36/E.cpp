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

const ll MAXN = 1e5 + 10;

int m;
vector<int> P[2], vec, path;
vector<pair<int, int>> adj[MAXN];
bool vis[MAXN], e_vis[MAXN];

void dfs(int v) {
	vis[v] = true;
	vec.push_back(v);
	for (pll e : adj[v])
		if (!vis[e.X])
			dfs(e.X);
}

void euler(int v, int ind) {
	while (!adj[v].empty()) {
		pll e = adj[v].back();
		adj[v].pop_back();
		
		if (e_vis[e.Y]) continue;
		e_vis[e.Y] = true;
		euler(e.X, e.Y);
	}
	
	if (ind) path.push_back(ind);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	

	cin >> m;
	if (m < 2) return cout << -1 << endl, 0; 

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}

	for (int i = 1; i < MAXN; i++) {
		if (vis[i] || adj[i].empty()) continue;
		vec.clear();
		path.clear();
		dfs(i);

		vector<int> odd;
		for (int e : vec)
			if (adj[e].size() & 1)
				odd.push_back(e);

		if (odd.size() > 4 || (odd.size() > 2 && !P[0].empty()) || !P[1].empty()) return cout << -1 << endl, 0;
	
		if (odd.size() < 4) {
			int v = vec.front();
			if (!odd.empty())
				v = odd.front();
			
			euler(v, 0);
			if (P[0].empty()) P[0] = path;
			else P[1] = path;
		} else {	
			adj[odd[0]].push_back({odd[1], m + 1});
			adj[odd[1]].push_back({odd[0], m + 1});

			euler(odd[2], 0);
			bool flag = false;

			for (int e : path) {
				if (e > m) {
					flag = true;
					continue;
				}

				if (flag) P[1].push_back(e);
				else P[0].push_back(e);
			}
		}
	}

	if (P[1].empty()) P[1].push_back(P[0].back()), P[0].pop_back();
	cout << P[0].size() << endl;
	for (int e : P[0]) cout << e << sep;

	cout << endl << P[1].size() << endl;
	for (int e : P[1]) cout << e << sep;
	cout << endl;
	return 0;
}