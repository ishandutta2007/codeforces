#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  using T = int;
  static T op(const T& x, const T& y) { return min(x, y); }
  static constexpr T e() { return numeric_limits<T>::max(); }

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
  int n, m, q; cin >> n >> m >> q;
  V<> ip(n);
  for (int i = 0; i < n; ++i) {
    int p; cin >> p, --p;
    ip[p] = i;
  }
  V<> a(m);
  for (auto&& e : a) cin >> e, --e, e = ip[e];
  V<> mn(n, m);
  VV<> par(20, V<>(m, m));
  for (int i = m - 1; i >= 0; --i) {
    par[0][i] = mn[(a[i] + 1) % n];
    mn[a[i]] = i;
  }
  for (int k = 1; k < (int) par.size(); ++k) {
    for (int i = 0; i < m; ++i) {
      if (par[k - 1][i] == m) continue;
      par[k][i] = par[k - 1][par[k - 1][i]];
    }
  }
  auto get_par = [&](int i, int h) -> int {
    for (int k = 0; h > 0; h >>= 1, ++k) {
      if (i == m) break;
      if (h & 1) i = par[k][i];
    }
    return i;
  };
  SegmentTree st(m);
  for (int i = 0; i < m; ++i) {
    st[i] = get_par(i, n - 1);
  }
  st.build();
  while (q--) {
    int l, r; cin >> l >> r, --l;
    cout << (st.acc(l, r) < r);
  }
  cout << '\n';
}