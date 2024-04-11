#define NDEBUG

#include <bits/stdc++.h>
#include <x86intrin.h>

#define DUMP(...) void(0)

using namespace std;

using uint = unsigned int;
using i64 = long long;
using u64 = unsigned long long;

template <class F> struct fix : F {
  fix(F f) : F(move(f)) {}
  template <class... Args> decltype(auto) operator()(Args&&... args) const {
    return F::operator()(ref(*this), forward<Args>(args)...);
  }
};

template <class T> auto sz(T&& x) {
  auto ret = size(forward<T>(x));
  return make_signed_t<decltype(ret)>(ret);
}

template <class T> T div_floor(T x, T y) { return x / y - ((x ^ y) < 0 && x % y); }
template <class T> T div_ceil(T x, T y) { return x / y + (0 <= (x ^ y) && x % y); }

template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x ? x = forward<U>(y), true : false; }
template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y ? x = forward<U>(y), true : false; }

template <class T> const auto inf_v = numeric_limits<T>::max() / 2;
const auto inf = inf_v<int>;

auto mt = mt19937_64(_rdtsc());
template <class T> T rand(T x, T y) {
  if constexpr (is_integral_v<T>) return uniform_int_distribution(x, y)(mt);
  if constexpr (is_floating_point_v<T>) return uniform_real_distribution(x, y)(mt);
}

auto rep = views::iota;
auto rev = views::reverse;

void solve(int);

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  cin >> t;
  for (auto i : rep(0, t)) solve(i);
}

void solve(int) {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  auto c = array<int, 4>();
  for (auto i : rep(0, n)) {
    ++c[(a[i] & 1) << 1 | (b[i] & 1)];
  }
  auto ans = inf;
  DUMP(c);
  if (c[0b10] == c[0b01]) {
    chmin(ans, c[0b10] + c[0b01]);
  }
  if (c[0b00] + 1 == c[0b11]) {
    chmin(ans, c[0b00] + c[0b11]);
  }
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << '\n';
}