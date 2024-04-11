#include <bits/extc++.h>

template <uint32_t Modulus>
struct modular {
  static_assert(int(Modulus) > 0, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }

  modular() : v(0) {}
  modular(int64_t x) : v(x % Modulus) {
    if (int(v) < 0) v += Modulus;
  }

  explicit operator int() const { return v; }
  modular& operator++() { return ++v == Modulus ? v = 0 : 0, *this; }
  modular& operator--() { return --(v ? v : v = Modulus), *this; }
  modular operator+() const { return *this; }
  modular operator-() const {
    modular res;
    res.v = v ? Modulus - v : 0;
    return res;
  }
  modular& operator*=(modular b) {
    v = uint64_t(v) * b.v % Modulus;
    return *this;
  }
  modular& operator/=(modular b) {
    auto [x, gcd] = extgcd(b.v, Modulus);
    assert(gcd == 1);
    return *this *= x;
  }
  modular& operator+=(modular b) {
    v += b.v - Modulus;
    if (int(v) < 0) v += Modulus;
    return *this;
  }
  modular& operator-=(modular b) {
    v -= b.v;
    if (int(v) < 0) v += Modulus;
    return *this;
  }

  friend modular operator++(modular& a, int) {
    return std::exchange(a, ++modular(a));
  }
  friend modular operator--(modular& a, int) {
    return std::exchange(a, --modular(a));
  }
  friend modular operator*(modular a, modular b) { return a *= b; }
  friend modular operator/(modular a, modular b) { return a /= b; }
  friend modular operator+(modular a, modular b) { return a += b; }
  friend modular operator-(modular a, modular b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, modular& b) {
    int64_t x;
    return is >> x, b = x, is;
  }
  friend std::ostream& operator<<(std::ostream& os, modular b) {
    return os << b.v;
  }
  friend bool operator==(modular a, modular b) { return a.v == b.v; }
  friend bool operator!=(modular a, modular b) { return a.v != b.v; }

 private:
  static std::pair<int, int> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) {
      int q = a / b;
      std::swap(x[0] -= q * x[1], x[1]);
      std::swap(a -= q * b, b);
    }
    return {x[0], a};
  }

  uint32_t v;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  int64_t len;
  cin >> n >> len >> k;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  auto s = a;
  sort(begin(s), end(s));
  auto q = len / n, r = len % n;

  using mint = modular<int(1e9) + 7>;
  mint ans;
  vector<mint> dp(n);
  dp[0] = 1;
  for (int j = 1; j <= k; ++j) {
    vector<mint> pref(n + 1);
    for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + dp[i];
    vector<mint> ndp(n);
    for (int i = 0; i < n; ++i) {
      ndp[i] = pref[upper_bound(begin(s), end(s), s[i]) - begin(s)];
    }
    swap(dp, ndp);
    ans += accumulate(begin(dp), end(dp), mint{}) * max(q - j + 1, int64_t{});
    if (j <= q + 1)
      for (int i = 0; i < r; ++i)
        ans += dp[lower_bound(begin(s), end(s), a[i]) - begin(s)];
  }

  cout << ans << '\n';
}