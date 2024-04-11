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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto&& e : a) cin >> e;
    for (auto&& e : b) cin >> e;
    for (auto&& e : c) cin >> e;
    vector<int> p(n);
    for (int i : rep(n)) {
      if (i == 0) {
        p[i] = a[i];
      } else if (i == n - 1) {
        for (int e : {a[i], b[i], c[i]})
          if (e != p[i - 1] and e != p[0]) {
            p[i] = e;
            break;
          }
      } else {
        if (a[i] != p[i - 1])
          p[i] = a[i];
        else
          p[i] = b[i];
      }
    }
    for (int i : rep(n)) cout << p[i] << " \n"[i == n - 1];
  }
}