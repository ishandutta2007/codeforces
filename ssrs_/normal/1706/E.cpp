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
    if (r <= L || R <= l){
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
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> U(m), V(m);
    for (int j = 0; j < m; j++){
      cin >> U[j] >> V[j];
      U[j]--;
      V[j]--;
    }
    vector<int> tv(n - 1, m), fv(n - 1, 0);
    while (true){
      vector<vector<int>> query(m);
      bool ok = true;
      for (int j = 0; j < n - 1; j++){
        if (tv[j] - fv[j] > 1){
          ok = false;
          int mid = (tv[j] + fv[j]) / 2;
          query[mid].push_back(j);
        }
      }
      if (ok){
        break;
      }
      unionfind UF(n);
      for (int j = 0; j < m; j++){
        for (int k : query[j]){
          if (UF.same(k, k + 1)){
            tv[k] = j;
          } else {
            fv[k] = j;
          }
        }
        UF.unite(U[j], V[j]);
      }
    }
    function<int(int, int)> op = [](int a, int b){
      return max(a, b);
    };
    segment_tree<int> ST(tv, op, 0);
    for (int j = 0; j < q; j++){
      int l, r;
      cin >> l >> r;
      l--;
      if (r - l == 1){
        cout << 0;
      } else {
        cout << ST.query(l, r - 1);
      }
      if (j < q - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}