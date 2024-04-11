#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct xor_segment_tree{
  int N;
  vector<vector<T>> ST;
  function<T(T, T)> f;
  T E;
  xor_segment_tree(vector<T> &A, function<T(T, T)> f, T E): f(f), E(E){
    N = A.size();
    ST = vector<vector<T>>(N * 2 - 1);
    for (int i = 0; i < N; i++){
      ST[N - 1 + i].push_back(A[i]);
    }
    for (int i = N - 2; i >= 0; i--){
      int cnt = ST[i * 2 + 1].size();
      for (int j = 0; j < cnt; j++){
        ST[i].push_back(f(ST[i * 2 + 1][j], ST[i * 2 + 2][j]));
      }
      for (int j = 0; j < cnt; j++){
        ST[i].push_back(f(ST[i * 2 + 2][j], ST[i * 2 + 1][j]));
      }
    }
  }
  T range_fold(int L, int R, int x, int i, int l, int r){
    if (r <= L || R <= l){
      return E;
    } else if (L <= l && r <= R){
      return ST[i][x];
    } else {
      int p = (r - l) / 2;
      int m = (l + r) / 2;
      if ((x & p) == 0){
        T resL = range_fold(L, R, x, i * 2 + 1, l, m);
        T resR = range_fold(L, R, x, i * 2 + 2, m, r);
        return f(resL, resR);
      } else {
        T resL = E;
        if (R >= m){
          resL = range_fold(max(L, m) - p, R - p, x ^ p, i * 2 + 1, l, m);
        }
        T resR = E;
        if (L < m){
          resR = range_fold(L + p, min(R, m) + p, x ^ p, i * 2 + 2, m, r);
        }
        return f(resR, resL);
      }
    }
  }
  T range_fold(int L, int R, int x){
    return range_fold(L, R, x, 0, 0, N);
  }
};
struct monoid{
  long long sum, left, right, all;
  monoid(): sum(0), left(0), right(0), all(0){
  }
  monoid(int x){
    sum = x;
    left = max(x, 0);
    right = max(x, 0);
    all = max(x, 0);
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.sum = L.sum + R.sum;
  ans.left = max(L.left, L.sum + R.left);
  ans.right = max(R.right, L.right + R.sum);
  ans.all = max({L.all, R.all, L.right + R.left});
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(1 << n);
  for (int i = 0; i < (1 << n); i++){
    cin >> a[i];
  }
  vector<monoid> A(1 << n);
  for (int i = 0; i < (1 << n); i++){
    A[i] = monoid(a[i]);
  }
  xor_segment_tree<monoid> ST(A, f, monoid());
  int q;
  cin >> q;
  int X = 0;
  for (int i = 0; i < q; i++){
    int k;
    cin >> k;
    X ^= 1 << k;
    cout << ST.range_fold(0, 1 << n, X).all << "\n";
  }
}