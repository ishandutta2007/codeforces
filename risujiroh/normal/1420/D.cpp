#include <bits/extc++.h>

template <class T>
struct fenwick {
  fenwick() {}
  template <class Generator>
  fenwick(int n, Generator gen) : tree(n) {
    for (int i = 0; i < n; ++i) tree[i] = gen(i);
    for (int i = 0; i < n; ++i)
      if (int j = i | (i + 1); j < n) tree[j] += tree[i];
  }

  int size() const { return std::size(tree); }
  void add(int i, T a) {
    assert(0 <= i), assert(i < size());
    for (; i < size(); i |= i + 1) tree[i] += a;
  }
  T sum(int i) const {
    assert(0 <= i), assert(i <= size());
    T res{};
    for (; i; i &= i - 1) res += tree[i - 1];
    return res;
  }
  T sum(int l, int r) const {
    assert(0 <= l), assert(l <= r), assert(r <= size());
    return sum(r) - sum(l);
  }
  int kth(T k) const {
    static_assert(std::is_integral_v<T> and not std::is_same_v<T, bool>);
    assert(k >= 0);
    int i = 0;
    for (int w = 1 << std::__lg(size()); w; w >>= 1)
      if (i + w <= size() and tree[i + w - 1] <= k) k -= tree[(i += w) - 1];
    return i;
  }

 private:
  std::vector<T> tree;
};

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
  cin >> n >> k;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    --l[i];
  }
  vector<int> order(n);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int i, int j) { return r[i] > r[j]; });
  {
    auto v = l;
    v.insert(end(v), begin(r), end(r));
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    for (auto&& e : l) e = lower_bound(begin(v), end(v), e) - begin(v);
    for (auto&& e : r) e = lower_bound(begin(v), end(v), e) - begin(v);
  }

  using mint = modular<998244353>;

  vector<mint> fact(n + 1), inv_fact(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = 1 / fact[n];
  for (int i = n; i--;) inv_fact[i] = inv_fact[i + 1] * (i + 1);
  auto binom = [&](int a, int b) -> mint {
    if (b < 0 or a < b) return 0;
    assert(0 <= b), assert(b <= a);
    return fact[a] * inv_fact[b] * inv_fact[a - b];
  };

  mint ans;
  fenwick<int> ft(2 * n, [](int) { return 0; });
  for (int i : order) {
    ans += binom(ft.sum(r[i]), k - 1);
    ft.add(l[i], 1);
  }
  cout << ans << '\n';
}