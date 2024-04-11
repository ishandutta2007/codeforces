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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  vector<int64_t> a(n), b(n);
  generate(ALL(a), scan<>);
  generate(ALL(b), scan<>);
  auto base = inner_product(ALL(a), begin(b), int64_t(0));
  auto ans = base;
  for (int m : Rep(n)) {
    int l = m, r = m + 1;
    auto cur = base;
    while (0 < l and r < n) {
      --l;
      cur -= a[l] * b[l];
      cur -= a[r] * b[r];
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ++r;
      chmax(ans, cur);
    }
  }
  for (int m : Rep(1, n)) {
    int l = m, r = m;
    auto cur = base;
    while (0 < l and r < n) {
      --l;
      cur -= a[l] * b[l];
      cur -= a[r] * b[r];
      cur += a[l] * b[r];
      cur += a[r] * b[l];
      ++r;
      chmax(ans, cur);
    }
  }
  cout << ans << '\n';
}