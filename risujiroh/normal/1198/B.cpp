#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr int inf = 2e9;

struct SegmentTree {
  using T = struct { int min, max; };
  static T op(const T& a, const T& b) { return {min(a.min, b.min), max(a.max, b.max)}; }
  static constexpr T e() { return {inf, -inf}; }
  using U = struct {
    int lb, ub;
    bool operator==(const auto& r) const { return lb == r.lb and ub == r.ub; }
  };
  static void ap(const U& f, T& a) {
    a.min = min(max(a.min, f.lb), f.ub);
    a.max = min(max(a.max, f.lb), f.ub);
  }
  static void cp(const U& g, U& f) {
    f.lb = min(max(f.lb, g.lb), g.ub);
    f.ub = min(max(f.ub, g.lb), g.ub);
  }
  static constexpr U id() { return {-inf, inf}; }

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
  void set(int i, const T& a) {
    push(i, i + 1);
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  SegmentTree st(n);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    st[i] = {a, a};
  }
  st.build();
  int q; cin >> q;
  while (q--) {
    int tp; cin >> tp;
    if (tp == 1) {
      int i, x; cin >> i >> x, --i;
      st.set(i, {x, x});
    } else {
      int x; cin >> x;
      st.act(0, n, {x, inf});
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << st.get(i).max << " \n"[!(n + ~i)];
  }
}