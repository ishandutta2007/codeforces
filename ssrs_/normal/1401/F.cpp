#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct segment_tree{
  int n, N;
  vector<bool> swp;
  vector<T> ST;
  segment_tree(vector<T> &a, int n): n(n){
    N = 1 << n;
    swp = vector<bool>(n, false);
    ST = vector<T>(N * 2 - 1, 0);
    for (int i = N - 1; i < N * 2 - 1; i++){
      ST[i] = a[i - N + 1];
    }
    for (int i = N - 2; i >= 0; i--){
      ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
    }
  }
  void replace(int i, T x){
    for (int j = 0; j < n; j++){
      if (swp[j]){
        i ^= (1 << j);
      }
    }
    i += N - 1;
    ST[i] = x;
    while (i > 0){
      i = (i - 1) / 2;
      ST[i] = ST[i * 2 + 1] + ST[i * 2 + 2];
    }
  }
  T sum(int L, int R, int i, int l, int r, int p){
    if (R <= l || r <= L){
      return 0;
    } else if (L <= l && r <= R){
      return ST[i];
    } else {
      int m = (l + r) / 2;
      if (swp[p]){
        int d = (r - l) / 2;
        T S1 = 0;
        if (R >= m){
          S1 = sum(max(m, L) - d, R - d, i * 2 + 1, l, m, p - 1);
        }
        T S2 = 0;
        if (L < m){
          S2 = sum(L + d, min(m, R) + d, i * 2 + 2, m, r, p - 1);
        }
        return S1 + S2;
      } else {
        T S1 = sum(L, R, i * 2 + 1, l, m, p - 1);
        T S2 = sum(L, R, i * 2 + 2, m, r, p - 1);
        return S1 + S2;
      }
    }
  }
  T sum(int L, int R){
    return sum(L, R, 0, 0, N, n - 1);
  }
  void swap(int k){
    swp[k] = !swp[k];
  }
  void reverse(int k){
    for (int i = 0; i < k; i++){
      swap(i);
    }
  }
  void debug(){
    for (T x : ST){
      cout << x << ' ';
    }
    cout << endl;
  }
};
int main(){
  int n, q;
  cin >> n >> q;
  vector<long long> a(1 << n);
  for (int i = 0; i < (1 << n); i++){
    cin >> a[i];
  }
  segment_tree<long long> ST(a, n);
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x, k;
      cin >> x >> k;
      ST.replace(x - 1, k);
    }
    if (t == 2){
      int k;
      cin >> k;
      ST.reverse(k);
    }
    if (t == 3){
      int k;
      cin >> k;
      ST.swap(k);
    }
    if (t == 4){
      int l, r;
      cin >> l >> r;
      cout << ST.sum(l - 1, r) << endl;
    }
  }
}