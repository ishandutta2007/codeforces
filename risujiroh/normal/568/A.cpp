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
template <class C>
constexpr int isize(C&& c) {
  using std::size;
  return size(std::forward<C>(c));
}
template <class T, class U>
constexpr bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
constexpr bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
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

using namespace std;

vector<int> sieve(int n) {
  vector<bool> b(n / 3 + 1, true);
  vector<int> res{2, 3};
  for (int p = 5, d = 4; p * p <= n; p += d = 6 - d)
    if (b[p / 3])
      for (int i = p * p, di = p % 3 * 2 * p; i <= n; i += di = 6 * p - di)
        b[i / 3] = false;
  for (int p = 5, d = 4; p <= n; p += d = 6 - d)
    if (b[p / 3]) res.push_back(p);
  while (not res.empty() and res.back() > n) res.pop_back();
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr int lim = 1e8;
  auto primes = sieve(lim);

  auto f = [](int n) -> int {
    int res{};
    while (n) {
      res *= 10;
      res += n % 10;
      n /= 10;
    }
    return res;
  };

  int p, q;
  cin >> p >> q;
  int ans{};
  auto it = begin(primes);
  int64_t pi{}, rub{};
  for (int n = 1; n <= lim; ++n) {
    if (it != end(primes) and *it == n) {
      ++pi;
      ++it;
    }
    rub += n == f(n);
    if (q * pi <= p * rub) ans = max(ans, n);
  }
  cout << ans << '\n';
}