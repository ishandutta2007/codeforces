#include <bits/stdc++.h>
using namespace std;
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
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> ST;
	vector<T> lazy;
	lazy_segment_tree(){
	}
	lazy_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, -1);
	}
	void eval(int i, int l, int r){
		if (lazy[i] != -1){
			if (i < N - 1){
				lazy[i * 2 + 1] = lazy[i];
				lazy[i * 2 + 2] = lazy[i];
			}
			ST[i] = lazy[i] * (r - l);
			lazy[i] = -1;
		}
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		eval(i, l, r);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] = x;
			eval(i, l, r);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
			ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
	}
	T range_sum(int L, int R, int i, int l, int r){
		eval(i, l, r);
		if (R <= l || r <= L){
			return 0;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return range_sum(L, R, i * 2 + 1, l, m) + range_sum(L, R, i * 2 + 2, m, r);
		}
	}
	T range_sum(int L, int R){
		return range_sum(L, R, 0, 0, N);
	}
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  lazy_segment_tree<int> ST;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c);
    in = vector<int>(N);
    next = vector<int>(N, 0);
    int t = 0;
    dfs2(c, t);
    ST = lazy_segment_tree<int>(N);
  }
  void dfs1(vector<vector<int>> &c, int v = 0){
    sz[v] = 1;
    for (int &w : c[v]){
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
  void path_update(int u, int v){
    int w = lca(u, v);
    while (next[u] != next[w]){
      ST.range_update(in[next[u]], in[u] + 1, 1);
      u = p[next[u]];
    }
    ST.range_update(in[w] + 1, in[u] + 1, 1);
    while (next[v] != next[w]){
      ST.range_update(in[next[v]], in[v] + 1, 1);
      v = p[next[v]];
    }
    ST.range_update(in[w] + 1, in[v] + 1, 1);
  }
  int path_sum(int u, int v){
    int w = lca(u, v);
    int ans = 0;
    while (next[u] != next[w]){
      ans += ST.range_sum(in[next[u]], in[u] + 1);
      u = p[next[u]];
    }
    ans += ST.range_sum(in[w] + 1, in[u] + 1);
    while (next[v] != next[w]){
      ans += ST.range_sum(in[next[v]], in[v] + 1);
      v = p[next[v]];
    }
    ans += ST.range_sum(in[w] + 1, in[v] + 1);
    return ans;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(q), b(q), x(q);
  for (int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> x[i];
    a[i]--;
    b[i]--;
  }
  unionfind UF(n);
  vector<bool> tree(q, false);
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < q; i++){
    if (!UF.same(a[i], b[i])){
      UF.unite(a[i], b[i]);
      tree[i] = true;
      E[a[i]].push_back(make_pair(x[i], b[i]));
      E[b[i]].push_back(make_pair(x[i], a[i]));
    }
  }
  for (int i = 1; i < n; i++){
    if (!UF.same(0, i)){
      UF.unite(0, i);
      E[0].push_back(make_pair(0, i));
      E[i].push_back(make_pair(i, 0));
    }
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> s(n, 0);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (auto P : E[v]){
      int w = P.second;
      if (w != p[v]){
        p[w] = v;
        c[v].push_back(w);
        s[w] = s[v] + P.first;
        Q.push(w);
      }
    }
  }
  heavy_light_decomposition T(p, c);
  vector<bool> ans = tree;
  for (int i = 0; i < q; i++){
    if (!tree[i]){
      if ((s[a[i]] % 2 - s[b[i]] % 2 + 2 + x[i]) % 2 == 1){
        if (T.path_sum(a[i], b[i]) == 0){
          ans[i] = true;
          T.path_update(a[i], b[i]);
        }
      }
    }
  }
  for (int i = 0; i < q; i++){
    if (ans[i]){
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
}