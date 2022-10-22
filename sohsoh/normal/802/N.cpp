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
	C dist[MAXN], k, tot_cost = 0;
	F mn[MAXN], f;
	vector<int> adj[MAXN];

	inline void add_edge(int u, int v, F cap, C cost) {
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

		F c = min(f, mn[t]), v = t;
		tot_cost += dist[t] * c;
		f -= c;

		while (v != s) {
			int id = par[v];
			E[id].cap -= c;
			E[id ^ 1].cap += c;
			v = E[id].from;
		}

		return c;
	}

	inline C max_flow(int _s, int _t, C _k, F _f) {
		s = _s, t = _t, k = _k, f = _f;
		
		while (f) {
			F c = solve();
			if (!c) break;
		}

		return tot_cost;
	}
};

const ll MAXN = 2200 + 4; 
const ll INF = 8e18;
MinCostMaxFlow<int, ll, MAXN, 3 * MAXN> flow;

int n, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
 
	int s = 0, t = n + 1;
        for (int i = 1; i <= n; i++) {
                int x;
                cin >> x;
                flow.add_edge(s, i, 1, x);
                if (i < n) flow.add_edge(i, i + 1, k, 0);
        }

        for (int i = 1; i <= n; i++) {
                int x;
                cin >> x;
                flow.add_edge(i, t, 1, x);
        }

	cout << flow.max_flow(s, t, INF, k) << endl;	
	return 0;
}