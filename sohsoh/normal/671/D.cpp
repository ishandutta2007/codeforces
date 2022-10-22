#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;

priority_queue<pll, vector<pll>, greater<pll>> pq[MAXN];
int n, m, H[MAXN];
ll dp[MAXN], delta[MAXN], lz[MAXN];
vector<pll> C[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int p) {
	H[v] = H[p] + 1;
	for (int u : adj[v]) {
		if (u == p) continue;
		dfs(u, v);
		dp[v] += dp[u];
		
		bool flag = (pq[v].size() < pq[u].size());
		if (flag) swap(v, u);
		
		while (!pq[u].empty()) {
			pll e = pq[u].top();
			pq[u].pop();
			if (H[e.Y] < H[v])
				pq[v].push({e.X + lz[u] - lz[v], e.Y});
		}

		if (flag) {
			swap(lz[v], lz[u]);
			pq[v].swap(pq[u]);
			swap(v, u);
		}
	}

	for (pll e : C[v]) pq[v].push({e.X - lz[v], e.Y});	
	if (p) {
		while (true) {
			if (pq[v].empty()) {
				cout << -1 << endl;
				exit(0);
			}

			if (H[pq[v].top().Y] >= H[v]) pq[v].pop();
			else {
				dp[v] += delta[v] = pq[v].top().X + lz[v];
				break;
			}
		}
	}

	lz[v] -= delta[v];	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		C[u].push_back({c, v});
	}

	dfs(1, 0);
	cout << dp[1] << endl;
	return 0;
}