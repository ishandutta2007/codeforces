#include <bits/stdc++.h>

template <class T, class Int> T power(T a, Int n, T e = 1) {
  __glibcxx_assert(n >= 0);
  if (n == 0) return e;
  for (; ~n & 1; n >>= 1) a *= a;
  T res = a;
  while (n >>= 1) {
    a *= a;
    if (n & 1) res *= a;
  }
  return res;
}

template <class T> class NumberBase {
 public:
  T& operator++() { return self() += T(1); }
  T& operator--() { return self() -= T(1); }
  T operator++(int) { return std::exchange(self(), ++self()); }
  T operator--(int) { return std::exchange(self(), --self()); }
  T operator+() const { return self(); }
  T operator-() const { return T{} - self(); }
  bool operator!() const { return self() == T{}; }
  explicit operator bool() const { return !!self(); }
  friend T operator+(const T& a, const T& b) { return T(a) += b; }
  friend T operator-(const T& a, const T& b) { return T(a) -= b; }
  friend T operator*(const T& a, const T& b) { return T(a) *= b; }
  friend T operator/(const T& a, const T& b) { return T(a) /= b; }
  friend bool operator>(const T& a, const T& b) { return b < a; }
  friend bool operator<=(const T& a, const T& b) { return !(a > b); }
  friend bool operator>=(const T& a, const T& b) { return !(a < b); }
  friend bool operator!=(const T& a, const T& b) { return !(a == b); }

 private:
  T& self() { return *static_cast<T*>(this); }
  const T& self() const { return *static_cast<const T*>(this); }
};

template <auto P> struct FpStaticPolicy {
  using U = std::make_unsigned_t<decltype(P)>;
  using D = std::conditional_t<std::is_same_v<U, uint32_t>, uint64_t, __uint128_t>;
  static_assert(2 <= P && P <= U(-1) / 4);
  static constexpr U p = P;
  static constexpr U inv_p = [] {
    U res = p;
    for (int _ = 5; _--;) res *= 2 - p * res;
    return p == 2 ? U(-1) / 2 + 1 : res;
  }();
  static constexpr U r2 = p == 2 ? 1 : -D(p) % p;
};
template <class T, int Id> struct FpDynamicPolicy {
  using U = std::make_unsigned_t<T>;
  using D = std::conditional_t<std::is_same_v<U, uint32_t>, uint64_t, __uint128_t>;
  static inline U p, inv_p, r2;
};
template <class Policy = FpStaticPolicy<998244353>> class Fp : public NumberBase<Fp<Policy>> {
  using U = typename Policy::U;
  using D = typename Policy::D;
  static_assert(std::is_same_v<U, uint32_t> || std::is_same_v<U, uint64_t>);

 public:
  using T = std::make_signed_t<U>;
  static inline std::vector<Fp> fact, ifact, inv;
  static constexpr T mod() { return Policy::p; }
  static void mod(T mod) {
    __glibcxx_assert(2 <= mod && mod <= T(U(-1) / 4));
    fact.clear(), ifact.clear(), inv.clear();
    Policy::p = mod, Policy::inv_p = Policy::p, Policy::r2 = -D(Policy::p) % Policy::p;
    for (int _ = 5; _--;) Policy::inv_p *= 2 - Policy::p * Policy::inv_p;
    if (Policy::p == 2) Policy::inv_p = U(-1) / 2 + 1, Policy::r2 = 1;
  }
  static void reserve(T n) {
    __glibcxx_assert(0 <= n && n < mod());
    fact.resize(n + 1), ifact.resize(n + 1), inv.resize(n + 1);
    fact[0] = 1;
    for (T i = 1; i <= n; ++i) fact[i] = i * fact[i - 1];
    ifact[n] = power(fact[n], Policy::p - 2);
    for (T i = n; i; --i) ifact[i - 1] = ifact[i] * i, inv[i] = fact[i - 1] * ifact[i];
  }
  static Fp binom(T n, T k) {
    if (n >= 0) return 0 <= k && k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0;
    if (k >= 0) return k & 1 ? -binom(k + ~n, k) : binom(k + ~n, k);
    return (n ^ k) & 1 ? -binom(~k, ~n) : binom(~k, ~n);
  }
  Fp() : v(0) {}
  template <class Int, std::enable_if_t<std::is_integral_v<Int> && std::is_signed_v<Int>>* = nullptr> Fp(Int x) {
    v = -mod() <= x && x < mod() ? x : x % mod();
    v = reduce(D(v + Policy::p) * Policy::r2);
  }
  template <class Int, std::enable_if_t<std::is_integral_v<Int> && std::is_unsigned_v<Int>>* = nullptr> Fp(Int x) {
    v = x < 2 * Policy::p ? x : x % Policy::p;
    v = reduce(D(v) * Policy::r2);
  }
  T val() const {
    T res = reduce(v) - Policy::p;
    return res < 0 ? res + Policy::p : res;
  }
  Fp& operator+=(const Fp& o) {
    v = T(v += o.v - 2 * Policy::p) < 0 ? v + 2 * Policy::p : v;
    return *this;
  }
  Fp& operator-=(const Fp& o) {
    v = T(v -= o.v) < 0 ? v + 2 * Policy::p : v;
    return *this;
  }
  Fp& operator*=(const Fp& o) {
    v = reduce(D(v) * o.v);
    return *this;
  }
  Fp& operator/=(const Fp& o) {
    __glibcxx_assert(o);
    if (o.val() < T(std::size(inv))) return *this *= inv[o.val()];
    if ((-o).val() < T(std::size(inv))) return *this *= -inv[(-o).val()];
    return *this *= power(o, Policy::p - 2);
  }
  friend bool operator==(const Fp& a, const Fp& b) {
    return a.v == b.v || a.v + Policy::p == b.v || a.v == b.v + Policy::p;
  }
  friend std::ostream& operator<<(std::ostream& os, const Fp& a) { return os << a.val(); }

 private:
  static U reduce(D x) { return (x + D(U(x) * -Policy::inv_p) * Policy::p) >> std::numeric_limits<U>::digits; }
  U v;
};

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  Fp<>::reserve(2e5);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos{-1};
    for (int i = 0; i < n; ++i)
      if (s[i] == '0') pos.push_back(i);
    pos.push_back(n);
    array<int, 2> cnt{};
    for (int z = 1; z < int(size(pos)); ++z) ++cnt[(pos[z] - pos[z - 1] - 1) & 1];
    int m = count(begin(s), end(s), '1') - cnt[1];
    assert(~m & 1);
    m /= 2;
    int k = size(pos) - 1;
    cout << Fp<>::binom(m + k - 1, k - 1) << '\n';
  }
}