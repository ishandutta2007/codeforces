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
  cout << fixed << setprecision(20);

  using num = double;

  int tt;
  cin >> tt;
  while (tt--) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    a.push_back(l);
    adjacent_difference(begin(a), end(a), begin(a));
    n = size(a);

    auto f = [&](num m, bool rev = false) -> num {
      if (rev) reverse(begin(a), end(a));
      num res{};
      num v = 1;
      for (int e : a) {
        num t = min(e / v, m);
        res += t * v;
        m -= t;
        v += 1;
      }
      if (rev) reverse(begin(a), end(a));
      return res;
    };

    num ok = 0, ng = 1e9;
    for (int _ : per(60)) {
      num mid = (ok + ng) / 2;
      (f(mid) + f(mid, true) < l ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}