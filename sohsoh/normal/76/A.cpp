#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

vector<pll> adj[MAXN];
pair<pll, ll> edges[MAXN];
int n, m, G, S, B;
bool found, vis[210];
vector<int> path;
ll ans = INF;

inline void Remove(int ind) {
	int u = edges[ind].X.X, v = edges[ind].X.Y;
	adj[u].erase(find(all(adj[u]), make_pair(1ll * v, 1ll * ind)));
	adj[v].erase(find(all(adj[v]), make_pair(1ll * u, 1ll * ind)));
} 

inline void Add(int ind) {
	int u = edges[ind].X.X, v = edges[ind].X.Y;
	adj[u].push_back({v, ind});
	adj[v].push_back({u, ind});
}

void dfs(int v, int p, int tar) {
	if (v == tar) {
		found = true;
		return;
	}

	for (pll e : adj[v]) {
		int u = e.X, ind = e.Y;
		if (u == p) continue;
		path.push_back(ind);
		dfs(u, v, tar);
		if (found) return;
		path.pop_back();
	}
}

void dfs2(int v, int p) {
	vis[v] = true;
	for (pll e : adj[v]) {
		int ind = e.Y, u = e.X;
		if (u == p) continue;
		dfs2(u, v);	
		B = max(1ll * B, edges[ind].Y);
	}
}

inline void Ans(int tg) {
	B = 0;
	memset(vis, false, sizeof vis);	
	dfs2(1, 0);
	if (find(vis + 1, vis + n + 1, false) != vis + n + 1) return;	
	ans = min(ans, 1ll * tg * G + 1ll * B * S);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> G >> S;
	vector<pll> E;
	for (int i = 1; i <= m; i++) {
		int u, v, g, s;
		cin >> u >> v >> g >> s;
		edges[i] = {{u, v}, s};
		E.push_back({g, i});
	}

	sort(all(E));
	for (pll e : E) {
		int g = e.X, ind = e.Y, u = edges[ind].X.X, v = edges[ind].X.Y, s = edges[ind].Y;
		found = false;
		path.clear();
		dfs(u, 0, v);

		if (!found) Add(ind);
		else {
			int bw = 0, r_ind = -1;
			for (int e : path) {
				if (edges[e].Y > bw) {
					bw = edges[e].Y;
					r_ind = e;
				}	
			}

			if (bw > s) {
				Remove(r_ind);	
				Add(ind);
			}
		}


		Ans(g);
	}

	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}