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

#ifdef LOCAL
  constexpr int lim = 2;
#else
  constexpr int lim = 500;
#endif

  int n, m;
  cin >> n >> m;
  vector dp(2, vector(60, vector<bitset<lim>>(n)));
  while (m--) {
    int i, j, t;
    cin >> i >> j >> t;
    --i, --j;
    dp[t][0][i][j] = 1;
  }
  for (int s : rep(1, 60))
    for (int t : rep(2)) {
      vector<bitset<lim>> transposed(n);
      for (int j : rep(n))
        for (int k : rep(n)) transposed[j][k] = dp[t ^ 1][s - 1][k][j];
      for (int i : rep(n))
        for (int j : rep(n))
          dp[t][s][i][j] = (dp[t][s - 1][i] & transposed[j]).any();
    }
  int64_t ans{};
  bitset<lim> bs;
  bs[0] = 1;
  int t = 0;
  for (int s : per(60)) {
    bitset<lim> nbs;
    for (int i : rep(n))
      if (bs[i]) nbs |= dp[t][s][i];
    if (nbs.any()) {
      ans |= int64_t(1) << s;
      swap(bs, nbs);
      t ^= 1;
    }
  }
  if (ans > int64_t(1e18)) ans = -1;
  cout << ans << '\n';
}