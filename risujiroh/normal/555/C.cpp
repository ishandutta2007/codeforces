// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

struct segment_tree_base {
  virtual int size() const = 0;

 protected:
  template <class F>
  void forward(int l, int r, F f) const {
    int h = h1(l += size() - 1, r += size());
    for (int s = 0; s < h; ++s)
      if (int i = l >> s; ~i & 1) f(i + 1);
    for (int s = h; s--;)
      if (int i = r >> s; i & 1) f(i - 1);
  }
  template <class F>
  void forward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->forward(l, r, f);
  }
  template <class F>
  void backward(int l, int r, F f) const {
    int h = h1(l += size() - 1, r += size());
    for (int s = 0; s < h; ++s)
      if (int i = r >> s; i & 1) f(i - 1);
    for (int s = h; s--;)
      if (int i = l >> s; ~i & 1) f(i + 1);
  }
  template <class F>
  void backward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->backward(l, r, f);
  }
  template <class F>
  void downward(int l, int r, F f) const {
    if (l == r or (l == 0 and r == size())) return;
    int h = h2(l += size(), r += size());
    for (int s = std::__lg(l); s > h; --s) f(l >> s);
    for (int s = h; s > __builtin_ctz(l); --s) f(l >> s);
    for (int s = h; s > __builtin_ctz(r); --s) f(r >> s);
  }
  template <class F>
  void downward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->downward(l, r, f);
  }
  template <class F>
  void upward(int l, int r, F f) const {
    if (l == r or (l == 0 and r == size())) return;
    int h = h2(l += size(), r += size());
    for (int s = __builtin_ctz(r); s++ < h;) f(r >> s);
    for (int s = __builtin_ctz(l); s++ < h;) f(l >> s);
    for (int s = h; s++ < std::__lg(l);) f(l >> s);
  }
  template <class F>
  void upward(int l, int r, F f) {
    const_cast<const segment_tree_base*>(this)->upward(l, r, f);
  }

 private:
  static int h1(int l, int r) {
    for (int h = 0;; ++h)
      if ((r >> h) - (l >> h) == 1) return h;
  }
  static int h2(int l, int r) {
    l <<= std::__lg(l) < std::__lg(r);
    return std::__lg(l ^ r);
  }
};

using namespace std;

constexpr int inf = 0x3f3f3f3f;

struct segtree : segment_tree_base {
  int n;
  vector<int> t;

  segtree(int _n) : n(_n), t(2 * n, inf) {}
  int size() const override { return n; }

  void act(int l, int r, int val) {
    forward(l, r, [&](int i) { chmin(t[i], val); });
  }
  int get(int i) const {
    int res = t[n + i];
    upward(i, i + 1, [&](int j) { chmin(res, t[j]); });
    return res;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> x(q), y(q);
  string s(q, '?');
  for (int i : rep(q)) {
    cin >> y[i] >> x[i] >> s[i];
    --x[i], --y[i];
  }
  auto vx = x, vy = y;
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  auto xi = [&](int x) -> int {
    return lower_bound(begin(vx), end(vx), x) - begin(vx);
  };
  auto yi = [&](int y) -> int {
    return lower_bound(begin(vy), end(vy), y) - begin(vy);
  };

  segtree row(size(vx)), col(size(vy));
  row.act(0, row.n, n);
  col.act(0, col.n, n);

  for (int k : rep(q)) {
    if (s[k] == 'L') {
      int pos = row.get(xi(x[k]));
      cout << pos - x[k] << '\n';
      row.act(xi(x[k]), xi(x[k]) + 1, x[k]);
      col.act(yi(n - pos), yi(n - x[k]), n - x[k] - 1);
    } else if (s[k] == 'U') {
      int pos = col.get(yi(y[k]));
      cout << pos - y[k] << '\n';
      col.act(yi(y[k]), yi(y[k]) + 1, y[k]);
      row.act(xi(n - pos), xi(n - y[k]), n - y[k] - 1);
    } else
      assert(false);
  }
}