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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;
    if (c == '+')
      cin >> a[i];
    else if (c == '-')
      a[i] = -1;
    else
      assert(false);
  }
  using Mint = Fp<998244353>;
  Mint ans;
  for (int pos = 0; pos < n; ++pos) {
    if (a[pos] == -1) continue;
    vector<Mint> f(pos + 1);
    f[0] = 1;
    for (int i = 0; i < pos; ++i) {
      auto nf = f;
      for (int le = 0; le <= i; ++le)
        if (a[i] == -1)
          nf[max(le - 1, 0)] += f[le];
        else if (a[i] <= a[pos])
          nf[le + 1] += f[le];
        else
          nf[le] += f[le];
      f = move(nf);
    }
    vector<Mint> g(n - pos);
    g[0] = 1;
    for (int i = n; i-- > pos + 1;) {
      auto ng = g;
      for (int x = 0; x < n - i; ++x)
        if (a[i] == -1)
          ng[x + 1] += g[x];
        else if (a[i] < a[pos])
          ng[max(x - 1, 0)] += g[x];
        else
          ng[x] += g[x];
      g = move(ng);
    }
    for (int le = 0; le <= pos; ++le)
      for (int x = 0; x < n - pos; ++x)
        if (le >= x) ans += a[pos] * f[le] * g[x];
  }
  cout << ans.val() << '\n';
}