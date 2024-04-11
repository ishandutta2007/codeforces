#include <bits/stdc++.h>

class SegtreeBase {
 public:
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
    const_cast<const SegtreeBase*>(this)->forward(l, r, f);
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
    const_cast<const SegtreeBase*>(this)->backward(l, r, f);
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
    const_cast<const SegtreeBase*>(this)->downward(l, r, f);
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
    const_cast<const SegtreeBase*>(this)->upward(l, r, f);
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
class LazySegtree : private SegtreeBase {
 public:
  LazySegtree() {}
  template <class Generator>
  LazySegtree(int n, Generator gen) : tree(2 * n), lazy(n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen();
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
      if (T na = tree[i] * a; pred(na)) {
        a = na;
        return;
      }
      while (i < size()) {
        push(i);
        if (T na = tree[i = 2 * i + 1] * a; pred(na)) a = na, --i;
      }
      res = i - size();
    });
    return res;
  }

 private:
  void apply(int i, const Action& f) {
    tree[i] = f(tree[i]);
    if (i < size()) lazy[i] = lazy[i] * f;
  }
  void push(int i) {
    apply(2 * i, lazy[i]), apply(2 * i + 1, lazy[i]);
    lazy[i] = Action{};
  }
  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }

  std::vector<T> tree;
  std::vector<Action> lazy;
};

template <class ForwardIterator,
          class T = typename std::iterator_traits<ForwardIterator>::value_type>
std::vector<std::pair<T, int>> rle(ForwardIterator first,
                                   ForwardIterator last) {
  std::vector<std::pair<T, int>> res;
  int n = 0;
  for (auto it = first; it != last; ++it)
    n += std::next(it) == last or not(*it == *std::next(it));
  res.reserve(n);
  for (; first != last; ++first)
    if (std::empty(res) or not(res.back().first == *first))
      res.emplace_back(*first, 1);
    else
      ++res.back().second;
  return res;
}

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

constexpr auto Inf = numeric_limits<int>::max() / 2;

struct Node {
  int mn = Inf;
  friend Node operator*(const Node& a, const Node& b) {
    return b.mn < a.mn ? b : a;
  }
};
struct Action {
  int v = 0;
  Node operator()(Node x) const {
    x.mn += v;
    return x;
  }
  friend Action operator*(const Action& f, const Action& g) {
    return {f.v + g.v};
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);
  {
    vector<int> na;
    for (auto&& e : rle(ALL(a))) na.push_back(e.first);
    a = move(na);
    n = size(a);
  }

  LazySegtree<Node, Action> seg(n, [] { return Node{}; });
  vector<int> last(1e5 + 1, -1);
  seg.update(0, [](Node) { return Node{0}; });
  for (int i : Rep(n)) {
    int x = seg.fold(0, n).mn + 1;
    if (last[a[i]] != -1) chmin(x, seg.get(last[a[i]] + 1).mn);
    seg.act(0, i, {1});
    seg.update(i, [&](Node) { return Node{x}; });
    last[a[i]] = i;
  }
  cout << seg.fold(0, n).mn << '\n';
}