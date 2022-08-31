#include <bits/stdc++.h>
using namespace std;
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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
  }
  function<int(int, int)> op = [](int x, int y){
    return max(x, y);
  };
  segment_tree<int> ST(a, op, 0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int xs, ys, xf, yf, k;
    cin >> xs >> ys >> xf >> yf >> k;
    xs--;
    ys--;
    xf--;
    yf--;
    xs = n - 1 - xs;
    xf = n - 1 - xf;
    if (ys > yf){
      swap(xs, xf);
      swap(ys, yf);
    }
    if ((xf - xs) % k != 0 || (yf - ys) % k != 0){
      cout << "NO" << "\n";
    } else {
      int x = xs % k;
      if (x < n - ST.query(ys, yf)){
        cout << "YES" << "\n";
      } else {
        cout << "NO" << "\n";
      }
    }
  }
}