#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  static constexpr int inf = 1e9;
  using T = struct { int min, max; };
  static T op(const T& a, const T& b) { return {min(a.min, b.min), max(a.max, b.max)}; }
  static constexpr T e() { return {inf, -inf}; }

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
  int T; cin >> T;
  while (T--) {
    string s; cin >> s;
    int n = s.size();
    V<> x(n + 1), y(n + 1);
    for (int i = 0; i < n; ++i) {
      x[i + 1] = x[i] + (s[i] == 'D' ? 1 : s[i] == 'A' ? -1 : 0);
      y[i + 1] = y[i] + (s[i] == 'W' ? 1 : s[i] == 'S' ? -1 : 0);
    }
    SegmentTree stx(n + 1), sty(n + 1);
    for (int i = 0; i <= n; ++i) {
      stx[i] = {x[i], x[i]};
      sty[i] = {y[i], y[i]};
    }
    stx.build();
    sty.build();
    auto ex = stx.acc(0, n + 1), ey = sty.acc(0, n + 1);
    lint res = (lint)(ex.max - ex.min + 1) * (ey.max - ey.min + 1);
    for (int i = 0; i <= n; ++i) {
      ex = stx.acc(0, i + 1);
      auto nex = stx.acc(i, n + 1);
      ey = sty.acc(0, i + 1);
      auto ney = sty.acc(i, n + 1);
      {
        lint curr = max(ex.max, nex.max + 1) - min(ex.min, nex.min + 1) + 1;
        curr *= max(ey.max, ney.max) - min(ey.min, ney.min) + 1;
        res = min(res, curr);
      }
      {
        lint curr = max(ex.max, nex.max - 1) - min(ex.min, nex.min - 1) + 1;
        curr *= max(ey.max, ney.max) - min(ey.min, ney.min) + 1;
        res = min(res, curr);
      }
      {
        lint curr = max(ex.max, nex.max) - min(ex.min, nex.min) + 1;
        curr *= max(ey.max, ney.max + 1) - min(ey.min, ney.min + 1) + 1;
        res = min(res, curr);
      }
      {
        lint curr = max(ex.max, nex.max) - min(ex.min, nex.min) + 1;
        curr *= max(ey.max, ney.max - 1) - min(ey.min, ney.min - 1) + 1;
        res = min(res, curr);
      }
    }
    cout << res << '\n';
  }
}