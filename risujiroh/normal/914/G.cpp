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
  vector<int> freq(1 << 17);
  while (n--) {
    int a;
    cin >> a;
    ++freq[a];
  }
  using Mint = Fp<int(1e9) + 7>;
  vector<Mint> fib(1 << 17);
  fib[1] = 1;
  for (int i = 2; i < 1 << 17; ++i) fib[i] = fib[i - 1] + fib[i - 2];
  vector<int64_t> a(1 << 17);
  for (int i = 0; i < 1 << 17; ++i)
    if (i == 0) {
      a[0] += int64_t(freq[0]) * freq[0];
    } else {
      for (int mask = i ^ ~-(1 << (__lg(i) + 1)), j = mask;; j = (j - 1) & mask) {
        a[i | j] += int64_t(2) * freq[i] * freq[j];
        if (j == 0) break;
      }
    }
  vector<int64_t> c(begin(freq), end(freq));
  for (int step = 1; step < 1 << 17; step *= 2)
    for (int offset = 0; offset < 1 << 17; offset += 2 * step)
      for (int i = offset; i < offset + step; ++i) {
        auto x = c[i], y = c[i + step];
        c[i] = x + y;
        c[i + step] = x - y;
      }
  for (auto&& e : c) e *= e;
  for (int step = 1; step < 1 << 17; step *= 2)
    for (int offset = 0; offset < 1 << 17; offset += 2 * step)
      for (int i = offset; i < offset + step; ++i) {
        auto x = c[i], y = c[i + step];
        c[i] = (x + y) / 2;
        c[i + step] = (x - y) / 2;
      }
  vector<Mint> f(1 << 17), g(1 << 17), h(1 << 17);
  for (int i = 0; i < 1 << 17; ++i) {
    f[i] = fib[i] * a[i];
    g[i] = fib[i] * freq[i];
    h[i] = fib[i] * c[i];
  }
  for (int step = 1; step < 1 << 17; step *= 2)
    for (int offset = 0; offset < 1 << 17; offset += 2 * step)
      for (int i = offset; i < offset + step; ++i) {
        f[i] += f[i + step];
        g[i] += g[i + step];
        h[i] += h[i + step];
      }
  for (int i = 0; i < 1 << 17; ++i) f[i] *= g[i] * h[i];
  for (int step = 1; step < 1 << 17; step *= 2)
    for (int offset = 0; offset < 1 << 17; offset += 2 * step)
      for (int i = offset; i < offset + step; ++i) f[i] -= f[i + step];
  Mint ans;
  for (int i = 1; i < 1 << 17; i *= 2) ans += f[i];
  cout << ans.val() << '\n';
}