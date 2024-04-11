#include <bits/stdc++.h>
using namespace std;

template <class T, class U, class Op, class Apply, class Compose>
struct SegmentTree {
  const Op op;
  const T e;
  const Apply ap;
  const Compose cp;
  const U id;
  const int n;
  vector<T> t;
  vector<U> u;
  SegmentTree(int _n, Op _op, T _e, Apply _ap, Compose _cp, U _id) :
    op(_op), e(_e), ap(_ap), cp(_cp), id(_id), n(_n), t(2 * n, e), u(n, id) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i-- > 1; ) t[i] = op(t[2 * i], t[2 * i + 1]); }
  void push() { for (int i = 1; i < n; ++i) push(i); }
  void apply(int i, U f) {
    t[i] = ap(t[i], f);
    if (i < n) u[i] = cp(u[i], f);
  }
  void push(int i) {
    apply(2 * i, u[i]), apply(2 * i + 1, u[i]);
    u[i] = id;
  }
  void propagate(int i) {
    for (int h = __lg(i), tz = __builtin_ctz(i); h > tz; --h) push(i >> h);
  }
  T fold(int l, int r) {
    propagate(l += n), propagate(r += n);
    T a = e, b = e;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  T get(int i) { return fold(i, i + 1); }
  void act(int l, int r, U f) {
    propagate(l += n), propagate(r += n);
    for (int i = l, j = r; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(i++, f);
      if (j & 1) apply(--j, f);
    }
    l = l >> __builtin_ctz(l);
    while (l >>= 1) t[l] = op(t[2 * l], t[2 * l + 1]);
    r = r >> __builtin_ctz(r);
    while (r >>= 1) t[r] = op(t[2 * r], t[2 * r + 1]);
  }
  void set(int i, T a) {
    propagate(i += n), propagate(i + 1);
    t[i] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
};
template <class T, class U, class Op, class Apply, class Compose>
auto make_segment_tree(int n, Op op, T e, Apply ap, Compose cp, U id) {
  return SegmentTree<T, U, Op, Apply, Compose>(n, op, e, ap, cp, id);
}

auto minimum = [](auto l, auto r) { return r < l ? r : l; };

constexpr long long inf = 0x3f3f3f3fLL << 32;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> p(n), ip(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    ip[p[i]] = i;
  }
  vector<int> a(n);
  for_each(begin(a), end(a), [](int& e) { cin >> e; });
  auto st = make_segment_tree<long long, long long>(
    n + 1, minimum, inf, plus<>(), plus<>(), 0
  );
  for (int i = 0; i < n; ++i) {
    st[i] = 0;
  }
  st.build();
  for (int i = 0; i < n; ++i) {
    st.act(i + 1, n + 1, a[i]);
  }
  long long res = st.fold(1, n), offset = 0;
  for (int x = 0; x < n; ++x) {
    int i = ip[x];
    st.act(i + 1, n + 1, -2 * a[i]);
    offset += a[i];
    res = min(res, offset + st.fold(1, n));
  }
  cout << res << '\n';
}