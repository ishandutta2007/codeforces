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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<vector<int>> ss(n + 1);
  for (int s : rep(1, n)) ss[gcd(s, n)].push_back(s);
  int64_t ans{};
  for (int g : rep(1, n + 1))
    if (n % g == 0) {
      vector<int> mx(g);
      for (int i : rep(n)) chmax(mx[i % g], a[i]);
      vector<int> pos{-1};
      for (int i : rep(2 * n))
        if (mx[i % g] > a[i % n]) pos.push_back(i);
      pos.push_back(2 * n);
      auto it = prev(end(pos));
      for (int l : per(n)) {
        while (l <= *prev(it)) --it;
        ans += upper_bound(begin(ss[g]), end(ss[g]), *it - l) - begin(ss[g]);
      }
    }
  cout << ans << '\n';
}