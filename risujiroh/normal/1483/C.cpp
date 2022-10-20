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

template <class T>
class Segtree : private SegtreeBase {
 public:
  Segtree() {}
  template <class Generator>
  Segtree(int n, Generator gen) : tree(2 * n) {
    for (int i = 0; i < n; ++i) tree[n + i] = gen();
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
      if (T na = tree[i] * a; pred(na)) {
        a = na;
        return;
      }
      while (i < size())
        if (T na = tree[i = 2 * i + 1] * a; pred(na)) a = na, --i;
      res = i - size();
    });
    return res;
  }

 private:
  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }

  std::vector<T> tree;
};

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

constexpr auto Inf = numeric_limits<int64_t>::max() / 2;

struct Node {
  int64_t mx = -Inf;
  friend Node operator*(const Node& a, const Node& b) {
    return a.mx < b.mx ? b : a;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> h(n);
  generate(ALL(h), scan<>);
  vector<int64_t> b(n);
  generate(ALL(b), scan<>);

  Segtree<Node> seg(n + 1, [] { return Node{}; });
  seg.update(0, [](Node) { return Node{0}; });

  stack<int, vector<int>> stk;
  for (int i : Rep(n)) {
    while (not empty(stk) and not(h[stk.top()] < h[i])) stk.pop();
    int prv = empty(stk) ? -1 : stk.top();
    auto t = -Inf;
    if (prv != -1) chmax(t, seg[prv + 1].mx);
    chmax(t, seg.fold(prv + 1, i + 1).mx + b[i]);
    seg.update(i + 1, [&](Node) { return Node{t}; });
    stk.push(i);
  }
  cout << seg[n].mx << '\n';
}