#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct SegmentTree {
  using T = int;
  static T op(const T& x, const T& y) { return max(x, y); }
  static constexpr T e() { return -2e9; }
  using U = int;
  static void ap(const U& f, T& x) { x += f; }
  static void cp(const U& g, U& f) { f += g; }
  static constexpr U id() { return 0; }

  const int n;
  V<T> t;
  V<U> u;
  SegmentTree(int n) : n(n), t(2 * n, e()), u(n, id()) {}
  T& operator[](int i) { return t[i + n]; }
  void build() { for (int i = n - 1; i; --i) t[i] = op(t[2 * i], t[2 * i + 1]); }
  void push() { for (int i = 1; i < n; ++i) push(i); }
  void apply(const U& f, int i) {
    ap(f, t[i]);
    if (i < n) cp(f, u[i]);
  }
  void push(int i) {
    if (u[i] == id()) return;
    apply(u[i], 2 * i);
    apply(u[i], 2 * i + 1);
    u[i] = id();
  }
  void push(int l, int r) {
    for (int hl = __lg(l + n), hr = __lg(r - 1 + n); hr > 0; --hl, --hr) {
      int al = l + n >> hl, ar = r - 1 + n >> hr;
      if (al < n) push(al);
      if (ar != al) push(ar);
    }
  }
  T acc(int l, int r) {
    push(l, r);
    T resl = e(), resr = e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) resl = op(resl, t[l++]);
      if (r & 1) resr = op(t[--r], resr);
    }
    return op(resl, resr);
  }
  T get(int i) { return acc(i, i + 1); }
  void act(int l, int r, const U& f) {
    push(l, r);
    for (int i = l + n, j = r + n; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(f, i++);
      if (j & 1) apply(f, --j);
    }
    l = l + n >> __builtin_ctz(l + n);
    while (l >>= 1) t[l] = op(t[2 * l], t[2 * l + 1]);
    r = r + n >> __builtin_ctz(r + n);
    while (r >>= 1) t[r] = op(t[2 * r], t[2 * r + 1]);
  }
  void set(int i, const T& x) {
    push(i, i + 1);
    t[i += n] = x;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  SegmentTree st(1 << 20);
  for (int i = 0; i < 1 << 20; ++i) st[i] = 0;
  st.build();
  int n, m; cin >> n >> m;
  V<> a(n);
  for (auto&& e : a) {
    cin >> e;
    st.act(0, e, 1);
  }
  V<> b(m);
  for (auto&& e : b) {
    cin >> e;
    st.act(0, e, -1);
  }
  int q; cin >> q;
  while (q--) {
    int tp, i, x; cin >> tp >> i >> x, --i;
    if (tp == 1) {
      st.act(0, a[i], -1);
      st.act(0, x, 1);
      a[i] = x;
    } else {
      st.act(0, b[i], 1);
      st.act(0, x, -1);
      b[i] = x;
    }
    if (st.acc(0, 1 << 20) <= 0) cout << -1 << '\n';
    else {
      int ok = 0, ng = 1 << 20;
      while (ng - ok > 1) {
        int mid = ok + ng >> 1;
        (st.acc(mid, 1 << 20) > 0 ? ok : ng) = mid;
      }
      cout << ok + 1 << '\n';
    }
  }
}