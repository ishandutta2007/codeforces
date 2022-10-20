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

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr auto inf = numeric_limits<int64_t>::max() / 2;

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  int q = n / k, r = n % k;

  auto f = [&](int i) -> int {
    if (i <= 0 or i >= n) return 0;
    return a[i] - a[i - 1];
  };

  vector dp(r + 1, -inf);
  dp[0] = 0;
  for (int i : rep(k)) {
    vector ndp(r + 1, -inf);
    for (int x : rep(r + 1)) {
      int pos = q * i + x;
      chmax(ndp[x], dp[x] + f(pos + q));
      if (x < r) chmax(ndp[x + 1], dp[x] + f(pos + q + 1));
    }
    dp = move(ndp);
  }

  cout << a.back() - a[0] - dp[r] << '\n';
}