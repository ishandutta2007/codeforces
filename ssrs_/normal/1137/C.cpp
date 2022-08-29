#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
struct strongly_connected_components{
	vector<vector<int>> ans;
	vector<int> scc;
	void dfs1(vector<vector<int>> &E, vector<int> &t, vector<bool> &used, int v){
		for (int w : E[v]){
			if (!used[w]){
				used[w] = true;
				dfs1(E, t, used, w);
			}
		}
		t.push_back(v);
	}
	void dfs2(vector<vector<int>> &E2, vector<bool> &used2, int v){
		ans.back().push_back(v);
		for (int w : E2[v]){
			if (!used2[w]){
				used2[w] = true;
				dfs2(E2, used2, w);
			}
		}
	}
	strongly_connected_components(vector<vector<int>> &E){
		int N = E.size();
		vector<vector<int>> E2(N);
		for (int i = 0; i < N; i++){
			for (int j : E[i]){
				E2[j].push_back(i);
			}
		}
		vector<int> t;
		vector<bool> used(N, false);
		for (int i = 0; i < N; i++){
			if (!used[i]){
				used[i] = true;
				dfs1(E, t, used, i);
			}
		}
		reverse(t.begin(), t.end());
		vector<bool> used2(N, false);
		scc = vector<int>(N);
		int cnt = 0;
		for (int i = 0; i < N; i++){
			if (!used2[t[i]]){
				used2[t[i]] = true;
				ans.push_back(vector<int>());
				dfs2(E2, used2, t[i]);
				for (int j : ans.back()){
					scc[j] = cnt;
				}
				cnt++;
			}
		}
	}
	int operator [](int k){
		return scc[k];
	}
	int size(){
		return ans.size();
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, d;
  cin >> n >> m >> d;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
  }
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  strongly_connected_components SCC(E);
  int cnt = SCC.size();
  vector<vector<int>> g(cnt);
  for (int i = 0; i < n; i++){
    g[SCC[i]].push_back(i);
  }
  vector<vector<int>> E1(n), E2(n);
  for (int i = 0; i < n; i++){
    for (int j : E[i]){
      if (SCC[i] == SCC[j]){
        E1[i].push_back(j);
      } else {
        E2[i].push_back(j);
      }
    }
  }
  vector<vector<int>> dp(n, vector<int>(d, -INF));
  dp[0][0] = 0;
  vector<int> id(n);
  int ans = 0;
  for (int i = 0; i < cnt; i++){
    int vc = g[i].size();
    for (int j = 0; j < vc; j++){
      id[g[i][j]] = j;
    }
    vector<vector<bool>> used(vc, vector<bool>(d, false));
    for (int j = 0; j < vc; j++){
      for (int k = 0; k < d; k++){
        if (!used[j][k]){
          used[j][k] = true;
          vector<pair<int, int>> b;
          vector<bool> m(vc, false);
          int mx = -INF, add = 0;
          queue<pair<int, int>> Q;
          Q.push(make_pair(j, k));
          while (!Q.empty()){
            int v = Q.front().first;
            int p = Q.front().second;
            Q.pop();
            mx = max(mx, dp[g[i][v]][p]);
            b.push_back(make_pair(v, p));
            if (S[g[i][v]][p] == '1' && !m[v]){
              add++;
              m[v] = true;
            }
            for (int w : E1[g[i][v]]){
              int w2 = id[w];
              int p2 = (p + 1) % d;
              if (!used[w2][p2]){
                used[w2][p2] = true;
                Q.push(make_pair(w2, p2));
              }
            }
          }
          ans = max(ans, mx + add);
          int sz = b.size();
          for (int l = 0; l < sz; l++){
            int v = b[l].first;
            int p = b[l].second;
            int p2 = (p + 1) % d;
            for (int w : E2[g[i][v]]){
              dp[w][p2] = max(dp[w][p2], mx + add);
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}