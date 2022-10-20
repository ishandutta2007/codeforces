#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> struct FenwickTree {
  const int n;
  V<T> t;
  FenwickTree(int _n) : n(_n), t(n + 1) {}
  void add(int i, T x) { for (++i; i <= n; i += i & -i) t[i] += x; }
  T sum(int i) const {
    T s = 0;
    for (; i; i -= i & -i) s += t[i];
    return s;
  }
  T sum(int l, int r) const { return sum(r) - sum(l); }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e, --e;
  V<> b(n); for (auto&& e : b) cin >> e, --e;
  reverse(begin(b), end(b));
  V<> ib(n);
  for (int i = 0; i < n; ++i) {
    ib[b[i]] = i;
  }
  int res = 0;
  FenwickTree<int> ft(n);
  for (int e : a) {
    res += !!ft.sum(0, ib[e]);
    ft.add(ib[e], 1);
  }
  cout << res << '\n';
}