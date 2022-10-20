// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt")
// #define NDEBUG

#include <bits/extc++.h>
#include <x86intrin.h>

struct rep {
  struct iterator {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    friend bool operator!=(iterator a, iterator b) { return *a != *b; }
  };
  const int l, r;
  rep(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  rep(int n) : rep(0, n) {}
  iterator begin() const { return {l}; }
  iterator end() const { return {r}; }
};
struct per {
  struct iterator {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    friend bool operator!=(iterator a, iterator b) { return *a != *b; }
  };
  const int l, r;
  per(int _l, int _r) : l(std::min(_l, _r)), r(_r) {}
  per(int n) : per(0, n) {}
  iterator begin() const { return {r - 1}; }
  iterator end() const { return {l - 1}; }
};
template <class C>
int sz(C&& c) {
  using std::size;
  return size(std::forward<C>(c));
}
template <class T, class U>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

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

template <class T, class U, class BinaryOperation = std::multiplies<>>
constexpr T power(T a, U n, T init = 1,
                  BinaryOperation binary_op = BinaryOperation{}) {
  static_assert(std::is_integral_v<U> and not std::is_same_v<U, bool>);
  assert(n >= 0);
  while (n) {
    if (n & 1) init = binary_op(init, a);
    if (n >>= 1) a = binary_op(a, a);
  }
  return init;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  const string t = "abc?";
  vector<array<int, 4>> suff(n + 1);
  for (int i : per(n)) {
    suff[i] = suff[i + 1];
    ++suff[i][t.find(s[i])];
  }

  auto f = [&](int l, int r, char c) -> int {
    int i = t.find(c);
    return suff[l][i] - suff[r][i];
  };

  using mint = modular<power(10, 9) + 7>;
  int k = suff[0][3];
  vector<mint> p3(k + 1);
  for (int i : rep(k + 1)) p3[i] = i ? 3 * p3[i - 1] : 1;

  mint ans;
  for (int i : rep(n)) {
    if (s[i] == 'a' or s[i] == 'c') continue;
    k -= s[i] == '?';
    ans += p3[k] * f(0, i, 'a') * f(i + 1, n, 'c');
    if (k) {
      ans += p3[k - 1] * f(0, i, 'a') * f(i + 1, n, '?');
      ans += p3[k - 1] * f(0, i, '?') * f(i + 1, n, 'c');
    }
    if (k >= 2) {
      ans += p3[k - 2] * f(0, i, '?') * f(i + 1, n, '?');
    }
    k += s[i] == '?';
  }
  cout << ans << '\n';
}