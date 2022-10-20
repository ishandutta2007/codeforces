#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr int inf = 2e9;
struct SegmentTree {
  using T = struct { int m0, m1; };
  static T op(const T& a, const T& b) {
    if (a.m0 < b.m0) {
      return {a.m0, min(a.m1, b.m0)};
    } else {
      return {b.m0, min(a.m0, b.m1)};
    }
  }
  static constexpr T e() { return {inf, inf}; }

  const int n;
  V<T> t;
  SegmentTree(int n) : n(n), t(2 * n, e()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T acc(int l, int r) const {
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  void set(int i, const T& a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<SegmentTree> st(9, SegmentTree(n));
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    int x = a;
    for (int k = 0; k < 9; ++k) {
      if (x % 10) {
        st[k][i] = {a, inf};
      }
      x /= 10;
    }
  }
  for (auto&& e : st) {
    e.build();
  }

  while (m--) {
    int tp; cin >> tp;
    if (tp == 1) {
      int i, a; cin >> i >> a, --i;
      int x = a;
      for (int k = 0; k < 9; ++k) {
        if (x % 10) {
          st[k].set(i, {a, inf});
        } else {
          st[k].set(i, st[k].e());
        }
        x /= 10;
      }
    } else {
      int l, r; cin >> l >> r, --l;
      int res = inf;
      for (int k = 0; k < 9; ++k) {
        auto e = st[k].acc(l, r);
        if (e.m1 == inf) continue;
        res = min(res, e.m0 + e.m1);
      }
      cout << (res == inf ? -1 : res) << '\n';
    }
  }
}