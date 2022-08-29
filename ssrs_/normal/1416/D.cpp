#include <bits/stdc++.h>
using namespace std;
const int LOG = 18;
struct unionfind{
  vector<int> p;
  unionfind(int N): p(N, -1){
  }
  int root(int x){
    if (p[x] == -1){
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
    p[x] = y;
  }
};
void dfs(vector<vector<int>> &c, vector<int> &P, vector<int> &L, vector<int> &R, int v){
  L[v] = P.size();
  if (c[v].empty()){
    P.push_back(v);
  }
  for (int w : c[v]){
    dfs(c, P, L, R, w);
  }
  R[v] = P.size();
}
struct segment_tree{
  int N;
  vector<pair<int, int>> ST;
  segment_tree(vector<int> &A){
    int N2 = A.size();
    N = 1;
    while (N < N2){
      N *= 2;
    }
    ST = vector<pair<int, int>>(N * 2 - 1, make_pair(0, 0));
    for (int i = 0; i < N2; i++){
      ST[N - 1 + i] = make_pair(A[i], i);
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  void update(int i){
    i += N - 1;
    ST[i].first = 0;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
    }
  }
  pair<int, int> range_max(int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return make_pair(0, 0);
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
    }
  }
  pair<int, int> range_max(int L, int R){
    return range_max(L, R, 0, 0, N);
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
  }
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  vector<int> t(q), x(q);
  for (int i = 0; i < q; i++){
    cin >> t[i] >> x[i];
    x[i]--;
  }
  vector<bool> used(m, false);
  for (int i = 0; i < q; i++){
    if (t[i] == 2){
      used[x[i]] = true;
    }
  }
  unionfind UF(n);
  vector<int> pr(n * 2 - 1, -1);
  vector<int> cr(n);
  for (int i = 0; i < n; i++){
    cr[i] = i;
  }
  vector<int> id(m, -1);
  int V = n;
  for (int i = 0; i < m; i++){
    if (!used[i]){
      int a2 = UF.root(a[i]);
      int b2 = UF.root(b[i]);
      if (a2 != b2){
        id[i] = V;
        pr[cr[a2]] = V;
        pr[cr[b2]] = V;
        UF.unite(a2, b2);
        cr[UF.root(a2)] = V;
        V++;
      }
    }
  }
  for (int i = q - 1; i >= 0; i--){
    if (t[i] == 2){
      int a2 = UF.root(a[x[i]]);
      int b2 = UF.root(b[x[i]]);
      if (a2 != b2){
        id[x[i]] = V;
        pr[cr[a2]] = V;
        pr[cr[b2]] = V;
        UF.unite(a2, b2);
        cr[UF.root(a2)] = V;
        V++;
      }
    }
  }
  for (int i = 1; i < n; i++){
    if (!UF.same(0, i)){
      int a2 = UF.root(0);
      int b2 = UF.root(i);
      if (a2 != b2){
        pr[cr[a2]] = V;
        pr[cr[b2]] = V;
        UF.unite(a2, b2);
        cr[UF.root(a2)] = V;
        V++;
      }
    }
  }
  vector<vector<int>> ch(V);
  for (int i = 0; i < V - 1; i++){
    ch[pr[i]].push_back(i);
  }
  vector<int> P;
  vector<int> L(V), R(V);
  dfs(ch, P, L, R, n * 2 - 2);
  vector<vector<int>> pp(LOG, vector<int>(V, -1));
  pp[0] = pr;
  for (int i = 0; i < LOG - 1; i++){
    for (int j = 0; j < V; j++){
      if (pp[i][j] != -1){
        pp[i + 1][j] = pp[i][pp[i][j]];
      }
    }
  }
  vector<bool> used2(V, false);
  for (int i = 0; i < m; i++){
    if (id[i] != -1){
      used2[id[i]] = true;
    }
  }
  vector<int> p2(n);
  for (int i = 0; i < n; i++){
    p2[i] = p[P[i]];
  }
  segment_tree ST(p2);
  for (int i = 0; i < q; i++){
    if (t[i] == 1){
      int v = x[i];
      for (int j = LOG - 1; j >= 0; j--){
        int w = pp[j][v];
        if (w != -1){
          if (used2[w]){
            v = w;
          }
        }
      }
      pair<int, int> res = ST.range_max(L[v], R[v]);
      cout << res.first << "\n";
      if (res.first != 0){
        ST.update(res.second);
      }
    }
    if (t[i] == 2){
      if (id[x[i]] != -1){
        used2[id[x[i]]] = false;
      }
    }
  }
}