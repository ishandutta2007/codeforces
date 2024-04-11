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
  cout << fixed << setprecision(20);

  using num = long double;
  constexpr num eps = 1e-10, inf = 1e10;

  auto f = [&](num l, num r, num s, num v) -> pair<num, num> {
    if (v > eps) {
      return {max((l - s) / v, num{}), max((r - s) / v, num{})};
    } else if (v < -eps) {
      return {max((r - s) / v, num{}), max((l - s) / v, num{})};
    } else {
      if (l + eps < s and s < r - eps) return {0, inf};
      return {0, 0};
    }
  };

  int n;
  cin >> n;
  num lx, ly, rx, ry;
  cin >> lx >> ly >> rx >> ry;
  vector<pair<num, num>> v;
  while (n--) {
    num x, y, vx, vy;
    cin >> x >> y >> vx >> vy;
    v.push_back(f(lx, rx, x, vx));
    v.push_back(f(ly, ry, y, vy));
  }
  num a = 0, b = inf;
  for (auto&& [l, r] : v) {
    chmax(a, l);
    chmin(b, r);
  }
  if (b - a < eps)
    cout << "-1\n";
  else
    cout << a << '\n';
}