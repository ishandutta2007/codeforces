#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

int n, m, low[MAXN], H[MAXN], cnt, ind[MAXN];
pll edges[MAXN];
vector<pll> adj[MAXN];
bool vis[MAXN], edge_vis[MAXN], in_cyc[MAXN], flag;
vector<int> T, vert, path, tadj[MAXN], tpath;

void print(vector<int> v) {
	cout << v.size() << sep;
	for (int e : v) cout << e << sep;
	cout << endl;
}

void majik(int v) {
	vis[v] = true;
	tpath.push_back(v);
	for (int u : tadj[v]) {
		int diff = ind[v] - ind[u];
		diff = (diff + int(path.size())) % int(path.size());
		
		if (vis[u] || (in_cyc[v] && in_cyc[u] && (diff == 1 || diff == int(path.size()) - 1))) continue;
		
		if (in_cyc[u]) {
			tpath.push_back(u);
			print(tpath);
			
			rotate(path.begin(), path.begin() + ind[tpath.front()], path.end());
			
			vector<int> vec = {tpath.front()};
			while (path.back() != u) {
				vec.push_back(path.back());
				path.pop_back();
			}

			vec.push_back(u);
			print(path);
			print(vec);
			exit(0);
		}

		majik(u);
	}

	tpath.pop_back();
}

void cyc(int v, int p) {
	vis[v] = true;
	path.push_back(v);

	for (int u : tadj[v]) {
		if (flag) break;

		if (u == p) continue;
		if (vis[u]) {
			reverse(all(path));
			flag = true;
			while (path.back() != u) path.pop_back();

			for (int e : path) in_cyc[e] = true;
			break;
		}

		cyc(u, v);
	}

	if (!flag) path.pop_back();
}

inline void solve() {
	sort(all(vert));
	vert.resize(unique(all(vert)) - vert.begin());
	
	if (cnt <= int(vert.size())) {
		cnt = 0;
		for (int e : vert)
			tadj[e].clear();
		vert.clear();

		return;
	}

	cout << "YES" << endl;
	int v = vert.front();
	
	memset(vis, false, sizeof vis);
	cyc(v, 0);
	for (int i = 0; i < int(path.size()); i++)
		ind[path[i]] = i;

	memset(vis, false, sizeof vis);
	for (int v : path)
		if (!vis[v])
			majik(v);

	assert(false);
}

void dfs(int v, int p) {
	T.push_back(v);
	vis[v] = true;
	H[v] = H[p] + 1;
	low[v] = H[v];

	for (pll e : adj[v]) {
		int u = e.X, id = e.Y;

		if (u == p) continue;
		if (vis[u]) {
			low[v] = min(low[v], H[u]);
			continue;
		}

		int t = T.back();
		dfs(u, v);
		low[v] = min(low[v], low[u]);

		if (low[u] >= H[v]) {
			while (T.back() != t) {
				int u = T.back();
				T.pop_back();	
				
				for (pll e : adj[u]) {
					if (!edge_vis[e.Y]) {
						edge_vis[e.Y] = true;
						tadj[edges[e.Y].X].push_back(edges[e.Y].Y);
						tadj[edges[e.Y].Y].push_back(edges[e.Y].X);
						vert.push_back(edges[e.Y].X);
						vert.push_back(edges[e.Y].Y);
						cnt++;
				//		debug(e.Y)
					}
				}
			}

			solve();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		edges[i] = {u, v};
	}

	for (int v = 1; v <= n; v++)
		if (!vis[v])
			dfs(v, 0);

	cout << "NO" << endl;
	return 0;
}