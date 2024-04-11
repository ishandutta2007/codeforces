#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename Cap>
struct ford_fulkerson{
	struct edge{
		int to, rev;
		Cap cap;
		edge(int to, int rev, Cap cap): to(to), rev(rev), cap(cap){
		}
	};
	int N;
	vector<vector<edge>> G;
	ford_fulkerson(){
	}
	ford_fulkerson(int N): N(N), G(N){
	}
	void add_edge(int from, int to, Cap cap){
		int id1 = G[from].size();
		int id2 = G[to].size();
		G[from].push_back(edge(to, id2, cap));
		G[to].push_back(edge(from, id1, 0));
	}
	Cap max_flow(int s, int t){
		Cap flow = 0;
		while (1){
			vector<Cap> m(N, INF);
			vector<int> pv(N, -1);
			vector<int> pe(N, -1);
			vector<bool> used(N, false);
			queue<int> Q;
			Q.push(s);
			used[s] = true;
			while (!Q.empty()){
				int v = Q.front();
				Q.pop();
				int cnt = G[v].size();
				for (int i = 0; i < cnt; i++){
					int w = G[v][i].to;
					if (!used[w] && G[v][i].cap > 0){
						used[w] = true;
						m[w] = min(m[v], G[v][i].cap);
						pv[w] = v;
						pe[w] = i;
						Q.push(w);
					}
				}
			}
			if (!used[t]){
				break;
			}
			Cap f = m[t];
			for (int i = t; i != s; i = pv[i]){
				G[pv[i]][pe[i]].cap -= f;
				G[i][G[pv[i]][pe[i]].rev].cap += f;
			}
			flow += f;
		}
		return flow;
	}
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  long long ans = 0;
  ford_fulkerson<long long> G(n + 2);
  for (int i = 0; i < n; i++){
    if (b[i] < 0){
      G.add_edge(n, i, -b[i]);
    } else {
      G.add_edge(i, n + 1, b[i]);
      ans += b[i];
    }
  }
  vector<int> p(101, -1);
  for (int i = 0; i < n; i++){
    for (int j = 1; j <= 100; j++){
      if (a[i] % j == 0 && p[j] != -1){
        G.add_edge(p[j], i, INF);
      }
    }
    p[a[i]] = i;
  }
  cout << ans - G.max_flow(n, n + 1) << endl;
}