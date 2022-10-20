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

template <class S>
auto rle(const S& s) {
  std::vector<std::pair<typename S::value_type, int>> res;
  for (const auto& c : s)
    if (empty(res) or res.back().first != c)
      res.emplace_back(c, 1);
    else
      ++res.back().second;
  return res;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto pos = s.find('W');
    if (pos == string::npos) {
      cout << max(2 * k - 1, 0) << '\n';
      continue;
    }
    int ans = count(begin(s), end(s), 'W');
    for (int i : rep(1, n)) ans += s[i - 1] == 'W' and s[i] == 'W';
    auto v = rle(s);
    vector<int> ls;
    int cnt{};
    for (int j : rep(size(v))) {
      auto [c, len] = v[j];
      if (c != 'L') continue;
      if (j == 0 or j == int(size(v)) - 1) {
        cnt += len;
      } else {
        ls.push_back(len);
      }
    }
    sort(begin(ls), end(ls));
    {
      for (int len : ls) {
        for (int i : rep(len)) {
          int cur = 2 + (i == len - 1);
          if (k-- > 0) ans += cur;
        }
      }
    }
    {
      while (cnt--) {
        if (k-- > 0) ans += 2;
      }
    }
    cout << ans << '\n';
  }
}