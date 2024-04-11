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
  int n, m; cin >> n >> m;
  V<string> s(n); for (auto&& e : s) cin >> e;
  VV<> r(n, V<>(m, 1));
  for (int i = 0; i < n; ++i) {
    for (int j = m - 2; j >= 0; --j) {
      if (s[i][j] == s[i][j + 1]) r[i][j] = 1 + r[i][j + 1];
    }
  }
  V<SegmentTree> st(m, n);
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) st[j][i] = r[i][j];
    st[j].build();
  }
  VV<> d(n, V<>(m, 1));
  for (int j = 0; j < m; ++j) {
    for (int i = n - 2; i >= 0; --i) {
      if (s[i][j] == s[i + 1][j]) d[i][j] = 1 + d[i + 1][j];
    }
  }
  lint res = 0;
  for (int sj = 0; sj < m; ++sj) {
    for (int si = 0; si < n; ++si) {
      int h = d[si][sj];
      if (si + 3 * h > n) continue;
      if (d[si + h][sj] != h) continue;
      if (d[si + 2 * h][sj] < h) continue;
      res += st[sj].acc(si, si + 3 * h);
    }
  }
  cout << res << '\n';
}