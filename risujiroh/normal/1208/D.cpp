#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int n) : n(n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
  // [0,i)sin+1
  int lower_bound(T s) const {
    if (s <= 0) return 0;
    int i = 0;
    for (int k = 1 << __lg(n); k; k >>= 1) {
      if (i + k <= n and t[i + k] < s) s -= t[i += k];
    }
    return i + 1;
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> s(n); for (auto&& e : s) cin >> e;
  V<> p(n);
  FenwickTree<lint> ft(n);
  for (int i = 0; i < n; ++i) {
    ft.add(i, i + 1 << 1);
  }
  for (int i = n - 1; i >= 0; --i) {
    p[i] = ft.lower_bound(s[i] << 1 | 1) - 1;
    ft.add(p[i], -(p[i] + 1 << 1));
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i] + 1 << " \n"[i == n - 1];
  }
}