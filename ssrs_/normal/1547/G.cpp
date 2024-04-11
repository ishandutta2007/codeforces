#include <bits/stdc++.h>
using namespace std;
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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> E(n);
    for (int j = 0; j < m; j++){
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      E[a].push_back(b);
    }
    strongly_connected_components G(E);
    int cnt = G.size();
    vector<vector<int>> E2(cnt);
    vector<bool> f(cnt, false);
    for (int j = 0; j < n; j++){
      for (int k : E[j]){
        if (G[j] == G[k]){
          f[G[j]] = true;
        } else {
          E2[G[j]].push_back(G[k]);
        }
      }
    }
    vector<int> dp(cnt, 0);
    if (f[G[0]]){
      dp[G[0]] = -1;
    } else {
      dp[G[0]] = 1;
    }
    for (int j = 0; j < cnt; j++){
      if (dp[j] != 0){
        for (int k : E2[j]){
          if (f[k]){
            dp[k] = -1;
          } else {
            if (dp[j] == -1){
              dp[k] = dp[j];
            } else if (dp[j] == 2){
              if (dp[k] != -1){
                dp[k] = dp[j];
              }
            } else if (dp[j] == 1){
              if (dp[k] == 0){
                dp[k] = 1;
              } else if (dp[k] == 1){
                dp[k] = 2;
              }
            }
          }
        }
      }
    }
    for (int j = 0; j < n; j++){
      cout << dp[G[j]];
      if (j < n - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}