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
  auto s = scan<string>();
  int n = size(s);
  int64_t x = scan();
  int64_t y = scan();

  vector f(2, Fenwick<int>(n, [] { return 0; }));
  for (int i : Rep(n))
    if (s[i] == '1')
      f[1].add(i, +1);
    else
      f[0].add(i, +1);

  int64_t cur = 0;
  for (int i : Rep(n))
    if (s[i] == '1')
      cur += f[0].sum(i) * x;
    else
      cur += f[1].sum(i) * y;

  auto ans = cur;
  for (int i : Rep(n))
    if (s[i] == '?') {
      cur -= f[1].sum(i) * y;
      cur -= f[1].sum(i + 1, n) * x;
      cur += f[0].sum(i) * x;
      cur += f[0].sum(i + 1, n) * y;
      f[0].add(i, -1);
      f[1].add(i, +1);
      chmin(ans, cur);
    }
  for (int i : Rep(n))
    if (s[i] == '?') {
      cur -= f[0].sum(i) * x;
      cur -= f[0].sum(i + 1, n) * y;
      cur += f[1].sum(i) * y;
      cur += f[1].sum(i + 1, n) * x;
      f[1].add(i, -1);
      f[0].add(i, +1);
      chmin(ans, cur);
    }
  cout << ans << '\n';
}