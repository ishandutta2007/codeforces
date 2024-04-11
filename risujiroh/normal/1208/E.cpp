#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  using T = int;
  static T op(const T& a, const T& b) { return max(a, b); }
  static constexpr T e() { return -2e9; }

  const int n;
  V<T> t;
  SegmentTree(int n) : n(n), t(2 * n, e()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  T acc(int l, int r) const {
    l = max(l + 1, 0), r = min(r + 1, n);
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
  int n, w; cin >> n >> w;
  V<lint> res(w + 1);
  while (n--) {
    int l; cin >> l;
    V<> a(l); for (auto&& e : a) cin >> e;
    if (l < w - l) {
      int mx = max(*max_element(begin(a), end(a)), 0);
      res[l] += mx;
      res[w - l] -= mx;
      mx = 0;
      for (int j = 0; j < l; ++j) {
        mx = max(mx, a[j]);
        res[j] += mx;
        res[j + 1] -= mx;
      }
      mx = 0;
      for (int j = w - 1; j >= w - l; --j) {
        mx = max(mx, a[j - (w - l)]);
        res[j] += mx;
        res[j + 1] -= mx;
      }
    } else {
      SegmentTree st(l + 2);
      st[0] = st[l + 1] = 0;
      for (int i = 0; i < l; ++i) {
        st[1 + i] = a[i];
      }
      st.build();
      for (int j = 0; j < w; ++j) {
        res[j] += st.acc(j - (w - l), j + 1);
        res[j + 1] -= st.acc(j - (w - l), j + 1);
      }
    }
  }
  for (int j = 0; j < w; ++j) {
    cout << res[j] << " \n"[j == w - 1];
    res[j + 1] += res[j];
  }
}