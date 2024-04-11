#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000;
struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};
void dfs(vector<vector<int>> &c, vector<int> &d, int v){
  if (c[v].empty()){
    d.push_back(v);
  }
  for (int w : c[v]){
    dfs(c, d, w);
  }
}
struct lazy_segment_tree{
  int N;
  vector<int> all_mn, all_mx, on_mn, on_mx;
  vector<int> lazy;
  lazy_segment_tree(vector<int> &A){
    int N2 = A.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    all_mn = vector<int>(N * 2 - 1, INF);
    all_mx = vector<int>(N * 2 - 1, -INF);
    on_mn = vector<int>(N * 2 - 1, INF);
    on_mx = vector<int>(N * 2 - 1, -INF);
    for (int i = 0; i < N2; i++){
      all_mn[N - 1 + i] = A[i];
      all_mx[N - 1 + i] = A[i];
    }
    for (int i = N - 2; i >= 0; i--){
      all_mn[i] = min(all_mn[i * 2 + 1], all_mn[i * 2 + 2]);
      all_mx[i] = max(all_mx[i * 2 + 1], all_mx[i * 2 + 2]);
    }
    lazy = vector<int>(N * 2 - 1, -1);
  }
  void push(int i){
    if (lazy[i] != -1){
      if (i < N - 1){
        lazy[i * 2 + 1] = lazy[i];
        lazy[i * 2 + 2] = lazy[i];
      }
      if (lazy[i] == 0){
        on_mn[i] = INF;
        on_mx[i] = -INF;
      }
      if (lazy[i] == 1){
        on_mn[i] = all_mn[i];
        on_mx[i] = all_mx[i];
      }
      lazy[i] = -1;
    }
  }
  void range_update(int L, int R, int x, int i, int l, int r){
    push(i);
    if (r <= L || R <= l){
      return;
    } else if (L <= l && r <= R){
      lazy[i] = x;
      push(i);
    } else {
      int m = (l + r) / 2;
      range_update(L, R, x, i * 2 + 1, l, m);
      range_update(L, R, x, i * 2 + 2, m, r);
      on_mn[i] = min(on_mn[i * 2 + 1], on_mn[i * 2 + 2]);
      on_mx[i] = max(on_mx[i * 2 + 1], on_mx[i * 2 + 2]);
    }
  }
  void range_update(int L, int R, int x){
    range_update(L, R, x, 0, 0, N);
  }
  pair<int, int> all_minmax(){
    push(0);
    return make_pair(on_mn[0], on_mx[0]);
  }
};
struct heavy_light_decomposition{
    vector<int> p, sz, in, next;
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
    heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c): p(p){
        int N = p.size();
        sz = vector<int>(N);
        dfs1(c, N - 1);
        in = vector<int>(N);
        next = vector<int>(N, N - 1);
        int t = 0;
        dfs2(c, t, N - 1);
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
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<tuple<int, int, int>> E(n - 1);
  for (int i = 0; i < n - 1; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[i] = make_tuple(w, u, v);
  }
  sort(E.begin(), E.end());
  unionfind UF(n);
  vector<int> p(n * 2 - 1, -1);
  vector<int> cr(n);
  for (int i = 0; i < n; i++){
    cr[i] = i;
  }
  vector<int> W(n * 2 - 1, -1);
  int V = n;
  for (int i = 0; i < n - 1; i++){
    int w = get<0>(E[i]);
    int u = get<1>(E[i]);
    int v = get<2>(E[i]);
    u = UF.root(u);
    v = UF.root(v);
    p[cr[u]] = V;
    p[cr[v]] = V;
    UF.unite(u, v);
    cr[UF.root(u)] = V;
    W[V] = w;
    V++;
  }
  vector<vector<int>> c(V);
  for (int i = 0; i < V - 1; i++){
    c[p[i]].push_back(i);
  }
  vector<int> d;
  dfs(c, d, V - 1);
  vector<int> pos(n);
  for (int i = 0; i < n; i++){
    pos[d[i]] = i;
  }
  lazy_segment_tree ST(pos);
  heavy_light_decomposition T(p, c);
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int l, r;
      cin >> l >> r;
      l--;
      ST.range_update(l, r, 1);
    }
    if (t == 2){
      int l, r;
      cin >> l >> r;
      l--;
      ST.range_update(l, r, 0);
    }
    if (t == 3){
      int x;
      cin >> x;
      x--;
      pair<int, int> R = ST.all_minmax();
      if (R.first == INF){
        cout << -1 << "\n";
      } else {
        int v = T.lca(d[R.first], d[R.second]);
        v = T.lca(v, x);
        cout << W[v] << "\n";
      }
    }
  }
}