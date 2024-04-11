#include <bits/stdc++.h>

template <const int& N> struct Z_ {
  static constexpr int mod() { return N; }
  uint32_t v;
  void normalize() { v = int(v) < 0 ? v + N : v; }
  Z_(int64_t x = 0) : v(x % N) { normalize(); }
  Z_& operator+=(Z_ o) { return v += o.v - N, normalize(), *this; }
  Z_& operator-=(Z_ o) { return v -= o.v, normalize(), *this; }
  Z_& operator*=(Z_ o) { return v = uint64_t(v) * o.v % N, *this; }
  friend Z_ operator-(Z_ a) { return Z_{} - a; }
  friend Z_ operator+(Z_ a, Z_ b) { return a += b; }
  friend Z_ operator-(Z_ a, Z_ b) { return a -= b; }
  friend Z_ operator*(Z_ a, Z_ b) { return a *= b; }
  friend bool operator==(Z_ a, Z_ b) { return a.v == b.v; }
  friend bool operator!=(Z_ a, Z_ b) { return a.v != b.v; }
  friend std::ostream& operator<<(std::ostream& os, Z_ a) { return os << a.v; }
};

template <const int& P> struct F_ : Z_<P> {
  static std::vector<F_> fact, ifact;
  static void reserve(int n) {
    fact.resize(n + 1), ifact.resize(n + 1);
    for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
    for (int i = n; i >= 0; --i) ifact[i] = i < n ? ifact[i + 1] * (i + 1) : pow(fact[n], P - 2);
  }
  static F_ binom(int n, int k) {
    if (n >= 0) return 0 <= k && k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0;
    return (k = std::max(k, n - k)) & 1 ? -binom(k + ~n, k) : binom(k + ~n, k);
  }
  using Z_<P>::Z_;
  F_(Z_<P> x) : Z_<P>::Z_(x) {}
  F_& operator/=(F_ o) { return *this = *this / o; }
  friend F_ operator/(F_ a, F_ b) { return a * inv(b); }
  friend F_ pow(F_ a, int64_t n) {
    if (n == 0) return 1;
    for (; ~n & 1; n >>= 1) a *= a;
    if (n < 0) a = inv(a), n = -n;
    F_ res = a;
    while (n >>= 1)
      if (a *= a, n & 1) res *= a;
    return res;
  }
  friend F_ inv(F_ a) { return a.v < fact.size() ? fact[a.v - 1] * ifact[a.v] : pow(a, P - 2); }
};
template <const int& P> std::vector<F_<P>> F_<P>::fact;
template <const int& P> std::vector<F_<P>> F_<P>::ifact;

constexpr int P = 1e9 + 7;
using Fp = F_<P>;

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  Fp::reserve(4e6);
  int n, q;
  cin >> n >> q;
  vector<Fp> ans(3 * n + 1), b{3, 3, 1};
  for (int i = 0; i <= 3 * n; ++i) ans[i] = Fp::binom(3 * n + 3, i + 1);
  for (int i = 0; i <= 3 * n; ++i) {
    for (int j = 1; j < min(i + 1, 3); ++j) ans[i] -= ans[i - j] * b[j];
    ans[i] /= b[0];
  }
  while (q--) {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
  }
}