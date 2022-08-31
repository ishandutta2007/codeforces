#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
const int LOG = 17;
const int INF = 1000000;
vector<int> f(vector<int> a, vector<int> b, int x = 10){
  if (a.empty()){
    if (b.size() > x){
      b.resize(x);
    }
    return b;
  }
  if (b.empty()){
    if (a.size() > x){
      a.resize(x);
    }
    return a;
  }
  a.push_back(INF);
  b.push_back(INF);
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  vector<int> c;
  c.reserve(x);
  while (a.size() > 1 || b.size() > 1){
    if (a.back() < b.back()){
      c.emplace_back(a.back());
      a.pop_back();
    } else {
      c.emplace_back(b.back());
      b.pop_back();
    }
    if (c.size() == x){
      return c;
    }
  }
  return c;
}
struct segment_tree{
	int N;
	vector<vector<int>> ST;
	segment_tree(){
	}
	segment_tree(vector<vector<int>> &A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<vector<int>>(N * 2 - 1);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	vector<int> query(int L, int R, int i, int l, int r, int x = 10){
		if (R <= l || r <= L){
			return vector<int>();
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return f(query(L, R, i * 2 + 1, l, m, x), query(L, R, i * 2 + 2, m, r, x), x);
		}
	}
	vector<int> query(int L, int R, int x = 10){
		return query(L, R, 0, 0, N, x);
	}
};
struct lowest_common_ancestor{
	vector<int> d;
	vector<vector<int>> next;
	lowest_common_ancestor(){
	}
	lowest_common_ancestor(vector<int> &p, vector<vector<int>> &c){
		int N = p.size();
		d = vector<int>(N, 0);
		queue<int> Q;
		Q.push(0);
		while (!Q.empty()){
			int v = Q.front();
			Q.pop();
			for (int w : c[v]){
				d[w] = d[v] + 1;
				Q.push(w);
			}
		}
		next = vector<vector<int>>(LOG, vector<int>(N, -1));
		for (int i = 0; i < N; i++){
			next[0][i] = p[i];
		}
		for (int i = 1; i < LOG; i++){
			for (int j = 0; j < N; j++){
				if (next[i - 1][j] != -1){
					next[i][j] = next[i - 1][next[i - 1][j]];
				}
			}
		}
	}
	int lca(int v, int w){
		if (d[v] > d[w]){
			swap(v, w);
		}
		int diff = d[w] - d[v];
		for (int i = 0; i < LOG; i++){
			if (diff >> i & 1){
				w = next[i][w];
			}
		}
		if (v == w){
			return v;
		}
		for (int i = LOG - 1; i >= 0; i--){
			if (next[i][v] != next[i][w]){
				v = next[i][v];
				w = next[i][w];
			}
		}
		return next[0][v];
	}
};
struct heavy_light_decomposition{
	lowest_common_ancestor LCA;
	vector<int> p;
	vector<int> sz, in, next;
	int t;
	segment_tree ST;
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
	void dfs2(vector<vector<int>> &c, int v = 0){
		in[v] = t;
		t++;
		for (int w : c[v]){
			if (w == c[v][0]){
				next[w] = next[v];
			} else {
				next[w] = w;
			}
			dfs2(c, w);
		}
	}
	heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, vector<vector<int>> &A): p(p){
		LCA = lowest_common_ancestor(p, c);
		int N = p.size();
		in = vector<int>(N, -1);
		sz = vector<int>(N, -1);
		next = vector<int>(N, 0);
		t = 0;
		dfs1(c);
		dfs2(c);
		vector<vector<int>> tmp(N);
		for (int i = 0; i < N; i++){
			tmp[in[i]] = A[i];
		}
		ST = segment_tree(tmp);
	}
	vector<int> query(int u, int v, int x){
		int w = LCA.lca(u, v);
		vector<int> ans;
		while (next[u] != next[w]){
			ans = f(ans, ST.query(in[next[u]], in[u] + 1, x), x);
			u = p[next[u]];
		}
		ans = f(ans, ST.query(in[w], in[u] + 1, x), x);
		while (next[v] != next[w]){
			ans = f(ST.query(in[next[v]], in[v] + 1, x), ans, x);
			v = p[next[v]];
		}
		ans = f(ST.query(in[w] + 1, in[v] + 1, x), ans, x);
		return ans;
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int v, u;
    cin >> v >> u;
    v--;
    u--;
    E[v].push_back(u);
    E[u].push_back(v);
  }
  vector<int> c(m);
  for (int i = 0; i < m; i++){
    cin >> c[i];
    c[i]--;
  }
  vector<int> p(n, -1);
  vector<vector<int>> ch(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != p[v]){
        p[w] = v;
        ch[v].push_back(w);
        Q.push(w);
      }
    }
  }
  vector<vector<int>> A(n);
  for (int i = 0; i < m; i++){
    A[c[i]].push_back(i + 1);
  }
  for (int i = 0; i < n; i++){
    sort(A[i].begin(), A[i].end());
  }
  heavy_light_decomposition HLD(p, ch, A);
  for (int i = 0; i < q; i++){
    int v, u, a;
    cin >> v >> u >> a;
    v--;
    u--;
    vector<int> t = HLD.query(v, u, a);
    int k = min((int) t.size(), a);
    cout << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << t[j];
    }
    cout << "\n";
  }
}