#include <bits/extc++.h>

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

template <class T>
struct segment_tree : segment_tree_base {
  segment_tree() {}
  template <class Generator>
  segment_tree(int n, Generator gen) : tree(2 * n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen(i);
    for (int i = n; i-- > 1;) pull(i);
  }

  int size() const override { return std::size(tree) / 2; }
  const T& operator[](int i) const {
    assert(0 <= i), assert(i < size());
    return tree[size() + i];
  }
  T fold(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T res{};
    forward(l, r, [&](int i) { res = res * tree[i]; });
    return res;
  }
  T fold_all_rotated() const { return size() ? tree[1] : T{}; }
  template <class Function>
  void update(int i, Function func) {
    assert(0 <= i), assert(i < size());
    tree[size() + i] = func(tree[size() + i]);
    upward(i, i + 1, [&](int j) { pull(j); });
  }
  template <class Predicate>
  int forward_search(int l, int r, Predicate pred) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T a{};
    assert(pred(a));
    int res = r;
    forward(l, r, [&](int i) {
      if (res < r) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = a * tree[i *= 2]; pred(na)) a = na, ++i;
      res = i - size();
    });
    return res;
  }
  template <class Predicate>
  int backward_search(int l, int r, Predicate pred) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    T a{};
    assert(pred(a));
    int res = l - 1;
    backward(l, r, [&](int i) {
      if (res >= l) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = a * tree[i = 2 * i + 1]; pred(na)) a = na, --i;
      res = i - size();
    });
    return res;
  }

 private:
  std::vector<T> tree;

  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }
};

constexpr auto inf = std::numeric_limits<int64_t>::max() / 2;

struct node {
  std::array<std::array<int64_t, 2>, 2> v{};
  node() { v[0][1] = v[1][0] = -inf; }
  node(int64_t a) {
    v[0][1] = a;
    v[1][0] = -a;
  }
  friend node operator*(const node& a, const node& b) {
    node c{};
    for (int l : {0, 1})
      for (int m : {0, 1})
        for (int r : {0, 1})
          c.v[l][r] = std::max(c.v[l][r], a.v[l][m] + b.v[m][r]);
    return c;
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    segment_tree<node> seg(n, [](int) -> node {
      int a;
      cin >> a;
      return a;
    });
    cout << seg.fold(0, n).v[0][1] << '\n';
    while (q--) {
      int i, j;
      cin >> i >> j;
      --i, --j;
      auto ti = seg[i], tj = seg[j];
      seg.update(i, [&](const node&) { return tj; });
      seg.update(j, [&](const node&) { return ti; });
      cout << seg.fold(0, n).v[0][1] << '\n';
    }
  }
}