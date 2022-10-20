#include <bits/stdc++.h>

template <class T> struct Combination {
  static std::vector<T> power_table(T a, int n) {
    std::vector<T> res(n + 1);
    res[0] = 1;
    for (int i = 1; i <= n; ++i) res[i] = res[i - 1] * a;
    return res;
  }

  std::vector<T> fact, ifact;

  Combination() {}
  explicit Combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * T(i), ifact[i] = ifact[i - 1] / T(i);
  }

  T binom(int n, int k) const {
    if (k < 0 or (n >= 0 and k > n)) return 0;
    if (int m = -n + k - 1; n < 0) return k & 1 ? -binom(m, k) : binom(m, k);
    return fact[n] * ifact[k] * ifact[n - k];
  }
  T homo(int n, int k) const {
    if (k < 0 or (-n >= 0 and k > -n)) return 0;
    return k & 1 ? -binom(-n, k) : binom(-n, k);
  }
};

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
  using Mint = Fp<int(1e9) + 7>;
  GetInverse<Mint>::init(1e5);
  Combination<Mint> comb(1e5);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    Mint ans;
    for (int x = 0; x <= (n + k - 1) / k; ++x) {
      if (x < 2) {
        ++ans;
        continue;
      }
      Mint t = comb.binom(n - (k - 1) * (x - 1), x);
      // t /= comb.binom(n, x);
      t *= comb.ifact[n];
      t *= comb.fact[x];
      t *= comb.fact[n - x];
      ans += t;
    }
    cout << ans.val() << '\n';
  }
}