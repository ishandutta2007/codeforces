#include <bits/stdc++.h>
using namespace std;
struct heavy_light_decomposition{
  vector<int> p, d, sz, in, next;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c): p(p){
    int N = p.size();
    sz = vector<int>(N, 1);
    d = vector<int>(N, 0);
    dfs1(c);
    int t = 0;
    in = vector<int>(N);
    next = vector<int>(N, 0);
    dfs2(c, t);
  }
  void dfs1(vector<vector<int>> &c, int v = 0){
    for (int &w : c[v]){
      d[w] = d[v] + 1;
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v = 0){
    in[v] = t;
    t++;
    for (int w : c[v]){
      if (w == c[v][0]){
        next[w] = next[v];
      } else {
        next[w] = w;
      }
      dfs2(c, t, w);
    }
  }
  int lca(int v, int w){
    while (true){
      if (in[v] > in[w]){
        swap(v, w);
      }
      if (next[v] == next[w]){
        return v;
      }
      w = p[next[w]];
    }
  }
  vector<int> get_path(int u, int v){
    int w = lca(u, v);
    vector<int> ans1 = {u};
    while (ans1.back() != w){
      int x = p[ans1.back()];
      ans1.push_back(x);
    }
    vector<int> ans2 = {v};
    while (ans2.back() != w){
      int x = p[ans2.back()];
      ans2.push_back(x);
    }
    ans2.pop_back();
    reverse(ans2.begin(), ans2.end());
    for (int x : ans2){
      ans1.push_back(x);
    }
    return ans1;
  }
};
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
  int n, q;
  cin >> n >> q;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  vector<int> x(q), y(q);
  vector<string> s(q);
  for (int i = 0; i < q; i++){
    cin >> x[i] >> y[i] >> s[i];
    x[i]--;
    y[i]--;
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        Q.push(w);
      }
    }
  }
  heavy_light_decomposition HLD(p, c);
  vector<vector<int>> path(q);
  for (int i = 0; i < q; i++){
    path[i] = HLD.get_path(x[i], y[i]);
  }
  vector<bool> used(n, false);
  vector<char> c1(n, 'a'), c2(n, 'a');
  for (int i = 0; i < q; i++){
    int cnt = path[i].size();
    for (int j = 0; j < cnt; j++){
      int v = path[i][j];
      if (!used[v]){
        used[v] = true;
        c1[v] = s[i][j];
        c2[v] = s[i][cnt - 1 - j];
      }
    }
  }
  vector<vector<int>> E2((n + q) * 2);
  for (int i = 0; i < q; i++){
    int cnt = path[i].size();
    for (int j = 0; j < cnt; j++){
      int v = path[i][j];
      if (s[i][j] != c1[v]){
        E2[i * 2].push_back((q + v) * 2 + 1);
        E2[(q + v) * 2].push_back(i * 2 + 1);
      }
      if (s[i][j] != c2[v]){
        E2[i * 2].push_back((q + v) * 2);
        E2[(q + v) * 2 + 1].push_back(i * 2 + 1);
      }
      if (s[i][cnt - 1 - j] != c1[v]){
        E2[i * 2 + 1].push_back((q + v) * 2 + 1);
        E2[(q + v) * 2].push_back(i * 2);
      }
      if (s[i][cnt - 1 - j] != c2[v]){
        E2[i * 2 + 1].push_back((q + v) * 2);
        E2[(q + v) * 2 + 1].push_back(i * 2);
      }
    }
  }
  strongly_connected_components G(E2);
  bool ok = true;
  for (int i = 0; i < n + q; i++){
    if (G[i * 2] == G[i * 2 + 1]){
      ok = false;
    }
  }
  if (!ok){
    cout << "NO" << endl;
  } else {
    vector<char> ans(n);
    for (int i = 0; i < n; i++){
      if (G[(q + i) * 2] > G[(q + i) * 2 + 1]){
        ans[i] = c1[i];
      } else {
        ans[i] = c2[i];
      }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++){
      cout << ans[i];
    }
    cout << endl;
  }
}