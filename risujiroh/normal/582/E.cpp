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

template <class F>
struct y_combinator : private F {
  y_combinator(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  using mint = modular<int(1e9) + 7>;

  auto and_conv = [&](auto a, auto b) {
    for (int s : rep(16))
      for (int i : rep(1 << 16))
        if (i >> s & 1) {
          a[i ^ 1 << s] += a[i];
          b[i ^ 1 << s] += b[i];
        }
    for (int i : rep(1 << 16)) a[i] *= b[i];
    for (int s : rep(16))
      for (int i : rep(1 << 16))
        if (i >> s & 1) a[i ^ 1 << s] -= a[i];
    return a;
  };

  auto or_conv = [&](auto a, auto b) {
    for (int s : rep(16))
      for (int i : rep(1 << 16))
        if (i >> s & 1) {
          a[i] += a[i ^ 1 << s];
          b[i] += b[i ^ 1 << s];
        }
    for (int i : rep(1 << 16)) a[i] *= b[i];
    for (int s : rep(16))
      for (int i : rep(1 << 16))
        if (i >> s & 1) a[i] -= a[i ^ 1 << s];
    return a;
  };

  string s;
  cin >> s;
  int n = size(s);

  auto f = y_combinator([&](auto&& self, int l, int r) -> vector<mint> {
    vector<mint> res(1 << 16);
    if (s[l] == '(') {
      int t{}, m = -1;
      for (int i : rep(l, r)) {
        t += s[i] == '(';
        t -= s[i] == ')';
        if (t == 0) {
          m = i + 1;
          break;
        }
      }
      auto a = self(l + 1, m - 1);
      auto b = self(m + 2, r - 1);
      if (s[m] != '|') {
        auto temp = and_conv(a, b);
        for (int i : rep(1 << 16)) res[i] += temp[i];
      }
      if (s[m] != '&') {
        auto temp = or_conv(a, b);
        for (int i : rep(1 << 16)) res[i] += temp[i];
      }
    } else {
      for (int x : rep(4)) {
        if (s[l] == '?' or s[l] == 'A' + x) {
          int id{};
          for (int bt : rep(16)) id |= (bt >> x & 1) << bt;
          ++res[id];
        }
        if (s[l] == '?' or s[l] == 'a' + x) {
          int id{};
          for (int bt : rep(16)) id |= (~bt >> x & 1) << bt;
          ++res[id];
        }
      }
    }
    return res;
  })(0, n);

  int m;
  cin >> m;
  vector ok(1 << 16, true);
  while (m--) {
    array<int, 4> a;
    int val;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> val;
    int bt = a[0] | a[1] << 1 | a[2] << 2 | a[3] << 3;
    for (int id : rep(1 << 16))
      if ((id >> bt & 1) != val) {
        ok[id] = false;
      }
  }

  mint ans;
  for (int id : rep(1 << 16))
    if (ok[id]) ans += f[id];
  cout << ans << '\n';
}