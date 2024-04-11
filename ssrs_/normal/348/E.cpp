#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(){
	}
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans += ST[k];
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  dual_segment_tree<int> ST;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, int r): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c, r);
    int t = 0;
    in = vector<int>(N);
    next = vector<int>(N, r);
    dfs2(c, t, r);
    ST = dual_segment_tree<int>(N);
  }
  void dfs1(vector<vector<int>> &c, int v){
    sz[v] = 1;
    for (int &w : c[v]){
      dfs1(c, w);
      sz[v] += sz[w];
      if (sz[w] > sz[c[v][0]]){
        swap(w, c[v][0]);
      }
    }
  }
  void dfs2(vector<vector<int>> &c, int &t, int v){
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
  int lca(int u, int v){
    while (true){
      if (in[u] > in[v]){
        swap(u, v);
      }
      if (next[u] == next[v]){
        return u;
      }
      v = p[next[v]];
    }
  }
  int lca(int u, int v, int w){
    return lca(u, v) ^ lca(v, w) ^ lca(w, u);
  }
  void path_add(int u, int v){
    int w = lca(u, v);
    while (next[u] != next[w]){
      ST.range_add(in[next[u]], in[u] + 1, 1);
      u = p[next[u]];
    }
    ST.range_add(in[w], in[u] + 1, 1);
    while (next[v] != next[w]){
      ST.range_add(in[next[v]], in[v] + 1, 1);
      v = p[next[v]];
    }
    ST.range_add(in[w] + 1, in[v] + 1, 1);
  }
  int operator [](int v){
    return ST[in[v]];
  }
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> id;
  vector<bool> mo(n, false);
  for (int i = 0; i < m; i++){
    int x;
    cin >> x;
    x--;
    id.push_back(x);
    mo[x] = true;
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    E[a].push_back(make_pair(c, b));
    E[b].push_back(make_pair(c, a));
  }
  vector<int> d1(n, -1);
  d1[id[0]] = 0;
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  queue<int> Q1;
  Q1.push(id[0]);
  while (!Q1.empty()){
    int v = Q1.front();
    Q1.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (d1[w] == -1){
        p[w] = v;
        c[v].push_back(w);
        d1[w] = d1[v] + P.first;
        Q1.push(w);
      }
    }
  }
  int s = id[0];
  for (int x : id){
    if (d1[x] > d1[s]){
      s = x;
    }
  }
  vector<int> ds(n, -1);
  ds[s] = 0;
  queue<int> Q2;
  Q2.push(s);
  while (!Q2.empty()){
    int v = Q2.front();
    Q2.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (ds[w] == -1){
        ds[w] = ds[v] + P.first;
        Q2.push(w);
      }
    }
  }
  int t = id[0];
  for (int x : id){
    if (ds[x] > ds[t]){
      t = x;
    }
  }
  vector<int> dt(n, -1);
  dt[t] = 0;
  queue<int> Q3;
  Q3.push(t);
  while (!Q3.empty()){
    int v = Q3.front();
    Q3.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (dt[w] == -1){
        dt[w] = dt[v] + P.first;
        Q3.push(w);
      }
    }
  }
  heavy_light_decomposition HLD(p, c, id[0]);
  int l1 = t;
  for (int i = 0; i < n; i++){
    if (mo[i] && ds[i] == ds[t]){
      l1 = HLD.lca(s, l1, i);
    }
  }
  int l2 = s;
  for (int i = 0; i < n; i++){
    if (mo[i] && dt[i] == dt[s]){
      l2 = HLD.lca(t, l2, i);
    }
  }
  for (int x : id){
    if (ds[x] < dt[x]){
      HLD.path_add(x, l1);
    }
    if (dt[x] < ds[x]){
      HLD.path_add(x, l2);
    }
    if (ds[x] == dt[x]){
      int l = HLD.lca(x, s, t);
      HLD.path_add(x, l);
    }
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; i++){
    cnt[i] = HLD[i];
  }
  int ans1 = 0;
  for (int i = 0; i < n; i++){
    if (!mo[i]){
      ans1 = max(ans1, cnt[i]);
    }
  }
  int ans2 = 0;
  for (int i = 0; i < n; i++){
    if (!mo[i] && cnt[i] == ans1){
      ans2++;
    }
  }
  cout << ans1 << ' ' << ans2 << endl;
}