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

template<typename F, typename C, int MAXN, int MAXM>
struct MinCostMaxFlow {
	struct Edge {
		int from, to;
		F cap;
		C cost;
	};


	Edge E[2 * MAXM];
	int m, par[MAXN], s, t;
	C dist[MAXN], cost = 0, pot[MAXN];
	F mn[MAXN], flow = 0;
	vector<int> adj[MAXN];
	bool vis[MAXN];

	MinCostMaxFlow() {
		memset(pot, 0, sizeof pot);
	}

	inline void add_edge(int u, int v, F cap, C cost) {
		adj[u].push_back(m);
		E[m++] = {u, v, cap, cost};
		adj[v].push_back(m);
		E[m++] = {v, u, 0, -cost};
	}

	inline void dijkstra() {
		C INF = numeric_limits<C>::max();
		fill(dist, dist + MAXN, INF);
		fill(par, par + MAXN, -1);
		memset(vis, false, sizeof vis);

		dist[s] = 0;
		mn[s] = numeric_limits<F>::max();
		
		while (true) {
			int v = -1;
			C d = INF;

			for (int u = 0; u < MAXN; u++)
				if (!vis[u] && dist[u] < d)
					v = u, d = dist[u];

			if (d == INF) break;
			for (int id : adj[v]) {
				int u = E[id].to;
				if (!E[id].cap) continue;
				C d_u = d + pot[v] - pot[u] + E[id].cost;

				if (d_u < dist[u]) {
					dist[u] = d_u;
					par[u] = id;
					mn[u] = min(mn[v], E[id].cap);
				}
			}

			vis[v] = true;
		}
	}

	inline F solve() {
		dijkstra();
	
		if (par[t] == -1) return 0;
		F c = min(mn[t], flow), v = t;
		flow -= c;
		cost += c * (dist[t] + pot[t]);

		while (v != s) {
			int id = par[v];
			E[id].cap -= c;
			E[id ^ 1].cap += c;
			v = E[id].from;
		}

		for (int v = 0; v < MAXN; v++)
			pot[v] += dist[v];
		

		return c;
	}

	inline C min_cost(int _s, int _t, F _flow) {
		s = _s, t = _t, flow = _flow;
		while (true) {
			F c = solve();
			if (c == 0)
				break;
		}

		return cost;
	}
};

const ll MAXN = 3000 + 10;
MinCostMaxFlow<int, int, MAXN * 2, MAXN * MAXN / 2> flow;

// dijkstra -> n^2

int n, A[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int s = 0, t = 2 * (n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		flow.add_edge(s, i << 1, 1, i - 1);
		flow.add_edge(i << 1 | 1, t, 1, n - i);
		flow.add_edge(i << 1, i << 1 | 1, 1, 0);

		for (int j = 1; j < i; j++)
			if (A[j] % 7 == A[i] % 7 || A[i] - A[j] == 1 || A[j] - A[i] == 1)
				flow.add_edge(j << 1 | 1, i << 1, 1, i - j - 1);
	}

	cout << 4 * n - flow.min_cost(s, t, 4) << endl;
	return 0;
}