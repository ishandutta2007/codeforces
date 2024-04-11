#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000001;
const long long INF2 = 1000000000000;
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  vector<long long> x(k), y(k);
  for (int i = 0; i < k; i++){
    cin >> x[i] >> y[i];
  }
  ford_fulkerson<int> G(n * 2 + 2);
  for (int i = 0; i < n; i++){
    G.add_edge(n * 2, i, 1);
    G.add_edge(n + i, n * 2 + 1, 1);
  }
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      G.add_edge(i, n + j, 1);
    }
  }
  int F = G.max_flow(n * 2, n * 2 + 1);
  vector<vector<bool>> ok(n, vector<bool>(2, true));
  vector<int> id(F);
  for (int i = 0; i < F; i++){
    int ans = INF;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < 2; k++){
        if (ok[j][k]){
          ok[j][k] = false;
          ford_fulkerson<int> G2(n * 2 + 2);
          for (int l = 0; l < n; l++){
            if (ok[l][0]){
              G2.add_edge(n * 2, l, 1);
            }
            if (ok[l][1]){
              G2.add_edge(n + l, n * 2 + 1, 1);
            }
            for (int v : E[l]){
              G2.add_edge(l, n + v, 1);
            }
          }
          int F2 = G2.max_flow(n * 2, n * 2 + 1);
          if (F2 == F - (i + 1)){
            if (k == 0){
              ans = j + 1;
            } else {
              ans = -(j + 1);
            }
          }
          ok[j][k] = true;
        }
      }
    }
    assert(ans != INF);
    id[i] = ans;
    if (ans > 0){
      ok[ans - 1][0] = false;
    } else {
      ok[-1 - ans][1] = false;
    }
  }
  int mn = n - F;
  if (k < mn){
    cout << k << endl;
    for (int i = 0; i < k; i++){
      cout << 0;
      if (i < k - 1){
        cout << ' ';
      }
    }
    cout << endl;
  } else {
    int cnt = k - mn + 1;
    vector<vector<long long>> dp(k + 1, vector<long long>(cnt + 1, -INF2));
    dp[0][0] = 0;
    vector<vector<long long>> prv(k + 1, vector<long long>(cnt + 1, -1));
    for (int i = 0; i < k; i++){
      for (int j = 0; j <= cnt; j++){
        for (int k = 0; k <= cnt - j; k++){
          if ((i + 1) - (j + k) < mn){
            long long t = max(x[i] - k * y[i], (long long) 0);
            if (dp[i + 1][j + k] < dp[i][j] + t){
              dp[i + 1][j + k] = dp[i][j] + t;
              prv[i + 1][j + k] = j;
            }
          }
        }
      }
    }
    vector<int> cnt2(k);
    int c = cnt;
    for (int i = k; i >= 1; i--){
      int a = c - prv[i][c];
      cnt2[i - 1] = a;
      c -= a;
    }
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < k; i++){
      for (int j = sum; j < sum + cnt2[i]; j++){
        ans.push_back(id[j]);
      }
      sum += cnt2[i];
      ans.push_back(0);
    }
    int a = ans.size();
    cout << a << endl;
    for (int i = 0; i < a; i++){
      cout << ans[i];
      if (i < a - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}