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

int64_t f(int64_t n) {
  int64_t ans = 0, cur = 0, sum = 0;
  for (char c : to_string(n)) {
    ans *= 10;
    ans += cur * 45;
    for (int i : Rep(c - '0')) ans += sum + i;
    cur *= 10;
    cur += c - '0';
    sum += c - '0';
  }
  return ans;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto a = scan<int64_t>();
  int64_t ng = 0, ok = 1e17;
  while (ok - ng > 1) {
    auto mid = (ng + ok) / 2;
    (f(mid) >= a ? ok : ng) = mid;
  }
  int64_t l = 1, r = ok;
  while (true) {
    while (f(r) - f(l) < a) ++r;
    if (f(r) - f(l) == a) {
      cout << l << ' ' << r - 1 << '\n';
      exit(0);
    }
    ++l;
  }
}