#include <bits/stdc++.h>

template <class> class GetInverse;
template <uint32_t P> class Fp {
 public:
  static_assert([](int n) -> bool {
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return 3 <= n and n < 1 << 30;
  }(P));
  static constexpr int mod() { return P; }

  Fp() : v(0) {}
  template <class Int> Fp(const Int& a) : v(a % mod()) { v = (uint64_t(v + P) << 32) % P; }
  int val() const {
    int res = reduce(v) - P;
    return res < 0 ? res + P : res;
  }
  Fp& operator++() { return *this += 1; }
  Fp& operator--() { return *this -= 1; }
  Fp& operator*=(Fp o) { return v = reduce(uint64_t(v) * o.v), *this; }
  Fp& operator/=(Fp o) { return *this *= GetInverse<Fp>{}(o); }
  Fp& operator+=(Fp o) { return v = int(v += o.v - 2 * P) < 0 ? v + 2 * P : v, *this; }
  Fp& operator-=(Fp o) { return v = int(v -= o.v) < 0 ? v + 2 * P : v, *this; }

  friend Fp operator++(Fp& a, int) { return std::exchange(a, ++Fp(a)); }
  friend Fp operator--(Fp& a, int) { return std::exchange(a, --Fp(a)); }
  friend Fp operator+(Fp a) { return a; }
  friend Fp operator-(Fp a) { return Fp{} -= a; }
  friend Fp operator*(Fp a, Fp b) { return a *= b; }
  friend Fp operator/(Fp a, Fp b) { return a /= b; }
  friend Fp operator+(Fp a, Fp b) { return a += b; }
  friend Fp operator-(Fp a, Fp b) { return a -= b; }
  friend bool operator==(Fp a, Fp b) { return a.v == b.v or a.v + P == b.v or a.v == b.v + P; }
  friend bool operator!=(Fp a, Fp b) { return not(a == b); }

 private:
  static constexpr uint32_t R = []() -> uint32_t {
    uint32_t res = -P;
    for (int _ = 4; _--;) res *= P * res + 2;
    return res;
  }();
  static uint32_t reduce(uint64_t x) { return (x + P * uint64_t(R * uint32_t(x))) >> 32; }

  uint32_t v;
};
template <uint32_t P> class GetInverse<Fp<P>> {
 public:
  static void init(int n) {
    inv.reserve(n + 1);
    for (int i = std::size(inv); i <= n;) {
      int q = P / i, j = std::min<int>(P / q, n);
      for (; i <= j; ++i) inv.push_back(-q * inv[P - q * i]);
    }
  }

  Fp<P> operator()(Fp<P> a) const {
    __glibcxx_assert(a.val());
    if ((-a).val() < int(std::size(inv))) return -inv[(-a).val()];
    int y0 = 0, z0 = P, y1 = 1, z1 = a.val();
    while (z1 >= std::max<int>(std::size(inv), 2)) std::swap(y0 -= z0 / z1 * y1, y1), std::swap(z0 %= z1, z1);
    return z1 > 1 ? y1 * inv[z1] : y1;
  }

 private:
  static inline std::vector<Fp<P>> inv{0, 1};
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> c(n), b(n - 1);
  for (auto&& e : c) cin >> e;
  for (auto&& e : b) cin >> e;
  partial_sum(begin(b), end(b), begin(b));
  using Mint = Fp<int(1e9) + 7>;
  auto go = [&](int x) -> Mint {
    vector<Mint> f(accumulate(begin(c), end(c), 0) + 1);
    f[0] = 1;
    int s = x;
    for (int i = 0; i < n; ++i) {
      for (int j = size(f); j-- > c[i] + 1;) f[j] -= f[j - c[i] - 1];
      for (int j = 1; j < int(size(f)); ++j) f[j] += f[j - 1];
      fill(begin(f), begin(f) + clamp(s, 0, int(size(f))), 0);
      if (i + 1 == n) break;
      s += x + b[i];
    }
    return accumulate(begin(f), end(f), Mint(0));
  };
  constexpr int L = 1e5;
  vector<Mint> ans(2 * L + 1);
  int x = 1e5;
  {
    int sb = accumulate(begin(b), end(b), 0);
    int sc = accumulate(begin(c), end(c), 0);
    while (sb + n * x > sc) --x;
  }
  int cnt = 210;
  for (; x >= -L; --x)
    if (cnt-- > 0) {
      ans[L + x] = go(x);
    } else {
      if (x < L) ans[L + x] = ans[L + x + 1];
    }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << ans[L + x].val() << '\n';
  }
}