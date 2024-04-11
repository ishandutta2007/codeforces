#include <bits/stdc++.h>
using namespace std;
struct monoid{
  int L, R;
  long long sum;
  monoid(){
    L = 0, R = 0, sum = -1;
  }
  monoid(int x){
    L = x, R = x, sum = 0;
  }
};
monoid merge(monoid A, monoid B){
  if (A.sum == -1){
    return B;
  }
  if (B.sum == -1){
    return A;
  }
  monoid ans;
  ans.L = A.L;
  ans.R = B.R;
  ans.sum = A.sum + B.sum + max(abs(A.R + B.L), abs(A.R - B.L));
  return ans;
}
struct segment_tree{
  int N;
  array<vector<monoid>, 2> ST;
  segment_tree(){
  }
  segment_tree(vector<int> &A){
    int N2 = A.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    ST[0] = vector<monoid>(N * 2 - 1);
    ST[1] = vector<monoid>(N * 2 - 1);
    for (int i = 0; i < N2; i++){
      ST[0][N - 1 + i] = monoid(A[i]);
      ST[1][N - 1 + i] = monoid(A[i]);
    }
    for (int i = N - 2; i >= 0; i--){
      ST[0][i] = merge(ST[0][i * 2 + 1], ST[0][i * 2 + 2]);
      ST[1][i] = merge(ST[1][i * 2 + 2], ST[1][i * 2 + 1]);
    }
  }
  void update(int i, int x){
    i += N - 1;
    ST[0][i] = monoid(x);
    ST[1][i] = monoid(x);
    while (i > 0){
      i = (i - 1) / 2;
      ST[0][i] = merge(ST[0][i * 2 + 1], ST[0][i * 2 + 2]);
      ST[1][i] = merge(ST[1][i * 2 + 2], ST[1][i * 2 + 1]);
    }
  }
  monoid fold(int L, int R, int d, int i, int l, int r){
    if (r <= L || R <= l){
      return monoid();
    } else if (L <= l && r <= R){
      return ST[d][i];
    } else {
      int m = (l + r) / 2;
      if (d == 0){
        return merge(fold(L, R, d, i * 2 + 1, l, m), fold(L, R, d, i * 2 + 2, m, r));
      } else {
        return merge(fold(L, R, d, i * 2 + 2, m, r), fold(L, R, d, i * 2 + 1, l, m));
      }
    }
  }
  monoid fold(int L, int R, int d){
    return fold(L, R, d, 0, 0, N);
  }
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  segment_tree ST;
  heavy_light_decomposition(vector<int> &p, vector<vector<int>> &c, vector<int> &a): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c);
    in = vector<int>(N);
    next = vector<int>(N);
    next[0] = 0;
    int t = 0;
    dfs2(c, t);
    vector<int> a2(N);
    for (int i = 0; i < N; i++){
      a2[in[i]] = a[i];
    }
    ST = segment_tree(a2);
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
  void update(int v, int x){
    ST.update(in[v], x);
  }
  monoid query(int u, int v){
    int w = lca(u, v);
    monoid ans1;
    while (next[u] != next[w]){
      ans1 = merge(ans1, ST.fold(in[next[u]], in[u] + 1, 1));
      u = p[next[u]];
    }
    ans1 = merge(ans1, ST.fold(in[w], in[u] + 1, 1));
    monoid ans2;
    while (next[v] != next[w]){
      ans2 = merge(ST.fold(in[next[v]], in[v] + 1, 0), ans2);
      v = p[next[v]];
    }
    ans2 = merge(ST.fold(in[w] + 1, in[v] + 1, 0), ans2);
    return merge(ans1, ans2);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++){
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    E[s].push_back(t);
    E[t].push_back(s);
  }
  vector<int> pr(n, -1);
  vector<vector<int>> ch(n);
  queue<int> Q;
  Q.push(0);
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : E[v]){
      if (w != pr[v]){
        pr[w] = v;
        ch[v].push_back(w);
        Q.push(w);
      }
    }
  }
  heavy_light_decomposition T(pr, ch, a);
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int u, c;
      cin >> u >> c;
      u--;
      T.update(u, c);
    }
    if (t == 2){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      cout << T.query(u, v).sum << "\n";
    }
  }
}