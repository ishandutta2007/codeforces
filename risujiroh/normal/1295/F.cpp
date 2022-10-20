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
  static_assert(int(Modulus) > 0, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static modular raw(uint32_t _v) {
    modular res;
    res.v = _v;
    return res;
  }

  modular() : v(0) {}
  modular(int64_t x) : v(x % Modulus) {
    if (int(v) < 0) v += Modulus;
  }

  template <class T>
  explicit operator T() const {
    return v;
  }
  modular& operator++() {
    ++v;
    if (v == Modulus) v = 0;
    return *this;
  }
  modular& operator--() {
    if (v == 0) v = Modulus;
    --v;
    return *this;
  }
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

template <uint32_t Modulus>
void ntt(std::vector<modular<Modulus>>& a, bool inverse) {
  using mint = modular<Modulus>;
  int n = size(a);
  assert((n & (n - 1)) == 0);
  if (n < 2) return;
  assert((Modulus - 1) % n == 0);
  static std::vector<mint> w{1}, iw{1};
  for (int m = size(w); m < n / 2; m *= 2) {
    static mint root = 2;
    while (power(root, (Modulus - 1) / 2) == 1) ++root;
    mint dw = power(root, (Modulus - 1) / (4 * m)), idw = 1 / dw;
    w.resize(2 * m), iw.resize(2 * m);
    for (int i = 0; i < m; ++i) w[m + i] = w[i] * dw, iw[m + i] = iw[i] * idw;
  }
  if (not inverse) {
    for (int m = n; m >>= 1;) {
      for (int l = 0, k = 0; l < n; l += 2 * m, ++k) {
        for (int i = l, j = l + m; i < l + m; ++i, ++j) {
          uint32_t x = a[i], y = a[j] * w[k];
          if (x >= Modulus) x -= Modulus;
          a[i] = mint::raw(x + y);
          a[j] = mint::raw(x + (Modulus - y));
        }
      }
    }
    for (auto&& e : a)
      if (uint32_t(e) >= Modulus) e = mint::raw(uint32_t(e) - Modulus);
  } else {
    for (int m = 1; m < n; m *= 2) {
      for (int l = 0, k = 0; l < n; l += 2 * m, ++k) {
        for (int i = l, j = l + m; i < l + m; ++i, ++j) {
          uint32_t x = a[i], y = a[j];
          a[i] += a[j];
          a[j] = mint::raw(x + (Modulus - y));
          a[j] *= iw[k];
        }
      }
    }
    mint inv = 1 / mint(n);
    for (auto&& e : a) e *= inv;
  }
}
template <uint32_t Modulus>
std::vector<modular<Modulus>> operator*(std::vector<modular<Modulus>> a,
                                        std::vector<modular<Modulus>> b) {
  if (empty(a) or empty(b)) return {};
  int n = size(a), m = size(b), sz = 1 << std::__lg(2 * (n + m - 1) - 1);
  if (std::min(n, m) < 30) {
    std::vector<int64_t> res(n + m - 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) res[i + j] += uint32_t(a[i] * b[j]);
    return {begin(res), end(res)};
  }
  bool eq = a == b;
  a.resize(sz), ntt(a, false);
  if (eq)
    b = a;
  else
    b.resize(sz), ntt(b, false);
  for (int i = 0; i < sz; ++i) a[i] *= b[i];
  ntt(a, true), a.resize(n + m - 1);
  return a;
}

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i : per(n)) {
    cin >> l[i] >> r[i];
    ++r[i];
  }
  for (int i : rep(n)) {
    l[i] += i;
    r[i] += i;
  }
  auto v = l;
  v.insert(end(v), begin(r), end(r));
  sort(begin(v), end(v));
  v.erase(unique(begin(v), end(v)), end(v));

  using mint = modular<998244353>;

  vector<mint> dp(n + 1);
  dp[0] = 1;

  for (int k : rep(1, size(v))) {
    auto in = [&](int i) -> bool { return l[i] <= v[k - 1] and v[k] <= r[i]; };

    vector<mint> c(n + 1);
    for (int i : rep(n + 1))
      c[i] = i ? c[i - 1] * (v[k] - v[k - 1] - i + 1) / i : 1;

    int a = 0;
    for (int b : rep(n + 1))
      if (b == n or not in(b)) {
        ++b;
        auto temp = vector(begin(dp) + a, begin(dp) + b) *
                    vector(begin(c), begin(c) + (b - a));
        move(begin(temp), begin(temp) + (b - a), begin(dp) + a);
        a = b;
      }
  }

  mint ans = dp[n];
  for (int i : rep(n)) ans /= r[i] - l[i];
  cout << ans << '\n';
}