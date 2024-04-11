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
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
  }
  vector<vector<int>> id(n, vector<int>(m, -1));
  int cnt = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (S[i][j] == '#'){
        id[i][j] = cnt;
        cnt++;
      }
    }
  }
  vector<vector<int>> c(m);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (S[i][j] == '#'){
        c[j].push_back(i);
      }
    }
  }
  vector<vector<int>> E(cnt);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m; j++){
      if (S[i][j] == '#'){
        int u = id[i][j];
        if (i > 0){
          if (S[i - 1][j] == '#'){
            int v = id[i - 1][j];
            E[u].push_back(v);
          }
        }
        if (j > 0){
          auto itr = lower_bound(c[j - 1].begin(), c[j - 1].end(), i);
          if (itr != c[j - 1].end()){
            int v = id[*itr][j - 1];
            E[u].push_back(v);
          }
        }
        if (j < m - 1){
          auto itr = lower_bound(c[j + 1].begin(), c[j + 1].end(), i);
          if (itr != c[j + 1].end()){
            int v = id[*itr][j + 1];
            E[u].push_back(v);
          }
        }
        auto itr = upper_bound(c[j].begin(), c[j].end(), i);
        if (itr != c[j].end()){
          int v = id[*itr][j];
          E[u].push_back(v);
        }
      }
    }
  }
  strongly_connected_components G(E);
  int cnt2 = G.size();
  vector<bool> ok(cnt2, false);
  for (int i = 0; i < cnt; i++){
    for (int j : E[i]){
      if (G[i] != G[j]){
        ok[G[j]] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < cnt2; i++){
    if (!ok[i]){
      ans++;
    }
  }
  cout << ans << endl;
}