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
  int n, m;
  cin >> n >> m;
  vector g(2, vector<vector<int>>(n));
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[0][u].push_back(v);
    g[1][v].push_back(u);
  }

  using mint = modular<998244353>;

  constexpr auto inf = numeric_limits<int64_t>::max() / 2;

  {
    vector d(2 * n, inf);
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>>
        pq;
    pq.emplace(d[0] = 0, 0);
    while (not empty(pq)) {
      auto [dv, v] = pq.top();
      pq.pop();
      if (dv != d[v]) continue;

      auto f = [&](int u, int cost) {
        if (dv + cost < d[u]) pq.emplace(d[u] = dv + cost, u);
      };

      for (int u : g[v & 1][v >> 1]) f(2 * u + (v & 1), 1);
      f(v ^ 1, 1 << 20);
    }

    auto dn = min(d[2 * (n - 1)], d[2 * (n - 1) + 1]);
    if ((dn >> 20) >= 20) {
      cout << power<mint>(2, dn >> 20) - 1 + (dn & ~-(1 << 20)) << '\n';
      exit(0);
    }
  }

  vector d(20 * n, inf);
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  pq.emplace(d[0] = 0, 0);
  while (not empty(pq)) {
    auto [dv, v] = pq.top();
    pq.pop();
    if (dv != d[v]) continue;

    auto f = [&](int u, int cost) {
      if (dv + cost < d[u]) pq.emplace(d[u] = dv + cost, u);
    };

    for (int u : g[v % 20 & 1][v / 20]) f(20 * u + v % 20, 1);
    if (v % 20 < 19) f(v + 1, 1 << v % 20);
  }

  auto ans = inf;
  for (int c = 0; c < 20; ++c) ans = min(ans, d[20 * (n - 1) + c]);
  cout << mint(ans) << '\n';
}