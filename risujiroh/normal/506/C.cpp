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
  int64_t n, m, k, p;
  cin >> n >> m >> k >> p;
  vector<int64_t> h(n), a(n);
  for (int i = 0; i < n; ++i) cin >> h[i] >> a[i];

  auto check = [&](auto mid) -> bool {
    {
      int64_t s{};
      for (int i : rep(n)) {
        auto need = max(h[i] + a[i] * m - mid, int64_t{});
        s += (need + p - 1) / p;
      }
      if (s > k * m) return false;
    }
    vector<int> suff(k * m + 1);
    for (int i : rep(n)) {
      auto need = max(h[i] + a[i] * m - mid, int64_t{});
      auto rest = (need + p - 1) / p * p - need;
      if (need == 0) continue;
      auto cur = h[i];
      int j = 0;
      while (j < k * m) {
        if (auto mn = min(p - rest, need); j % k == 0 and cur < mn) {
          auto t = (mn - cur + a[i] - 1) / a[i];
          cur += a[i] * t;
          j += k * t;
          if (j >= k * m) break;
        }
        if (need <= p and cur >= need) {
          ++suff[j];
          need = 0;
          break;
        }
        if (cur >= p) {
          ++suff[j];
          need -= p;
          cur -= p;
        } else if (p - cur <= rest) {
          ++suff[j];
          need -= cur;
          rest -= p - cur;
          cur = 0;
        }
        if (j % k == k - 1) cur += a[i];
        ++j;
      }
      if (need > 0) return false;
    }
    for (int j : per(k * m)) {
      suff[j] += suff[j + 1];
      if (suff[j] > k * m - j) return false;
    }
    return true;
  };

  int64_t ng = *max_element(begin(a), end(a)) - 1, ok = 1e13;
  while (ok - ng > 1) {
    auto mid = (ng + ok) / 2;
    (check(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}