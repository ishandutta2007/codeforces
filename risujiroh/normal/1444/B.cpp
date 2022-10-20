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

  int n;
  cin >> n;
  vector<int> a(2 * n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));

  mint ans = accumulate(begin(a) + n, end(a), mint(0));
  ans -= accumulate(begin(a), begin(a) + n, mint(0));
  for (int i : rep(1, 2 * n + 1)) ans *= i;
  for (int i : rep(1, n + 1)) ans /= i, ans /= i;
  cout << ans << '\n';
}