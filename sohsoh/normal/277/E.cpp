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
	C dist[MAXN], cost = 0;
	F mn[MAXN], flow = 0;
	vector<int> adj[MAXN];

	inline void add_edge(int u, int v, F cap, C cost) {
		adj[u].push_back(m);
		E[m++] = {u, v, cap, cost};
		adj[v].push_back(m);
		E[m++] = {v, u, 0, -cost};
	}

	inline void SPFA() {
		fill(dist, dist + MAXN, numeric_limits<C>::max());
		fill(par, par + MAXN, -1);
		queue<int> q;

		dist[s] = 0;
		q.push(s);
		mn[s] = numeric_limits<F>::max();
	
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

	inline F solve() {
		SPFA();

		if (par[t] == -1) return 0;
		F c = mn[t], v = t;
		flow += c;
		cost += c * dist[t];

		while (v != s) {
			int id = par[v];
			E[id].cap -= c;
			E[id ^ 1].cap += c;
			v = E[id].from;
		}

		return c;
	}

	inline pair<F, C> max_flow(int _s, int _t) {
		s = _s, t = _t;
		while (true) {
			F c = solve();
			if (!c) break;
		}

		return {flow, cost};
	}
};

const ll MAXN = 402;
MinCostMaxFlow<int, double, MAXN * 2, MAXN * MAXN> flow;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;

	int s = 0, t = 2 * n + 1;
	vector<pll> vec;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({x, y});
	}

	vec.push_back({1e4, 1e4});
	sort(all(vec), [] (pll a, pll b) {
		return a.Y > b.Y;	
	});

	for (int i = 1; i <= n; i++) {
		flow.add_edge(s, i, 2, 0);
		flow.add_edge(i + n, t, 1, 0);
		for (int j = 1; j <= i; j++) {
			if (vec[i].Y < vec[j].Y) {
				double dist = sqrt((vec[i].X - vec[j].X) * (vec[i].X - vec[j].X) + 
						(vec[i].Y - vec[j].Y) * (vec[i].Y - vec[j].Y));
				flow.add_edge(j, n + i, 1, dist);
			}
		}
	}

	auto e = flow.max_flow(s, t);
	if (e.X != n - 1) return cout << -1 << endl, 0;
	cout << setprecision(10) << fixed << e.Y << endl;
	return 0;
}