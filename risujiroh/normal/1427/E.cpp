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
  int x;
  cin >> x;

  vector<string> ans;
  set<int64_t> se{x};
  auto f = [&](char op, int64_t a, int64_t b) -> int64_t {
    assert(se.count(a));
    assert(se.count(b));
    ans.push_back(to_string(a) + " " + op + " " + to_string(b));
    if (op == '+') {
      se.insert(a + b);
      return a + b;
    } else if (op == '^') {
      se.insert(a ^ b);
      return a ^ b;
    } else
      assert(false);
  };

  f('^', x, x);

  auto mul = [&](int64_t a, int64_t b) -> int64_t {
    assert(se.count(a));
    assert(0 <= b), assert(b < (1 << 20));
    int64_t sum{};
    for (int s : rep(20)) {
      if (b >> s & 1) {
        f('+', sum, a << s);
        sum += a << s;
      }
      f('+', a << s, a << s);
    }
    assert(sum == a * b);
    return sum;
  };

  int64_t inv = x;
  for (int _ = 3; _--;) {
    inv *= 2 - x * inv;
    inv &= ~-(1 << 20);
  }
  auto prod = mul(x, inv);
  cerr << bitset<60>(x) << '\n';
  cerr << bitset<60>(prod) << '\n';
  auto y = mul(prod, 1 << __lg(x));
  cerr << bitset<60>(y) << '\n';
  auto sum = f('+', x, y);
  auto xr = f('^', x, y);
  cerr << bitset<60>(sum) << '\n';
  cerr << bitset<60>(xr) << '\n';
  auto p2 = f('^', sum, xr);
  cerr << bitset<60>(p2) << '\n';
  assert((p2 & (p2 - 1)) == 0);
  mul(p2, (1 << 20) / p2);
  auto prod1 = mul(1 << 20, prod >> 20);
  f('^', prod, prod1);
  assert(se.count(1));

  cout << size(ans) << '\n';
  for (auto&& e : ans) cout << e << '\n';
}