#include <bits/stdc++.h>

template <uint32_t Modulus>
struct modular {
  static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static constexpr modular raw(uint32_t _v) {
    modular res;
    res.v = _v;
    return res;
  }

  constexpr modular() : v(0) {}
  constexpr modular(int64_t x) : v(x % Modulus) {
    v = int(v) < 0 ? v + Modulus : v;
  }

  template <class T>
  explicit constexpr operator T() const {
    return v;
  }
  constexpr modular& operator++() {
    v = ++v == Modulus ? 0 : v;
    return *this;
  }
  constexpr modular& operator--() {
    --(v ? v : v = Modulus);
    return *this;
  }
  constexpr modular operator+() const { return *this; }
  constexpr modular operator-() const { return raw(v ? Modulus - v : 0); }
  constexpr modular& operator*=(modular b) {
    v = uint64_t(v) * b.v % Modulus;
    return *this;
  }
  constexpr modular& operator/=(modular b) {
    auto [x, gcd] = extgcd(b.v, Modulus);
    assert(gcd == 1);
    return *this *= x;
  }
  constexpr modular& operator+=(modular b) {
    v = int(v += b.v - Modulus) < 0 ? v + Modulus : v;
    return *this;
  }
  constexpr modular& operator-=(modular b) {
    v = int(v -= b.v) < 0 ? v + Modulus : v;
    return *this;
  }

  friend constexpr modular operator++(modular& a, int) {
    return std::exchange(a, ++modular(a));
  }
  friend constexpr modular operator--(modular& a, int) {
    return std::exchange(a, --modular(a));
  }
  friend constexpr modular operator*(modular a, modular b) { return a *= b; }
  friend constexpr modular operator/(modular a, modular b) { return a /= b; }
  friend constexpr modular operator+(modular a, modular b) { return a += b; }
  friend constexpr modular operator-(modular a, modular b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, modular& b) {
    int64_t x;
    return is >> x, b = x, is;
  }
  friend std::ostream& operator<<(std::ostream& os, modular b) {
    return os << b.v;
  }
  friend constexpr bool operator==(modular a, modular b) { return a.v == b.v; }
  friend constexpr bool operator!=(modular a, modular b) { return a.v != b.v; }

 private:
  static constexpr std::pair<int, int> extgcd(int a, int b) {
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

  using mint = modular<998244353>;

  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), ia(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
      ia[a[i]] = i;
    }
    vector p(n, -1);
    vector<int> pos(k);
    for (int i = 0; i < k; ++i) {
      int b;
      cin >> b;
      --b;
      p[ia[b]] = i;
      pos[i] = ia[b];
    }
    mint ans = 1;
    for (int e : pos) {
      int cur = 0;
      cur += e and p[e - 1] < p[e];
      cur += e + 1 < n and p[e + 1] < p[e];
      ans *= cur;
    }
    cout << ans << '\n';
  }
}