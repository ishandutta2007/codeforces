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

  constexpr int lim = 30000;
  constexpr int inf = 0x3f3f3f3f;

  int n, d;
  cin >> n >> d;
  vector<int> cnt(lim + 1);
  while (n--) {
    int p;
    cin >> p;
    ++cnt[p];
  }
  vector _dp(1001, vector(lim + 1, -inf));
  auto dp = begin(_dp) + 500;
  dp[0][d] = cnt[d];
  for (int pos : rep(d, lim))
    for (int x : rep(-500, 501))
      if (dp[x][pos] >= 0)
        for (int y : {x - 1, x, x + 1})
          if (d + y >= 1 and pos + d + y <= lim)
            chmax(dp[y][pos + d + y], dp[x][pos] + cnt[pos + d + y]);

  int ans{};
  for (int pos : rep(d, lim + 1))
    for (int x : rep(-500, 501)) chmax(ans, dp[x][pos]);
  cout << ans << '\n';
}