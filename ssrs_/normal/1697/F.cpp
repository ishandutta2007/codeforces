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
struct two_sat{
  int N;
  vector<vector<int>> E;
  two_sat(int N): N(N), E(N * 2){
  }
  void add(int i, bool f){
    add(i, !f, i, f);
  }
  void add(int i, bool f, int j, bool g){
    E[i * 2 + (f ? 1 : 0)].push_back(j * 2 + (g ? 1 : 0));
    E[j * 2 + (g ? 0 : 1)].push_back(i * 2 + (f ? 0 : 1));
  }
  vector<bool> get(){
    strongly_connected_components G(E);
    vector<bool> ans(N);
    for (int i = 0; i < N; i++){
      if (G[i * 2] == G[i * 2 + 1]){
        return vector<bool>(0);
      } else if (G[i * 2] < G[i * 2 + 1]){
        ans[i] = true;
      } else {
        ans[i] = false;
      }
    }
    return ans;
  }
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, k;
    cin >> n >> m >> k;
    two_sat G(n * (k - 1));
    for (int j = 0; j < n; j++){
      for (int l = 0; l < k - 2; l++){
        G.add(j * (k - 1) + l + 1, true, j * (k - 1) + l, true);
      }
    }
    for (int j = 0; j < n - 1; j++){
      for (int l = 0; l < k - 1; l++){
        G.add(j * (k - 1) + l, true, (j + 1) * (k - 1) + l, true);
      }
    }
    for (int j = 0; j < m; j++){
      int t;
      cin >> t;
      if (t == 1){
        int i2, x;
        cin >> i2 >> x;
        i2--;
        x--;
        if (x == 0){
          G.add(i2 * (k - 1), true);
        } else if (x < k - 1){
          G.add(i2 * (k - 1) + (x - 1), true, i2 * (k - 1) + x, true);
        } else {
          G.add(i2 * (k - 1) + (k - 2), false);
        }
      }
      if (t == 2){
        int i2, j2, x;
        cin >> i2 >> j2 >> x;
        i2--;
        j2--;
        x -= 2;
        if (x < k - 1){
          G.add(i2 * (k - 1) + x, false);
          G.add(j2 * (k - 1) + x, false);
        }
        for (int l = 1; l < k; l++){
          if (x - l >= 0 && x - l < k - 1){
            G.add(i2 * (k - 1) + l - 1, true, j2 * (k - 1) + (x - l), false);
          }
        }
      }
      if (t == 3){
        int i2, j2, x;
        cin >> i2 >> j2 >> x;
        i2--;
        j2--;
        x -= 2;
        if (x >= k){
          G.add(i2 * (k - 1) + (x - k), true);
          G.add(j2 * (k - 1) + (x - k), true);
        }
        for (int l = 1; l < k; l++){
          if (x - l >= 0 && x - l < k - 1){
            G.add(i2 * (k - 1) + l - 1, false, j2 * (k - 1) + (x - l), true);
          }
        }
      }
    }
    vector<bool> ans = G.get();
    if (ans.empty()){
      cout << -1 << endl;
    } else {
      vector<int> ans2(n, 0);
      for (int j = 0; j < n; j++){
        for (int l = 0; l < k - 1; l++){
          if (ans[j * (k - 1) + l]){
            ans2[j]++;
          }
        }
      }
      for (int j = 0; j < n; j++){
        cout << ans2[j] + 1;
        if (j < n - 1){
          cout << ' ';
        }
      }
      cout << endl;
    }
  }
}