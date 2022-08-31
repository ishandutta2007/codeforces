#include <bits/stdc++.h>
using namespace std;
const int LOG = 19;
const int INF = 1100000000;
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
void dfs2(vector<vector<int>> &c, vector<int> &d, vector<int> &in, vector<int> &out, int v){
  in[v] = d.size();
  if (c[v].empty()){
    d.push_back(v);
  }
  for (int w : c[v]){
    dfs2(c, d, in, out, w);
  }
  out[v] = d.size();
}
struct monoid{
  int e, mn, mx;
  monoid(): e(-1), mn(INF), mx(-INF){
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.e = max(L.e, R.e);
  if (L.e == ans.e){
    ans.mn = min(ans.mn, L.mn);
    ans.mx = max(ans.mx, L.mx);
  }
  if (R.e == ans.e){
    ans.mn = min(ans.mn, R.mn);
    ans.mx = max(ans.mx, R.mx);
  }
  return ans;
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T query(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return E;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R){
		return query(L, R, 0, 0, N);
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
        while (1){
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
  vector<int> e(n);
  for (int i = 0; i < n; i++){
    cin >> e[i];
  }
  vector<int> a(n - 1), b(n - 1), c(n - 1), t(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> a[i] >> b[i] >> c[i] >> t[i];
    a[i]--;
    b[i]--;
  }
  vector<tuple<int, int, int>> S1(n - 1);
  for (int i = 0; i < n - 1; i++){
    S1[i] = make_tuple(c[i], a[i], b[i]);
  }
  sort(S1.begin(), S1.end(), greater<tuple<int, int, int>>());
  unionfind UF1(n);
  vector<int> p1(n * 2 - 1, -1);
  vector<int> cap(n * 2 - 1, 0);
  vector<int> curr1(n);
  for (int i = 0; i < n; i++){
    curr1[i] = i;
  }
  int V1 = n;
  for (int i = 0; i < n - 1; i++){
    int a2 = get<1>(S1[i]);
    int b2 = get<2>(S1[i]);
    int u = UF1.root(a2);
    int v = UF1.root(b2);
    p1[curr1[u]] = V1;
    p1[curr1[v]] = V1;
    UF1.unite(u, v);
    curr1[UF1.root(u)] = V1;
    cap[V1] = get<0>(S1[i]);
    V1++;
  }
  vector<vector<int>> c1(n * 2 - 1);
  for (int i = 0; i < n * 2 - 2; i++){
    c1[p1[i]].push_back(i);
  }
  vector<int> d1;
  vector<int> in(n * 2 - 1), out(n * 2 - 1);
  dfs2(c1, d1, in, out, n * 2 - 2);
  vector<tuple<int, int, int>> S2(n - 1);
  for (int i = 0; i < n - 1; i++){
    S2[i] = make_tuple(t[i], a[i], b[i]);
  }
  sort(S2.begin(), S2.end());
  unionfind UF2(n);
  vector<int> p2(n * 2 - 1, -1);
  vector<int> toll(n * 2 - 1, 0);
  vector<int> curr2(n);
  for (int i = 0; i < n; i++){
    curr2[i] = i;
  }
  int V2 = n;
  for (int i = 0; i < n - 1; i++){
    int a2 = get<1>(S2[i]);
    int b2 = get<2>(S2[i]);
    int u = UF2.root(a2);
    int v = UF2.root(b2);
    p2[curr2[u]] = V2;
    p2[curr2[v]] = V2;
    UF2.unite(u, v);
    curr2[UF2.root(u)] = V2;
    toll[V2] = get<0>(S2[i]);
    V2++;
  }
  vector<vector<int>> c2(n * 2 - 1);
  for (int i = 0; i < n * 2 - 2; i++){
    c2[p2[i]].push_back(i);
  }
  vector<int> d2;
  dfs(c2, d2, n * 2 - 2);
  vector<int> pos(n);
  for (int i = 0; i < n; i++){
    pos[d2[i]] = i;
  }
  vector<monoid> mo(n);
  for (int i = 0; i < n; i++){
    mo[i].e = e[d1[i]];
    mo[i].mn = pos[d1[i]];
    mo[i].mx = pos[d1[i]];
  }
  vector<vector<int>> pp(LOG, vector<int>(n * 2 - 1, -1));
  pp[0] = p1;
  for (int i = 0; i < LOG - 1; i++){
    for (int j = 0; j < n * 2 - 1; j++){
      if (pp[i][j] != -1){
        pp[i + 1][j] = pp[i][pp[i][j]];
      }
    }
  }
  segment_tree<monoid> ST(mo, f, monoid());
  heavy_light_decomposition T(p2, c2);
  for (int i = 0; i < q; i++){
    int v, x;
    cin >> v >> x;
    x--;
    int x2 = x;
    for (int j = LOG - 1; j >= 0; j--){
      if (pp[j][x] != -1){
        int w = pp[j][x];
        if (v <= cap[w]){
          x = w;
        }
      }
    }
    int L = in[x], R = out[x];
    monoid res = ST.query(L, R);
    int w = T.lca(d2[res.mn], d2[res.mx]);
    w = T.lca(w, x2);
    cout << res.e << ' ' << toll[w] << "\n";
  }
}