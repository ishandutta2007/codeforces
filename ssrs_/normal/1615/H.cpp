#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename Cap, typename Cost>
struct primal_dual{
	struct edge{
		int to, rev;
		Cap cap;
		Cost cost;
		edge(int to, int rev, Cap cap, Cost cost): to(to), rev(rev), cap(cap), cost(cost){
		}
	};
	int N;
	vector<vector<edge>> G;
	primal_dual(){
	}
	primal_dual(int N): N(N), G(N){
	}
	void add_edge(int from, int to, Cap cap, Cost cost){
		int id1 = G[from].size();
		int id2 = G[to].size();
		G[from].push_back(edge(to, id2, cap, cost));
		G[to].push_back(edge(from, id1, 0, - cost));
	}
	vector<Cost> min_cost_flow(int s, int t, Cap F){
		Cap flow = 0;
		Cost cost = 0;
		vector<Cost> h(N, 0);
		while (flow < F){
			vector<Cap> m(N, INF);
			vector<Cost> d(N, INF);
			vector<int> pv(N, -1);
			vector<int> pe(N, -1);
			vector<bool> used(N, false);
			priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> pq;
			pq.push(make_pair(0, s));
			d[s] = 0;
			while (!pq.empty()){
				int v = pq.top().second;
				pq.pop();
				if (!used[v]){
					used[v] = true;
					if (v == t){
						break;
					}
					int cnt = G[v].size();
					for (int i = 0; i < cnt; i++){
						int w = G[v][i].to;
						if (!used[w] && G[v][i].cap > 0){
							Cost tmp = G[v][i].cost - h[w] + h[v];
							if (d[w] > d[v] + tmp){
								d[w] = d[v] + tmp;
								m[w] = min(m[v], G[v][i].cap);
								pv[w] = v;
								pe[w] = i;
								pq.push(make_pair(d[w], w));
							}
						}
					}
				}
			}
			if (!used[t]){
				break;
			}
			for (int i = 0; i < N; i++){
				if (used[i]){
					h[i] -= d[t] - d[i];
				}
			}
			Cap c = min(m[t], F - flow);
			for (int i = t; i != s; i = pv[i]){
				G[pv[i]][pe[i]].cap -= c;
				G[i][G[pv[i]][pe[i]].rev].cap += c;
			}
			flow += c;
			cost += c * (- h[s]);
		}
		return h;
	}
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  primal_dual<long long, long long> G(n + 3);
  vector<long long> b(n + 1, 0);
  for (int i = 0; i < n; i++){
    G.add_edge(n, i, 2, a[i]);
    b[n]++;
    b[i]--;
  }
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      G.add_edge(j, i, INF, 0);
    }
  }
  for (int i = 0; i <= n; i++){
    if (b[i] < 0){
      G.add_edge(i, n + 2, -b[i], 0);
    } else {
      G.add_edge(n + 1, i, b[i], 0);
    }
  }
  vector<long long> p = G.min_cost_flow(n + 1, n + 2, n);
  for (int i = 0; i < n; i++){
    cout << p[i] - p[n];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}