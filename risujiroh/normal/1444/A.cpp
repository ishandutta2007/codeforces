// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iter {
    int i;
    constexpr void operator++() { ++i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr rep(int n) : rep(0, n) {}
  constexpr iter begin() const { return {l}; }
  constexpr iter end() const { return {r}; }
};
struct per {
  struct iter {
    int i;
    constexpr void operator++() { --i; }
    constexpr int operator*() const { return i; }
    friend constexpr bool operator!=(iter a, iter b) { return *a != *b; }
  };
  const int l, r;
  constexpr per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  constexpr per(int n) : per(0, n) {}
  constexpr iter begin() const { return {r - 1}; }
  constexpr iter end() const { return {l - 1}; }
};
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

template <class T>
std::map<T, int> factorize(T n) {
  std::map<T, int> res;
  for (T i = 2; i * i <= n; ++i)
    while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

template <class T, class U, class BinaryOperation = std::multiplies<>>
constexpr T power(T a, U n, T init = 1,
                  BinaryOperation binary_op = BinaryOperation{}) {
  static_assert(std::is_integral_v<U> and not std::is_same_v<U, bool>);
  assert(n >= 0);
  while (n) {
    if (n & 1) init = binary_op(init, a);
    if (n >>= 1) a = binary_op(a, a);
  }
  return init;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int64_t p, q;
    cin >> p >> q;
    if (p % q) {
      cout << p << '\n';
      continue;
    }
    int64_t ans = -1;
    for (auto [x, y] : factorize(q)) {
      auto cur = p;
      while (cur % x == 0) cur /= x;
      cur *= power(x, y - 1);
      chmax(ans, cur);
    }
    cout << ans << '\n';
  }
}