#include <bits/stdc++.h>

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int> a(n);
  generate(ALL(a), scan<>);
  sort(ALL(a), greater{});
  int m = scan();
  a.resize(m);
  vector<pair<char, int>> ct(m);
  for (auto&& [c, t] : ct) {
    c = scan<char>();
    t = scan() - 1;
  }
  reverse(ALL(ct));
  vector<int> f(1 << m);
  for (auto&& [c, t] : ct) {
    if (c == 'p' and t == 0) {
      vector nf(1 << m, -Inf);
      for (int mask : Rep(1, 1 << m))
        chmax(nf[mask], f[mask & (mask - 1)] + a[__builtin_ctz(mask)]);
      f = move(nf);
    } else if (c == 'p' and t == 1) {
      vector nf(1 << m, +Inf);
      for (int mask : Rep(1, 1 << m))
        chmin(nf[mask], f[mask & (mask - 1)] - a[__builtin_ctz(mask)]);
      f = move(nf);
    } else if (c == 'b' and t == 0) {
      vector nf(1 << m, -Inf);
      for (int mask : Rep(1, 1 << m))
        for (int i : Rep(m))
          if (mask >> i & 1) chmax(nf[mask], f[mask ^ 1 << i]);
      f = move(nf);
    } else if (c == 'b' and t == 1) {
      vector nf(1 << m, +Inf);
      for (int mask : Rep(1, 1 << m))
        for (int i : Rep(m))
          if (mask >> i & 1) chmin(nf[mask], f[mask ^ 1 << i]);
      f = move(nf);
    } else
      assert(false);
  }
  DUMP(f);

  cout << f.back() << '\n';
}