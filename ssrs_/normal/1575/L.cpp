#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct segment_tree_2d{
  vector<pair<int, int>> pos;
  vector<int> X;
  vector<vector<int>> Y;
  int N;
  vector<int> N2;
  vector<vector<T>> ST;
  function<T(T, T)> f;
  T E;
  segment_tree_2d(function<T(T, T)> f, T E): f(f), E(E){
  }
  void add(int x, int y){
    pos.push_back(make_pair(x, y));
    X.push_back(x);
  }
  void build(){
    int cnt = pos.size();
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    int cnt2 = X.size();
    N = 1;
    while (N < cnt2){
      N *= 2;
    }
    Y = vector<vector<int>>(N * 2 - 1);
    for (int i = 0; i < cnt; i++){
      int p = lower_bound(X.begin(), X.end(), pos[i].first) - X.begin();
      p += N - 1;
      Y[p].push_back(pos[i].second);
      while (p > 0){
        p = (p - 1) / 2;
        Y[p].push_back(pos[i].second);
      }
    }
    N2 = vector<int>(N * 2 - 1, 0);
    ST = vector<vector<T>>(N * 2 - 1);
    for (int i = 0; i < N * 2 - 1; i++){
      if (!Y[i].empty()){
        sort(Y[i].begin(), Y[i].end());
        Y[i].erase(unique(Y[i].begin(), Y[i].end()), Y[i].end());
        int cnt3 = Y[i].size();
        N2[i] = 1;
        while (N2[i] < cnt3){
          N2[i] *= 2;
        }
        ST[i] = vector<T>(N2[i] * 2 - 1);
      }
    }
  }
  T get(int x, int y){
    int p1 = lower_bound(X.begin(), X.end(), x) - X.begin();
    p1 += N - 1;
    int p2 = lower_bound(Y[p1].begin(), Y[p1].end(), y) - Y[p1].begin();
    p2 += N2[p1] - 1;
    return ST[p1][p2];
  }
  void update2(int i, int j, T x){
    j += N2[i] - 1;
    ST[i][j] = x;
    while (j > 0){
      j = (j - 1) / 2;
      ST[i][j] = f(ST[i][j * 2 + 1], ST[i][j * 2 + 2]);
    }
  }
  void update(int i, int j, T x){
    int p1 = lower_bound(X.begin(), X.end(), i) - X.begin();
    p1 += N - 1;
    int p2 = lower_bound(Y[p1].begin(), Y[p1].end(), j) - Y[p1].begin();
    update2(p1, p2, x);
    while (p1 > 0){
      p1 = (p1 - 1) / 2;
      p2 = lower_bound(Y[p1].begin(), Y[p1].end(), j) - Y[p1].begin();
      T x2 = 0;
      int pl = lower_bound(Y[p1 * 2 + 1].begin(), Y[p1 * 2 + 1].end(), j) - Y[p1 * 2 + 1].begin();
      if (pl < Y[p1 * 2 + 1].size()){
        if (Y[p1 * 2 + 1][pl] == j){
          x2 = f(x2, ST[p1 * 2 + 1][N2[p1 * 2 + 1] - 1 + pl]);
        }
      }
      int pr = lower_bound(Y[p1 * 2 + 2].begin(), Y[p1 * 2 + 2].end(), j) - Y[p1 * 2 + 2].begin();
      if (pr < Y[p1 * 2 + 2].size()){
        if (Y[p1 * 2 + 2][pr] == j){
          x2 = f(x2, ST[p1 * 2 + 2][N2[p1 * 2 + 2] - 1 + pr]);
        }
      }
      update2(p1, p2, x2);
    }
  }
  T query1(int id, int L, int R, int i, int l, int r){
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return ST[id][i];
    } else {
      int m = (l + r) / 2;
      return f(query1(id, L, R, i * 2 + 1, l, m), query1(id, L, R, i * 2 + 2, m, r));
    }
  }
  T query2(int U, int D, int L, int R, int i, int u, int d){
    if (d <= U || D <= u){
      return E;
    } else if (U <= u && d <= D){
      int l = lower_bound(Y[i].begin(), Y[i].end(), L) - Y[i].begin();
      int r = lower_bound(Y[i].begin(), Y[i].end(), R) - Y[i].begin();
      return query1(i, l, r, 0, 0, N2[i]);
    } else {
      int m = (u + d) / 2;
      return f(query2(U, D, L, R, i * 2 + 1, u, m), query2(U, D, L, R, i * 2 + 2, m, d));
    }
  }
  T query(int U, int D, int L, int R){
    int u = lower_bound(X.begin(), X.end(), U) - X.begin();
    int d = lower_bound(X.begin(), X.end(), D) - X.begin();
    return query2(u, d, L, R, 0, 0, N);
  }
};
int f(int x, int y){
  return max(x, y);
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<bool> ok(n, true);
  for (int i = 0; i < n; i++){
    if (a[i] > i){
      ok[i] = false;
    }
  }
  segment_tree_2d<int> ST(f, 0);
  for (int i = 0; i < n; i++){
    if (ok[i]){
      ST.add(a[i], i - a[i]);
    }
  }
  ST.build();
  int ans = 0;
  for (int i = 0; i < n; i++){
    if (ok[i]){
      int mx = ST.query(0, a[i], 0, i - a[i] + 1);
      ans = max(ans, mx + 1);
      ST.update(a[i], i - a[i], mx + 1);
    }
  }
  cout << ans << endl;
}