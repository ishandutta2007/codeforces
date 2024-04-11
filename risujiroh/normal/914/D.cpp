#include <bits/stdc++.h>

template <class Derived> class SegtreeBase {
 protected:
  template <class F> void for_each_node(int l, int r, bool reverse, F f) const {
    int h = 0;
    for (l += size() - 1, r += size(); (r >> h) - (l >> h) > 1;) ++h;
    if (not reverse) {
      for (int s = 0; s < h; ++s)
        if (int i = l >> s; ~i & 1) f(i + 1);
      for (int s = h; s--;)
        if (int i = r >> s; i & 1) f(i - 1);
    } else {
      for (int s = 0; s < h; ++s)
        if (int i = r >> s; i & 1) f(i - 1);
      for (int s = h; s--;)
        if (int i = l >> s; ~i & 1) f(i + 1);
    }
  }
  template <class F> void for_each_ancestor(int l, int r, bool reverse, F f) const {
    if (l == r) return;
    int hl = std::__lg(l >>= __builtin_ctz(l += size()));
    int hr = std::__lg(r >>= __builtin_ctz(r += size()));
    if (hl > hr) std::swap(hl, hr), std::swap(l, r);
    auto go = [&](int s) {
      if (s < hl) f(l >> (hl - s));
      if (s >= hl or l >> (hl - s) != r >> (hr - s)) f(r >> (hr - s));
    };
    if (not reverse)
      for (int s = 0; s < hr; ++s) go(s);
    else
      for (int s = hr; s--;) go(s);
  }

 private:
  int size() const { return static_cast<const Derived*>(this)->size(); }
};

template <class Monoid> class Segtree : public SegtreeBase<Segtree<Monoid>> {
 public:
  using SegtreeBase<Segtree>::for_each_node;
  using SegtreeBase<Segtree>::for_each_ancestor;
  using T = std::decay_t<decltype(Monoid::id)>;

  Segtree() {}
  template <class Generator> Segtree(int n, Generator gen) : tree(2 * n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen(i);
    for (int i = n; i-- > 1;) pull(i);
  }
  explicit Segtree(int n, const T& a = Monoid::id) : Segtree(n, [&](int) -> T { return a; }) {}

  int size() const { return std::size(tree) / 2; }
  const T& operator[](int i) const {
    __glibcxx_assert(0 <= i and i < size());
    return tree[size() + i];
  }
  T fold(int l, int r) const {
    __glibcxx_assert(0 <= l and l <= r and r <= size());
    T res = Monoid::id;
    for_each_node(l, r, false, [&](int i) { res = Monoid::op(res, tree[i]); });
    return res;
  }
  T fold_all_rotated() const { return size() ? tree[1] : Monoid::id; }
  template <class Function> void update(int i, Function func) {
    __glibcxx_assert(0 <= i and i < size());
    tree[size() + i] = func(tree[size() + i]);
    for_each_ancestor(i, i + 1, true, [&](int j) { pull(j); });
  }
  template <class Predicate> int search(int l, int r, Predicate pred) const {
    __glibcxx_assert(0 <= l and l <= r and r <= size());
    __glibcxx_assert(pred(Monoid::id));
    T a = Monoid::id;
    int res = r;
    for_each_node(l, r, false, [&](int i) {
      if (res < r) return;
      if (T na = Monoid::op(a, tree[i]); pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = Monoid::op(a, tree[i *= 2]); pred(na)) a = na, ++i;
      res = i - size();
    });
    return res;
  }
  template <class Predicate> int search_backward(int l, int r, Predicate pred) const {
    __glibcxx_assert(0 <= l and l <= r and r <= size());
    __glibcxx_assert(pred(Monoid::id));
    T a = Monoid::id;
    int res = l - 1;
    for_each_node(l, r, true, [&](int i) {
      if (res >= l) return;
      if (T na = Monoid::op(tree[i], a); pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = Monoid::op(tree[i = 2 * i + 1], a); pred(na)) a = na, --i;
      res = i - size();
    });
    return res;
  }

 private:
  void pull(int i) { tree[i] = Monoid::op(tree[2 * i], tree[2 * i + 1]); }

  std::vector<T> tree;
};

struct Gcd {
  using T = int;
  static T op(const T& a, const T& b) { return std::gcd(a, b); }
  static constexpr T id = 0;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  Segtree<Gcd> seg(n, [](int) {
    int a;
    cin >> a;
    return a;
  });
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      --l;
      int i = seg.search(l, r, [&](int g) { return g % x == 0; });
      if (i == r or gcd(seg.fold(l, i), seg.fold(i + 1, r)) % x == 0)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else {
      int i, x;
      cin >> i >> x;
      --i;
      seg.update(i, [&](int) { return x; });
    }
  }
}