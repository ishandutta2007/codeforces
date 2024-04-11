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
  int64_t p;
  int alpha;
  cin >> p >> alpha;
  string s;
  cin >> s;

  vector<int64_t> a(1);
  auto normalize = [&] {
    int i = 0;
    while (i < int(size(a))) {
      int q = a[i] / p;
      a[i] %= p;
      if (q) {
        if (i + 1 >= int(size(a))) a.resize(i + 2);
        a[i + 1] += q;
      }
      ++i;
    }
  };

  for (char c : s) {
    for (auto&& e : a) e *= 10;
    normalize();
    a[0] += c - '0';
    normalize();
  }
  int n = size(a);

  using mint = modular<int(1e9) + 7>;

  auto f = [&](int64_t r) -> mint {
    if (r <= p) return r * (r + 1) / 2;
    r -= p;
    return p * (p + 1) / 2 + p * r - r * (r + 1) / 2;
  };
  auto g = [&](int l, int r, int offset) -> mint {
    l -= offset, r -= offset;
    l = max(l, 0);
    if (l >= r) return 0;
    return f(r) - f(l);
  };

  vector dp(2, vector(2, vector<mint>(n + 1)));
  vector ndp(2, vector(2, vector<mint>(n + 1)));
  dp[0][0][0] = 1;
  for (int i : rep(n)) {
    for (int over : rep(2))
      for (int carry : rep(2))
        fill(begin(ndp[over][carry]), end(ndp[over][carry]), 0);

    vector pos{int64_t{}, a[i], a[i] + 1, p, p + a[i], p + a[i] + 1, 2 * p};
    vector pre(2, vector<mint>(size(pos)));
    for (int carry : rep(2))
      for (int k : rep(1, size(pos)))
        pre[carry][k] = g(pos[k - 1], pos[k], carry);

    for (int over : rep(2))
      for (int carry : rep(2))
        for (int cnt : rep(i + 1))
          if (int(dp[over][carry][cnt])) {
            for (int k : rep(1, size(pos))) {
              int l = pos[k - 1];
              int nover = l % p > a[i] or (l % p == a[i] and over);
              int ncarry = l >= p;
              int ncnt = cnt + (l >= p);
              ndp[nover][ncarry][ncnt] += dp[over][carry][cnt] * pre[carry][k];
            }
          }
    swap(dp, ndp);
  }

  mint ans;
  for (int cnt : rep(alpha, n + 1)) ans += dp[0][0][cnt];
  cout << ans << '\n';
}