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

const int INF = 1e9;

template<int MAXN, int MAXM>
struct MinCostMaxFlow {
	struct Edge {
		int from, to, cap,  cost;
	};


	Edge E[2 * MAXM];
	int m, par[MAXN], s, t, dist[MAXN], k, mn[MAXN];
	vector<int> adj[MAXN];

	inline void add_edge(int u, int v, int cap, int cost) {
		adj[u].push_back(m);
		E[m++] = {u, v, cap, cost};
		adj[v].push_back(m);
		E[m++] = {v, u, 0, -cost};
	}

	inline void SPFA() {
		memset(dist, 63, sizeof dist);
		fill(par, par + MAXN, -1);
		queue<int> q;

		dist[s] = 0;
		q.push(s);
		mn[s] = INF;
	
		while (!q.empty()) {
			int v = q.front();
			q.pop();

			for (int id : adj[v]) {
				int u = E[id].to;
				if (!E[id].cap) continue;

				if (dist[u] > dist[v] + E[id].cost) {
					dist[u] = dist[v] + E[id].cost;
					q.push(u);
					par[u] = id;
					mn[u] = min(mn[v], E[id].cap);
				}
			}
		}
	}

	inline int solve() {
		SPFA();

		if (dist[t] > k) return 0;
		int c = min(mn[t], dist[t] == 0 ? mn[t] : k / dist[t]), v = t;
		k -= dist[t] * c;

		while (v != s) {
			int id = par[v];
			E[id].cap -= c;
			E[id ^ 1].cap += c;
			v = E[id].from;
		}

		return c;
	}

	inline int max_flow(int _s, int _t, int _k) {
		s = _s, t = _t, k = _k;
		int ans = 0;
		
		while (true) {
			int c = solve();
			if (c) ans += c;
			else return ans;
		}
	}
};

const ll MAXN = 50 + 3; 
MinCostMaxFlow<MAXN, 2 * MAXN * MAXN> flow;

int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;

	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			int c;
			cin >> c;
			if (!c) continue;

			flow.add_edge(u, v, c, 0);
			flow.add_edge(u, v, k, 1);
		}
	}

	cout << flow.max_flow(1, n, k) << endl;
	return 0;
}