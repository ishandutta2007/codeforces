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

#pragma GCC target("bmi,bmi2,lzcnt,popcnt")

#include <x86intrin.h>

struct fenwick_set {
  int n, m, sz = 0;
  vector<uint64_t> dat;
  vector<int> tree;
  fenwick_set(int _n = 0) : n(_n), m(n / 64 + 1), dat(m), tree(m + 1) {}
  int operator[](int i) const { return dat[i / 64] >> i % 64 & 1; }
  void set() {
    sz = n;
    fill(begin(dat), end(dat), -1);
    for (int j = 1; j <= m; ++j) {
      tree[j] = _blsi_u64(j) * 64;
    }
  }
  void set(int i) {
    if ((*this)[i]) return;
    ++sz;
    dat[i / 64] |= 1uLL << i % 64;
    for (int j = i / 64 + 1; j <= m; j += _blsi_u64(j)) {
      ++tree[j];
    }
  }
  void reset() {
    sz = 0;
    fill(begin(dat), end(dat), 0);
    fill(begin(tree), end(tree), 0);
  }
  void reset(int i) {
    if ((*this)[i] == 0) return;
    --sz;
    dat[i / 64] &= ~(1uLL << i % 64);
    for (int j = i / 64 + 1; j <= m; j += _blsi_u64(j)) {
      --tree[j];
    }
  }
  int rank(int i) const {
    i = clamp(i, 0, n);
    int res = _popcnt64(_bzhi_u64(dat[i / 64], i % 64));
    for (int j = i / 64; j; j = _blsr_u64(j)) {
      res += tree[j];
    }
    return res;
  }
  int select(int k) const {
    if (k < 0) return -1;
    if (k >= sz) return n;
    int j = 0;
    for (int w = 1 << __lg(m); w; w >>= 1) {
      if (j + w <= m and tree[j + w] <= k) {
        j += w;
        k -= tree[j];
      }
    }
    return j * 64 + _tzcnt_u64(_pdep_u64(1uLL << k, dat[j]));
  }
  int pred(int i) const { return select(rank(i) - 1); }
  int succ(int i) const { return select(rank(i + 1)); }
};

constexpr int Inf = 0x3f3f3f3f;

struct Node {
  int mx = -Inf;
  friend Node operator*(const Node& a, const Node& b) {
    return a.mx < b.mx ? b : a;
  }
};
struct Action {
  int v = 0;
  Node operator()(Node x) const {
    x.mx += v;
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
  vector<int> h(n);
  generate(ALL(h), scan<>);
  int q = scan();
  vector<int> l(q), r(q), w(q);
  for (int id : Rep(q)) l[id] = scan() - 1, r[id] = scan(), w[id] = scan();

  vector<int> order(n);
  iota(ALL(order), 0);
  sort(ALL(order), [&](int i, int j) { return h[i] > h[j]; });

  vector ok(q, 1), ng(q, int(1e9) + 1);
  while (true) {
    map<int, vector<int>, greater<>> mp;
    for (int id : Rep(q))
      if (ng[id] - ok[id] > 1) mp[(ok[id] + ng[id]) / 2].push_back(id);
    if (empty(mp)) break;

    LazySegtree<Node, Action> seg(n + 1, [] { return Node{0}; });
    fenwick_set f(n);
    f.set();

    auto go = [&](int i) {
      f.reset(i);
      seg.act(f.pred(i) + 1, i + 1, {seg.get(i + 1).mx + 1});
    };

    auto it = begin(order);
    for (auto [k, v] : mp) {
      while (it != end(order) and h[*it] >= k) {
        go(*it);
        ++it;
      }
      for (int id : v)
        (seg.fold(l[id], r[id] - w[id] + 1).mx >= w[id] ? ok[id] : ng[id]) = k;
    }
  }

  for (auto&& e : ok) cout << e << '\n';
}