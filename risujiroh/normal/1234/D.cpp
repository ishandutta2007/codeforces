#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  using T = int;
  static T op(const T& a, const T& b) { return a | b; }
  static constexpr T e() { return 0; }

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
  string s; cin >> s;
  int n = s.size();
  SegmentTree st(n);
  for (int i = 0; i < n; ++i) {
    st[i] = 1 << s[i] - 'a';
  }
  st.build();

  int q; cin >> q;
  while (q--) {
    int tp; cin >> tp;
    if (tp == 1) {
      int i; cin >> i, --i;
      char c; cin >> c;
      st.set(i, 1 << c - 'a');
    } else {
      int l, r; cin >> l >> r, --l;
      int res = __builtin_popcount(st.acc(l, r));
      cout << res << '\n';
    }
  }
}