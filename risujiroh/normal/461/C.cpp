#include <bits/stdc++.h>

template <class T>
class Fenwick {
 public:
  Fenwick() {}
  template <class Generator>
  Fenwick(int n, Generator gen) : tree(n) {
    for (int i = 0; i < n; ++i) tree[i] = gen();
    for (int i = 0; i < n; ++i)
      if (int j = i | (i + 1); j < n) tree[j] += tree[i];
  }

  int size() const { return std::size(tree); }
  void add(int i, const T& a) {
    assert(0 <= i), assert(i < size());
    for (; i < size(); i |= i + 1) tree[i] += a;
  }
  T sum(int i) const {
    assert(0 <= i), assert(i <= size());
    T res{};
    for (; i; i &= i - 1) res += tree[i - 1];
    return res;
  }
  T sum(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    return sum(r) - sum(l);
  }
  T get(int i) const {
    assert(0 <= i), assert(i < size());
    return sum(i, i + 1);
  }

 private:
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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();

  Fenwick<int> f(n, [] { return 1; });
  int bg = 0, ed = n;
  bool reversed = false;

  for (int q = scan(); q--;) {
    if (scan() == 1) {
      int p = scan();
      if ((not reversed and 2 * p <= ed - bg) or
          (reversed and 2 * p > ed - bg)) {
        if (2 * p > ed - bg) {
          p = ed - bg - p;
          reversed ^= true;
        }
        bg += p;
        assert(bg < ed);
        for (int i : Rep(p)) f.add(bg + i, f.get(bg - i - 1));
      } else {
        if (2 * p > ed - bg) {
          p = ed - bg - p;
          reversed ^= true;
        }
        ed -= p;
        assert(bg < ed);
        for (int i : Rep(p)) f.add(ed - i - 1, f.get(ed + i));
      }
    } else {
      int l = scan();
      int r = scan();
      if (not reversed) {
        cout << f.sum(bg + l, bg + r) << '\n';
      } else {
        cout << f.sum(ed - r, ed - l) << '\n';
      }
    }
  }
}