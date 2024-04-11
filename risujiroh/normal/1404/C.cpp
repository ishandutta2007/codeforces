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

template <class T, class Action>
struct lazy_segment_tree : segment_tree_base {
  lazy_segment_tree() {}
  template <class Generator>
  lazy_segment_tree(int n, Generator gen) : tree(2 * n), lazy(n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen(i);
    for (int i = n; i-- > 1;) pull(i);
  }

  int size() const override { return std::size(lazy); }
  T fold(int l, int r) {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    downward(l, r, [&](int i) { push(i); });
    T res{};
    forward(l, r, [&](int i) { res = res * tree[i]; });
    return res;
  }
  T get(int i) {
    assert(0 <= i), assert(i < size());
    return fold(i, i + 1);
  }
  T fold_all_rotated() const { return size() ? tree[1] : T{}; }
  template <class Function>
  void update(int i, Function func) {
    assert(0 <= i), assert(i < size());
    downward(i, i + 1, [&](int j) { push(j); });
    tree[size() + i] = func(tree[size() + i]);
    upward(i, i + 1, [&](int j) { pull(j); });
  }
  void act(int l, int r, const Action& f) {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    downward(l, r, [&](int i) { push(i); });
    forward(l, r, [&](int i) { apply(i, f); });
    upward(l, r, [&](int i) { pull(i); });
  }
  template <class Predicate>
  int forward_search(int l, int r, Predicate pred) {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    downward(l, r, [&](int i) { push(i); });
    T a{};
    assert(pred(a));
    int res = r;
    forward(l, r, [&](int i) {
      if (res < r) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size()) {
        push(i);
        if (T na = a * tree[i *= 2]; pred(na)) a = na, ++i;
      }
      res = i - size();
    });
    return res;
  }
  template <class Predicate>
  int backward_search(int l, int r, Predicate pred) {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    downward(l, r, [&](int i) { push(i); });
    T a{};
    assert(pred(a));
    int res = l - 1;
    backward(l, r, [&](int i) {
      if (res >= l) return;
      if (T na = a * tree[i]; pred(na)) {
        a = na;
        return;
      }
      while (i < size()) {
        push(i);
        if (T na = a * tree[i = 2 * i + 1]; pred(na)) a = na, --i;
      }
      res = i - size();
    });
    return res;
  }

 private:
  std::vector<T> tree;
  std::vector<Action> lazy;

  void apply(int i, const Action& f) {
    tree[i] = f(tree[i]);
    if (i < size()) lazy[i] = lazy[i] * f;
  }
  void push(int i) {
    apply(2 * i, lazy[i]), apply(2 * i + 1, lazy[i]);
    lazy[i] = Action{};
  }
  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }
};

struct node {
  int mx = -1;
  friend node operator*(const node& a, const node& b) {
    return a.mx < b.mx ? b : a;
  }
};
struct action {
  int v;
  node operator()(node x) const {
    x.mx += v;
    return x;
  }
  friend action operator*(const action& f, const action& g) {
    return {f.v + g.v};
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = i - a[i] + 1;
    if (a[i] < 0) a[i] = n;
  }

  vector<vector<pair<int, int>>> l_id(n + 1);
  for (int id = 0; id < q; ++id) {
    int x, y;
    cin >> x >> y;
    int l = x, r = n - y;
    l_id[r].emplace_back(l, id);
  }

  vector<int> res(q);
  lazy_segment_tree<node, action> seg(n, [](int) -> node { return {0}; });
  for (int i = 0; i < n; ++i) {
    int j = seg.backward_search(0, i + 1,
                                [&](node x) -> bool { return x.mx < a[i]; });
    seg.act(0, j + 1, {1});
    for (auto [l, id] : l_id[i + 1]) res[id] = seg.get(l).mx;
  }

  for (auto&& e : res) cout << e << '\n';
}