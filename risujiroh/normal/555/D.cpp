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

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  vector<pair<int, int>> p(n);
  for (int i : rep(n)) {
    cin >> x[i];
    p[i] = {x[i], i};
  }
  sort(begin(p), end(p));

  y_combinator solve = [&](auto&& self, int i, int l) -> int {
    int j = prev(lower_bound(begin(p), end(p), pair{x[i] + l + 1, 0}))->second;
    l -= x[j] - x[i];
    int k = lower_bound(begin(p), end(p), pair{x[j] - l, 0})->second;
    if (j == k) return j;
    l -= x[j] - x[k];
    l %= 2 * (x[j] - x[k]);
    return self(k, l);
  };

  while (q--) {
    int i, l;
    cin >> i >> l;
    --i;
    cout << solve(i, l) + 1 << '\n';
  }
}