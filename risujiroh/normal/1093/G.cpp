#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct Monoid {
  using T = pair< V<>, V<> >; // min, max
  static T op(const T& lhs, const T& rhs) {
    V<> mn(32), mx(32);
    for (int i = 0; i < 32; ++i) {
      mn[i] = min(lhs.first[i], rhs.first[i]);
      mx[i] = max(lhs.second[i], rhs.second[i]);
    }
    return {mn, mx};
  }
  static T e() { return {V<>(32, 1e9), V<>(32, -1e9)}; }
};

template<class Monoid> struct SegmentTree {
  using M = Monoid;
  using T = typename M::T;

  const int n;
  V<T> val;

  SegmentTree(int n) : n(n), val(2 * n, M::e()) {}
  template<class Itr> SegmentTree(Itr first, Itr last) : n(distance(first, last)), val(2 * n, M::e()) {
    copy(first, last, next(begin(val), n));
    build();
  }

  T& operator[](int i) { return val[i + n]; }

  void build() {
    for (int i = n - 1; i > 0; --i) val[i] = M::op(val[2 * i], val[2 * i + 1]);
  }

  T get(int l, int r) const {
    T resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = M::op(resl, val[l++]);
      if (r & 1) resr = M::op(val[--r], resr);
    }
    return M::op(resl, resr);
  }

  void set(int i, const T& a) {
    for (val[i += n] = a, i >>= 1; i > 0; i >>= 1) val[i] = M::op(val[2 * i], val[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  VV<> a; assign(a, n, 5, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) cin >> a[i][j];
  }
  SegmentTree<Monoid> st(n);
  for (int i = 0; i < n; ++i) {
    V<> v(32);
    for (int bit = 0; bit < 32; ++bit) for (int j = 0; j < 5; ++j) {
      v[bit] += bit & 1 << j ? a[i][j] : -a[i][j];
    }
    st[i] = {v, v};
  }
  st.build();
  int q; cin >> q;
  for (int _ = 0; _ < q; ++_) {
    int tp; cin >> tp;
    if (tp == 1) {
      int i; cin >> i, --i;
      V<> b(5);
      for (int j = 0; j < k; ++j) cin >> b[j];
      V<> v(32);
      for (int bit = 0; bit < 32; ++bit) for (int j = 0; j < 5; ++j) {
        v[bit] += bit & 1 << j ? b[j] : -b[j];
      }
      st.set(i, {v, v});
    } else {
      int l, r; cin >> l >> r, --l;
      auto e = st.get(l, r);
      int res = 0;
      for (int bit = 0; bit < 32; ++bit) res = max(res, e.second[bit] - e.first[bit]);
      cout << res << '\n';
    }
  }
}