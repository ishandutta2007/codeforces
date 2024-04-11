#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr int inf = 1e9;

struct SegmentTree {
  using T = struct { int m0, l1, m1, r1, l2, r2, m3; };
  static T op(const T& x, const T& y) {
    T res;
    res.m0 = x.m0 + y.m0;
    res.l1 = max(x.l1, x.m0 + y.l1);
    res.m1 = max(x.m1 + y.m0, -x.m0 + y.m1);
    res.r1 = max(x.r1 - y.m0, y.r1);
    res.l2 = max({x.l2, x.m1 + y.l1, -x.m0 + y.l2});
    res.r2 = max({x.r2 + y.m0, x.r1 + y.m1, y.r2});
    res.m3 = max({x.m3, x.r2 + y.l1, x.r1 + y.l2, y.m3});
    return res;
  }
  static constexpr T e() { return {0, -inf, -inf, -inf, -inf, -inf, -inf}; }

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
  void set(int i, const T& x) {
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, q; cin >> n >> q;
  string s; cin >> s;
  SegmentTree st(2 * n - 2);
  for (int i = 0; i < st.n; ++i) {
    if (s[i] == '(') st[i] = {1, 1, 1, 0, 1, 1, 1};
    if (s[i] == ')') st[i] = {-1, 0, 1, 1, 1, 1, 1};
  }
  st.build();
  cout << st.acc(0, st.n).m3 << '\n';
  while (q--) {
    int i, j; cin >> i >> j, --i, --j;
    auto ei = st[i], ej = st[j];
    st.set(i, ej);
    st.set(j, ei);
    cout << st.acc(0, st.n).m3 << '\n';
  }
}