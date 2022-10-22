//: // ////: ///  / : //// / :
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

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;

int n, m, q, ind, F[MAXN], P_ind[MAXN], P[MAXN], tin[MAXN], tout[MAXN], t;
ll dp[MAXN][2];
vector<int> t_adj[MAXN], adj[MAXN];
vector<pll> Q;
bool vis[MAXN], E[MAXN];

void tdfs(int v) {
	vis[v] = true;
	tin[v] = ++t;
	for (int u : t_adj[v]) {
		if (!vis[u]) {
			ind++;
			P_ind[u] = ind;
			F[ind] = u;
			P[u] = v;

			adj[v].push_back(u);
			adj[u].push_back(v);
			tdfs(u);
		}
	}

	tout[v] = t;
}

inline bool par(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

void dfs(int v) {
	dp[v][0] = 0;
	dp[v][1] = 1;

	for (int u : adj[v]) {
		if (u == P[v]) continue;
		dfs(u);

		ll f[2];
		f[0] = INF;
		f[1] = INF;

		f[0] = min({f[0], dp[v][0] + dp[u][0], dp[v][1] + dp[u][1] - 1});
		f[1] = min({f[1], dp[v][1] + dp[u][0], dp[v][0] + dp[u][1]});
		dp[v][0] = f[0];
		dp[v][1] = f[1];
	}

	dp[v][0] = min(dp[v][0], dp[v][1]);
	dp[v][1] = min(dp[v][1], dp[v][0] + 1);

	if (E[P_ind[v]]) dp[v][0] = INF;
	else dp[v][1] = INF;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		t_adj[u].push_back(v);
		t_adj[v].push_back(u);
	}

	tdfs(1);
	
	vector<vector<int>> tans;
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		vector<int> tmp = {u};

		while (!par(u, v)) {
			E[P_ind[u]] ^= true;
			u = P[u];
			tmp.push_back(u);
		}

		while (u != v) {
			for (int e : adj[u]) {
				if (par(e, v) && e != P[u]) {
					E[P_ind[e]] ^= true;
					u = e;
					tmp.push_back(e);
					break;
				}
			}
		}

		tans.push_back(tmp);
	}

	dfs(1);
	if (dp[1][0] == 0) {
		cout << "YES" << endl;
		for (auto v : tans) {
			cout << v.size() << endl;
			for (int e : v) cout << e << sep;
			cout << endl;
		}
	} else {
		cout << "NO" << endl << dp[1][0] << endl;
	}
	return 0;
}