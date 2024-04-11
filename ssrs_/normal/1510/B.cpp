#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
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
	pair<Cap, Cost> min_cost_flow(int s, int t, Cap F){
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
		return make_pair(flow, cost);
	}
};
int main(){
  int d, n;
  cin >> d >> n;
  vector<int> x(n, 0);
  for (int i = 0; i < n; i++){
    string s;
    cin >> s;
    for (int j = 0; j < d; j++){
      x[i] += (s[d - 1 - j] - '0') << j;
    }
  }
  primal_dual<int, int> G((1 << (d + 1)) + 5);
  int s = 1 << (d + 1);
  int t1 = (1 << (d + 1)) + 1;
  int t2 = (1 << (d + 1)) + 2;
  int S = (1 << (d + 1)) + 3;
  int T = (1 << (d + 1)) + 4;
  for (int i = 0; i < (1 << d); i++){
    G.add_edge(i * 2, i * 2 + 1, INF, 0);
    for (int j = 0; j < d; j++){
      if ((i >> j & 1) == 0){
        int i2 = i + (1 << j);
        G.add_edge(i * 2 + 1, i2 * 2, INF, 1);
      }
    }
    G.add_edge(i * 2 + 1, s, INF, 0);
    G.add_edge(i * 2 + 1, t1, INF, 0);
  }
  for (int i = 0; i < n; i++){
    G.add_edge(S, x[i] * 2 + 1, 1, 0);
    G.add_edge(x[i] * 2, T, 1, 0);
  }
  G.add_edge(s, 0, INF, 1);
  G.add_edge(t1, t2, 1, 0);
  G.add_edge(S, s, INF, 0);
  G.add_edge(t2, T, INF, 0);
  G.min_cost_flow(S, T, INF);
  vector<vector<int>> next(1 << d);
  for (int i = 0; i < (1 << d); i++){
    for (int j = 0; j < d; j++){
      if ((i >> j & 1) == 0){
        int i2 = i + (1 << j);
        for (auto e : G.G[i2 * 2]){
          if (e.to == i * 2 + 1 && e.cap > 0){
            for (int k = 0; k < e.cap; k++){
              next[i].push_back(i2);
            }
          }
        }
      }
    }
  }
  vector<vector<int>> p;
  while (!next[0].empty()){
    p.push_back({0});
    int v = 0;
    while (!next[v].empty()){
      int w = next[v].back();
      next[v].pop_back();
      p.back().push_back(w);
      v = w;
    }
  }
  int cnt = p.size();
  vector<char> ans;
  for (int i = 0; i < cnt; i++){
    int sz = p[i].size();
    for (int j = 0; j < sz - 1; j++){
      int id = d - 1 - __builtin_ctz(p[i][j + 1] - p[i][j]);
      ans.push_back((char) ('0' + id));
    }
    if (i < cnt - 1){
      ans.push_back('R');
    }
  }
  int k = ans.size();
  cout << k << endl;
  for (int i = 0; i < k; i++){
    cout << ans[i];
    if (i < k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}