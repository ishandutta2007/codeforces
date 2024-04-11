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

int n, tot = 0, X[MAXN], tmp, val[MAXN], C[MAXN];
vector<pair<pll, int>> edges;
bool vis[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	vis[v] = true;
	val[tmp] += X[v];
	C[tmp]++;
	for (int u : adj[v]) if (u != p) dfs(u, v);
}

inline bool check(int v) {
	int t = tot - val[v];
	return C[v] <= t;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({{u, v}, w});
	}

	for (int i = 1; i <= n; i++) {
		cin >> X[i];
		tot += X[i];
	}

	int L = 0, R = MAXN;
	while (L < R) {
		tmp = 0;
		for (int i = 1; i <= n; i++) val[i] = C[i] = 0, adj[i].clear();
		int mid = (L + R + 1) >> 1;
		bool ok = true;
		for (auto e : edges)
			if (e.Y < mid) adj[e.X.X].push_back(e.X.Y), adj[e.X.Y].push_back(e.X.X);
		fill(vis, vis + n + 10, false);	
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				tmp++;
				dfs(i, 0);
				ok &= check(tmp);
			}
		}

		if (ok) L = mid;
		else R = mid - 1;
	}

	cout << L << endl;
	return 0;
}