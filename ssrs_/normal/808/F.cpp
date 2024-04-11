#include <bits/stdc++.h>
using namespace std;
const int MAX = 200000;
const int INF = 100000000;
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
  vector<bool> prime(MAX + 1, true);
  for (int i = 2; i <= MAX; i++){
    if (prime[i]){
      for (int j = i * 2; j <= MAX; j += i){
        prime[j] = false;
      }
    }
  }
  int n, k;
  cin >> n >> k;
  vector<int> p(n), c(n), l(n);
  for (int i = 0; i < n; i++){
    cin >> p[i] >> c[i] >> l[i];
  }
  int tv = n + 1, fv = 0;
  while (tv - fv > 1){
    int mid = (tv + fv) / 2;
    int id = -1;
    for (int i = 0; i < n; i++){
      if (c[i] == 1 && l[i] <= mid){
        if (id == -1){
          id = i;
        } else if (p[i] > p[id]){
          id = i;
        }
      }
    }
    vector<bool> ok(n, true);
    for (int i = 0; i < n; i++){
      if (l[i] > mid){
        ok[i] = false;
      } else if (c[i] == 1 && i != id){
        ok[i] = false;
      }
    }
    ford_fulkerson<int> G(n + 2);
    int sum = 0;
    for (int i = 0; i < n; i++){
      if (ok[i]){
        sum += p[i];
        if (c[i] % 2 == 0){
          G.add_edge(n, i, p[i]);
        } else {
          G.add_edge(i, n + 1, p[i]);
        }
      }
    }
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        if (ok[i] && ok[j] && prime[c[i] + c[j]]){
          if (c[i] % 2 == 1){
            G.add_edge(j, i, INF);
          } else {
            G.add_edge(i, j, INF);
          }
        }
      }
    }
    long long F = G.max_flow(n, n + 1);
    long long mx = sum - F;
    if (mx >= k){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  if (tv == n + 1){
    cout << -1 << endl;
  } else {
    cout << tv << endl;
  }
}