#include <bits/stdc++.h>
using namespace std;
vector<int> f;
struct monoid{
  int L, M, R;
  bool all;
  monoid(){
  }
  monoid(int x){
    if (x == 0){
      L = 0;
      M = 0;
      R = 0;
      all = false;
    } else if (x == 1){
      L = 1;
      M = 0;
      R = 1;
      all = true;
    } else {
      L = 0;
      M = 0;
      R = 0;
      all = true;
    }
  }
  int get(){
    if (all){
      return f[L];
    } else {
      return f[L] + M + f[R];
    }
  }
};
monoid merge(monoid A, monoid B){
  monoid ans;
  if (A.all){
    ans.L = A.L + B.L;
  } else {
    ans.L = A.L;
  }
  if (B.all){
    ans.R = A.R + B.R;
  } else {
    ans.R = B.R;
  }
  ans.M = A.M + B.M;
  if (!A.all && !B.all){
    ans.M += f[A.R + B.L];
  }
  ans.all = A.all && B.all;
  return ans;
}
struct segment_tree{
  int N;
  vector<monoid> STL, STR;
  segment_tree(){
  }
  segment_tree(int N2){
    N = 1;
    while (N < N2){
      N *= 2;
    }
    STL = vector<monoid>(N * 2 - 1);
    STR = vector<monoid>(N * 2 - 1);
    for (int i = 0; i < N2; i++){
      STL[N - 1 + i] = monoid(1);
      STR[N - 1 + i] = monoid(1);
    }
    for (int i = N2; i < N; i++){
      STL[N - 1 + i] = monoid(-1);
      STR[N - 1 + i] = monoid(-1);
    }
    for (int i = N - 2; i >= 0; i--){
      STL[i] = merge(STL[i * 2 + 1], STL[i * 2 + 2]);
      STR[i] = merge(STR[i * 2 + 2], STR[i * 2 + 1]);
    }
  }
  void update(int i){
    i += N - 1;
    STL[i] = monoid(0);
    STR[i] = monoid(0);
    while (i > 0){
      i = (i - 1) / 2;
      STL[i] = merge(STL[i * 2 + 1], STL[i * 2 + 2]);
      STR[i] = merge(STR[i * 2 + 2], STR[i * 2 + 1]);
    }
  }
  monoid range_fold(int L, int R, int d, int i, int l, int r){
    if (r <= L || R <= l){
      return monoid(-1);
    } else if (L <= l && r <= R){
      if (d == 0){
        return STL[i];
      } else {
        return STR[i];
      }
    } else {
      int m = (l + r) / 2;
      if (d == 0){
        return merge(range_fold(L, R, d, i * 2 + 1, l, m), range_fold(L, R, d, i * 2 + 2, m, r));
      } else {
        return merge(range_fold(L, R, d, i * 2 + 2, m, r), range_fold(L, R, d, i * 2 + 1, l, m));
      }
    }
  }
  monoid range_fold(int L, int R, int d){
    return range_fold(L, R, d, 0, 0, N);
  }
};
struct heavy_light_decomposition{
  vector<int> p, sz, in, next;
  segment_tree ST;
  heavy_light_decomposition(vector<int> p, vector<vector<int>> c): p(p){
    int N = p.size();
    sz = vector<int>(N);
    dfs1(c);
    in = vector<int>(N);
    next = vector<int>(N, 0);
    int t = 0;
    dfs2(c, t);
    ST = segment_tree(N);
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
  void update(int v){
    ST.update(in[v]);
  }
  monoid path_fold(int u, int v){
    int w = lca(u, v);
    monoid L(-1);
    while (next[u] != next[w]){
      L = merge(L, ST.range_fold(in[next[u]], in[u] + 1, 1));
      u = p[next[u]];
    }
    L = merge(L, ST.range_fold(in[w] + 1, in[u] + 1, 1));
    monoid R(-1);
    while (next[v] != next[w]){
      R = merge(ST.range_fold(in[next[v]], in[v] + 1, 0), R);
      v = p[next[v]];
    }
    R = merge(ST.range_fold(in[w] + 1, in[v] + 1, 0), R);
    return merge(L, R);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  f = vector<int>(n, 0);
  for (int i = 1; i < n; i++){
    cin >> f[i];
  }
  vector<vector<pair<int, int>>> E(n);
  for (int i = 0; i < n - 1; i++){
    int v, u, w;
    cin >> v >> u >> w;
    v--;
    u--;
    E[v].push_back(make_pair(w, u));
    E[u].push_back(make_pair(w, v));
  }
  vector<int> p(n, -1);
  vector<vector<int>> c(n);
  vector<int> pw(n);
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
        pw[w] = P.first;
        Q.push(w);
      }
    }
  }
  vector<int> qu(q), qv(q), ql(q);
  for (int i = 0; i < q; i++){
    cin >> qu[i] >> qv[i] >> ql[i];
    qu[i]--;
    qv[i]--;
  }
  vector<tuple<int, int, int>> T;
  for (int i = 0; i < q; i++){
    T.push_back(make_tuple(ql[i], 0, i));
  }
  for (int i = 1; i < n; i++){
    T.push_back(make_tuple(pw[i], 1, i));
  }
  sort(T.begin(), T.end());
  vector<int> ans(q);
  heavy_light_decomposition D(p, c);
  for (int i = 0; i < q + n - 1; i++){
    int t = get<1>(T[i]);
    if (t == 0){
      int id = get<2>(T[i]);
      ans[id] = D.path_fold(qu[id], qv[id]).get();
    }
    if (t == 1){
      int v = get<2>(T[i]);
      D.update(v);
    }
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] << endl;
  }
}