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

template <class F>
struct y_combinator : private F {
  y_combinator(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

struct random : std::mt19937 {
  using std::mt19937::mt19937;
  using std::mt19937::operator();

  static int64_t gen_seed() {
    return std::chrono::steady_clock::now().time_since_epoch().count();
  }

  random() : std::mt19937(gen_seed()) {}

  template <class Int>
  auto operator()(Int a, Int b)
      -> std::enable_if_t<std::is_integral_v<Int>, Int> {
    return std::uniform_int_distribution<Int>(a, b)(*this);
  }
  template <class Real>
  auto operator()(Real a, Real b)
      -> std::enable_if_t<std::is_floating_point_v<Real>, Real> {
    return std::uniform_real_distribution<Real>(a, b)(*this);
  }
} rng;

struct splitmix64_hash {
  static inline const uint64_t r =
      std::chrono::steady_clock::now().time_since_epoch().count();
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const { return splitmix64(x + r); }
};
template <class Key, class T>
using hash_map = __gnu_pbds::gp_hash_table<Key, T, splitmix64_hash>;
template <class Key>
using hash_set = hash_map<Key, __gnu_pbds::null_type>;

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr auto inf = numeric_limits<int64_t>::max() / 2;

  int n, k;
  cin >> n >> k;
  vector<int> l(n), r(n), a(n);
#ifdef LOCAL
  for (int i : rep(n)) {
    l[i] = (i ? r[i - 1] : 1) + rng(0, 9);
    r[i] = l[i] + rng(0, 9);
  }
  generate(begin(a), end(a), bind(rng, 1, 9));
#else
  for (int i : rep(n)) cin >> l[i] >> r[i] >> a[i];
#endif

  /*vector dp(n + 1, vector(k + 1, inf));
  fill(begin(dp[n]), end(dp[n]), 0);

  for (int i : per(n)) {
    for (int x : rep(k + 1)) {
      if (a[i] > x + k * int64_t(r[i] - l[i])) continue;
      int y = (x - a[i]) % k;
      if (y < 0) y += k;
      chmin(dp[i][x], a[i] + dp[i + 1][y]);
      if (i + 1 < n and l[i] + (a[i] - x + k - 1) / k < l[i + 1])
        chmin(dp[i][x], x + int64_t(a[i] - x + k - 1) / k * k + dp[i + 1][k]);
    }
  }*/

  vector<hash_map<int, int64_t>> mp(n);
  y_combinator f = [&](auto&& self, int i, int x) -> int64_t {
    if (i == n) return 0;
    if (a[i] > x + k * int64_t(r[i] - l[i])) return inf;
    if (mp[i].find(x) != end(mp[i])) return mp[i][x];
    auto res = inf;
    int y = (x - a[i]) % k;
    if (y < 0) y += k;
    chmin(res, a[i] + self(i + 1, y));
    if (i + 1 < n and l[i] + (a[i] - x + k - 1) / k < l[i + 1])
      chmin(res, x + int64_t(a[i] - x + k - 1) / k * k + self(i + 1, k));
    return mp[i][x] = res;
  };

  auto ans = f(0, k);
  if (ans == inf) ans = -1;
  cout << ans << '\n';
}