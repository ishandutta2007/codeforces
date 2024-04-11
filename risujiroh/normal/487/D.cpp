#include <bits/stdc++.h>

template <class T, class U, class AssociativeOp = std::multiplies<>>
constexpr T power(T a, U n, T init = 1, AssociativeOp op = AssociativeOp{}) {
  static_assert(std::is_integral_v<U> and not std::is_same_v<U, bool>);
  assert(n >= 0);
  while (n) {
    if (n & 1) init = op(init, a);
    if (n >>= 1) a = op(a, a);
  }
  return init;
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
  std::vector<T> tree;

  void pull(int i) { tree[i] = tree[2 * i] * tree[2 * i + 1]; }
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l, r;
  Rep(int _l, int _r) : l(_l), r(_r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l}; }
  I end() const { return {r}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l, r;
  Per(int _l, int _r) : l(_l), r(_r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r - 1}; }
  I end() const { return {l - 1}; }
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

int w;

struct Node {
  array<int, 10> to{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  friend Node operator*(const Node& a, const Node& b) {
    Node c;
    for (int j : Rep(10))
      c.to[j] = 0 <= b.to[j] and b.to[j] < w ? a.to[b.to[j]] : b.to[j];
    return c;
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int h, q;
  h = scan(), w = scan(), q = scan();

  auto encode = [&](const string& s) -> int {
    assert(int(size(s)) == w);
    int res = 0;
    for (char c : s) {
      auto pos = string{"<^>"}.find(c);
      assert(pos != string::npos);
      res = res * 3 + pos;
    }
    return res;
  };

  vector<Node> tab(power(3, w));
  {
    string s;
    Fix([&](auto self) -> void {
      if (int(size(s)) == w) {
        auto&& e = tab[encode(s)].to;
        for (int j : Rep(w)) {
          int cur = j;
          bool ok = false;
          for (int _ = 20; _--;) {
            if (0 <= cur and cur < w) {
              if (s[cur] == '<') {
                --cur;
              } else if (s[cur] == '>') {
                ++cur;
              } else if (s[cur] == '^') {
                ok = true;
                break;
              } else
                assert(false);
            } else {
              ok = true;
              break;
            }
          }
          e[j] = ok ? cur : -2;
        }
        return;
      }
      for (char c : string{"<^>"}) {
        s += c;
        self();
        s.pop_back();
      }
    })();
  }

  vector<string> s(h);
  generate(ALL(s), scan<string>);
  segment_tree<Node> seg(h, [&](int i) { return tab[encode(s[i])]; });
  for (int r : Rep(1, h + 1))
    for (int l : Rep(r)) DUMP(l, r, seg.fold(l, r).to);
  while (q--) {
    if (scan<char>() == 'A') {
      int i = scan() - 1, j = scan() - 1;
      int l = seg.backward_search(0, i + 1, [&](const Node& e) {
        return 0 <= e.to[j] and e.to[j] < w;
      });
      // DUMP(i, j, w, l);
      // for (int l : Rep(i + 1)) {
      //   DUMP(l, seg.fold(l, i + 1).to[j]);
      // }
      // exit(0);
      if (l != -1 and seg.fold(l, i + 1).to[j] == -2) {
        cout << "-1 -1\n";
      } else if (l == -1) {
        cout << "0 " << seg.fold(0, i + 1).to[j] + 1 << '\n';
      } else {
        cout << l + 1 << ' ' << seg.fold(l, i + 1).to[j] + 1 << '\n';
      }
    } else {
      int i = scan() - 1, j = scan() - 1;
      s[i][j] = scan<char>();
      seg.update(i, [&](const Node&) { return tab[encode(s[i])]; });
    }
  }
}