#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


struct MaxMonoid {
  using T = lint;
  static T op(T lhs, T rhs) { return lhs > rhs ? lhs : rhs; }
  static constexpr T e() { return numeric_limits<T>::min(); }
};

template<class Monoid> struct SegmentTree {
  using T = typename Monoid::T;

  const int n;
  V<T> val;

  SegmentTree(int n) : n(n), val(2 * n, Monoid::e()) {}
  template<class Itr> SegmentTree(Itr first, Itr last) : n(distance(first, last)), val(2 * n, Monoid::e()) {
    copy(first, last, next(begin(val), n));
    build();
  }

  T& operator[](int i) { return val[i + n]; }

  void build() {
    for (int i = n - 1; i > 0; --i) val[i] = Monoid::op(val[2 * i], val[2 * i + 1]);
  }

  T get(int l, int r) const {
    T resl = Monoid::e(), resr = Monoid::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = Monoid::op(resl, val[l++]);
      if (r & 1) resr = Monoid::op(val[--r], resr);
    }
    return Monoid::op(resl, resr);
  }

  void set(int i, const T& a) {
    for (val[i += n] = a, i >>= 1; i > 0; i >>= 1) val[i] = Monoid::op(val[2 * i], val[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, k, x; cin >> n >> k >> x;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  if (x < n / k) return cout << -1 << '\n', 0;
  SegmentTree<MaxMonoid> dpn(n + 1), dpc(n + 1);
  dpn.set(0, 0);
  for (int j = 0; j < x; ++j) {
    swap(dpn.val, dpc.val);
    fill(begin(dpn.val), end(dpn.val), MaxMonoid::e());
    for (int i = 0; i < n; ++i) dpn[i + 1] = a[i] + dpc.get(max(i - k + 1, 0), i + 1);
    dpn.build();
  }
  cout << dpn.get(n - k + 1, n + 1) << '\n';
}