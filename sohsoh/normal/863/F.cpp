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
		fill(dist, dist + MAXN, numeric_limits<C>::max());
		fill(par, par + MAXN, -1);
		priority_queue<pair<C, int>, vector<pair<C, int>>, greater<pair<C, int>>> pq;

		dist[s] = 0;
		mn[s] = numeric_limits<F>::max();
		pq.push({dist[s], s});
		
		while (!pq.empty()) {
			int v = pq.top().Y;
			C d = pq.top().X;
			pq.pop();
			if (d != dist[v]) continue;
		
			for (int id : adj[v]) {
				int u = E[id].to;
				if (!E[id].cap) continue;
				C d_u = d + pot[v] - pot[u] + E[id].cost;

				if (d_u < dist[u]) {
					dist[u] = d_u;
					pq.push({d_u, u});
					par[u] = id;
					mn[u] = min(mn[v], E[id].cap);
				}
			}
		}
	}

	inline F solve() {
		dijkstra();
	
		if (par[t] == -1) return 0;
		F c = mn[t], v = t;
		flow += c;
		cost += c * (dist[t] + pot[t]);

		while (v != s) {
			int id = par[v];
			E[id].cap -= c;
			E[id ^ 1].cap += c;
			v = E[id].from;
		}

		for (int v = 0; v < MAXN; v++)
			if (par[v] != -1)
				pot[v] += dist[v];

		return c;
	}

	inline pair<C, F> min_cost_max_flow(int _s, int _t) {
		s = _s, t = _t;
		while (true) {
			F c = solve();
			if (c == 0)
				break;
		}

		return {cost, flow};
	}
};

const ll MAXN = 50 + 3;
MinCostMaxFlow<int, int, MAXN * MAXN * 2, MAXN * MAXN * 5> flow;

int n, q, L[MAXN], R[MAXN], F[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	fill(L + 1, L + n + 1, 1);
	fill(R + 1, R + n + 1, n);

	while (q--) {
		int ind, l, r, c;
		cin >> ind >> l >> r >> c;
		for (int i = l; i <= r; i++) {
			if (ind == 1) L[i] = max(L[i], c);
			else R[i] = min(R[i], c);
		}
	}

	int s = 0, t = MAXN * MAXN * 2 - 1, v = 1;
	for (int i = 1; i <= n; i++) {
		F[i] = v;
		flow.add_edge(v++, t, 1, 1);
		for (int j = 2; j <= n; j++) {
			flow.add_edge(v - 1, v, n, 0);
			flow.add_edge(v++, t, 1, 2 * j - 1);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (L[i] > R[i]) return cout << -1 << endl, 0;
		int prv = 0;
		for (int j = L[i]; j <= R[i]; j++) {
			flow.add_edge(prv, v, 1, 0);
			flow.add_edge(v, F[j], 1, 0);
			prv = v++;
		}
	}

	auto e = flow.min_cost_max_flow(s, t);
	if (e.Y != n) return cout << -1 << endl, 0;
	cout << e.X << endl;
	return 0;
}