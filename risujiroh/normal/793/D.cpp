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

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  constexpr int inf = 0x3f3f3f3f;

  int n, need;
  cin >> n >> need;
  --need;
  int m;
  cin >> m;
  vector cost(n + 2, vector(n + 2, inf));
  while (m--) {
    int u, v, c;
    cin >> u >> v >> c;
    chmin(cost[u][v], c);
  }

  vector dp(n + 2, vector(n + 2, 0));
  while (need--) {
    vector ndp(n + 2, vector(n + 2, inf));
    for (int i : rep(n + 2))
      for (int j : rep(n + 2))
        for (int k : rep(min(i, j) + 1, max(i, j)))
          chmin(ndp[i][j], cost[j][k] + min(dp[i][k], dp[j][k]));
    swap(dp, ndp);
  }

  int ans = inf;
  for (int i : rep(1, n + 1)) {
    chmin(ans, dp[0][i]);
    chmin(ans, dp[n + 1][i]);
  }
  if (ans == inf) ans = -1;
  cout << ans << '\n';
}