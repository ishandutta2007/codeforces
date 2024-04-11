#include <bits/stdc++.h>
using namespace std;

template <class T> struct range_add {
  static constexpr T inf = numeric_limits<T>::max() / 2;
  struct node { T delta = 0, max = -inf; };
  static node op(const node& l, const node& r) {
    return {l.delta + r.delta, std::max(l.max, l.delta + r.max)};
  }
  static node make_node(T a) { return {a, a}; }
  const int n;
  vector<node> t;
  range_add(const vector<T>& v) : n(v.size() + 1), t(2 * n) {
    for (int i = n - 1; i--; ) t[n + i] = make_node(v[i] - (i ? v[i - 1] : 0));
    for (int i = n; i-- > 1; ) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  node fold(int l, int r) const {
    node a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = op(a, t[l++]);
      if (r & 1) b = op(t[--r], b);
    }
    return op(a, b);
  }
  T get(int i) const { return fold(0, i + 1).delta; }
  T max(int l, int r) const { return get(l - 1) + fold(l, r).max; }
  void set(int i, const node& a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = op(t[2 * i], t[2 * i + 1]);
  }
  void add(int l, int r, T a) {
    set(l, make_node(t[n + l].delta + a));
    set(r, make_node(t[n + r].delta - a));
  }
};

auto chmin = [](auto&& l, auto r) { return r < l ? l = r, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> a(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> c[i];
  }
  vector<int> b(m), d(m);
  for (int j = 0; j < m; ++j) {
    cin >> b[j] >> d[j];
  }
  vector<int> x(p), y(p), z(p);
  for (int k = 0; k < p; ++k) {
    cin >> x[k] >> y[k] >> z[k];
  }
  auto vx = a;
  vx.insert(end(vx), begin(x), end(x));
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  for (auto&& e : a) {
    e = lower_bound(begin(vx), end(vx), e) - begin(vx);
  }
  for (auto&& e : x) {
    e = lower_bound(begin(vx), end(vx), e) - begin(vx);
  }
  auto vy = b;
  vy.insert(end(vy), begin(y), end(y));
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  for (auto&& e : b) {
    e = lower_bound(begin(vy), end(vy), e) - begin(vy);
  }
  for (auto&& e : y) {
    e = lower_bound(begin(vy), end(vy), e) - begin(vy);
  }
  int h = vx.size(), w = vy.size();
  vector<int> mc(h + 1, 0x3f3f3f3f);
  for (int i = 0; i < n; ++i) {
    chmin(mc[a[i]], c[i]);
  }
  for (int s = h; s--; ) {
    chmin(mc[s], mc[s + 1]);
  }
  vector<int> md(w + 1, 0x3f3f3f3f);
  for (int j = 0; j < m; ++j) {
    chmin(md[b[j]], d[j]);
  }
  for (int t = w; t--; ) {
    chmin(md[t], md[t + 1]);
  }
  vector<vector<int>> ks(h);
  for (int k = 0; k < p; ++k) {
    ks[x[k]].push_back(k);
  }
  vector<int> v(w);
  for (int t = 0; t < w; ++t) {
    v[t] = -md[t];
  }
  range_add<int> ra(v);
  int res = -2e9;
  for (int s = 0; s < h; ++s) {
    int cur = -mc[s] + ra.max(0, w);
    res = max(res, cur);
    for (int k : ks[s]) {
      ra.add(y[k] + 1, w, z[k]);
    }
  }
  cout << res << '\n';
}