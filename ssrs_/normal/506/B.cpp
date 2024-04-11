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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> E(n);
  for (int i = 0; i < m; i++){
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    E[a].push_back(b);
  }
  strongly_connected_components S(E);
  int cnt = S.size();
  vector<int> sz(cnt, 0);
  vector<vector<int>> E2(cnt);
  for (int i = 0; i < n; i++){
    sz[S[i]]++;
    for (int j : E[i]){
      if (S[i] != S[j]){
        E2[S[i]].push_back(S[j]);
        E2[S[j]].push_back(S[i]);
      }
    }
  }
  int ans = 0;
  vector<bool> used(cnt, false);
  for (int i = 0; i < cnt; i++){
    if (!used[i]){
      used[i] = true;
      int tmp = 1;
      int sum = sz[i];
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E2[v]){
          if (!used[w]){
            used[w] = true;
            tmp++;
            sum += sz[w];
            Q.push(w);
          }
        }
      }
      if (tmp != sum){
        ans += sum;
      } else {
        ans += tmp - 1;
      }
    }
  }
  cout << ans << endl;
}