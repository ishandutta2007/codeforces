#include <bits/stdc++.h>

template <class T>
class Combination {
 public:
  static void clear() { fact_ = inv_fact_ = {1}; }
  static T fact(int n) {
    assert(n >= 0);
    while (int(std::size(fact_)) <= n)
      fact_.push_back(fact_.back() * T(std::size(fact_)));
    return fact_[n];
  }
  static T inv_fact(int n) {
    assert(n >= 0);
    while (int(std::size(inv_fact_)) <= n)
      inv_fact_.push_back(inv_fact_.back() / T(std::size(inv_fact_)));
    return inv_fact_[n];
  }
  static T binom(int n, int k) {
    if (k < 0 or (n >= 0 and k > n)) return 0;
    if (int m = -n + k - 1; n < 0) return k & 1 ? -binom(m, k) : binom(m, k);
    return fact(n) * inv_fact(k) * inv_fact(n - k);
  }
  static T homo(int n, int k) {
    if (k < 0 or (-n >= 0 and k > -n)) return 0;
    return k & 1 ? -binom(-n, k) : binom(-n, k);
  }

 private:
  static inline std::vector<T> fact_{1}, inv_fact_{1};

  Combination();
};

template <class Mint>
class DivMint {
 public:
  static void init(int n) {
    assert(1 <= n), assert(n < Mint::modulus());
    inv_.resize(n + 1);
    inv_[1] = 1;
    for (int i = 2; i <= n;) {
      auto q = Mint::modulus() / i, j = std::min<int>(Mint::modulus() / q, n);
      for (; i <= j; ++i) inv_[i] = -q * inv_[Mint::modulus() - q * i];
    }
  }
  static Mint& div_assign(Mint& a, decltype(Mint::modulus()) v) {
    assert(v);
    while (v >= int(std::size(inv_)))
      a *= -(Mint::modulus() / std::exchange(v, Mint::modulus() % v));
    return a *= inv_[v];
  }

 private:
  static inline std::vector<Mint> inv_;

  DivMint();
};

template <uint32_t Modulus>
class ModularInt {
  using M = ModularInt;

 public:
  static_assert(int(Modulus) >= 1, "Modulus must be in the range [1, 2^31)");
  static constexpr int modulus() { return Modulus; }
  static M raw(uint32_t v) { return *reinterpret_cast<M*>(&v); }

  ModularInt() : v_(0) {}
  ModularInt(int64_t v) : v_((v %= Modulus) < 0 ? v + Modulus : v) {}

  template <class T>
  explicit operator T() const {
    return v_;
  }
  M& operator++() { return v_ = ++v_ == Modulus ? 0 : v_, *this; }
  M& operator--() { return --(v_ ? v_ : v_ = Modulus), *this; }
  M& operator*=(M o) { return v_ = uint64_t(v_) * o.v_ % Modulus, *this; }
  M& operator/=(M o) {
    auto [inv, gcd] = extgcd(o.v_, Modulus);
    assert(gcd == 1);
    return *this *= inv;
  }
  M& operator+=(M o) {
    return v_ = int(v_ += o.v_ - Modulus) < 0 ? v_ + Modulus : v_, *this;
  }
  M& operator-=(M o) {
    return v_ = int(v_ -= o.v_) < 0 ? v_ + Modulus : v_, *this;
  }

  friend M operator++(M& a, int) { return std::exchange(a, ++M(a)); }
  friend M operator--(M& a, int) { return std::exchange(a, --M(a)); }
  friend M operator+(M a) { return a; }
  friend M operator-(M a) { return a.v_ = a.v_ ? Modulus - a.v_ : 0, a; }
  friend M operator*(M a, M b) { return a *= b; }
  friend M operator/(M a, M b) { return a /= b; }
  friend M operator+(M a, M b) { return a += b; }
  friend M operator-(M a, M b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, M& x) {
    int64_t v;
    return is >> v, x = v, is;
  }
  friend std::ostream& operator<<(std::ostream& os, M x) { return os << x.v_; }
  friend bool operator==(M a, M b) { return a.v_ == b.v_; }
  friend bool operator!=(M a, M b) { return a.v_ != b.v_; }

 private:
  static std::pair<int, int> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
    return {x[0], a};
  }

  uint32_t v_;
};

#pragma region my_template

struct Rep {
  struct I {
    int i;
    void operator++() { ++i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i < *o; }
  };
  const int l_, r_;
  Rep(int l, int r) : l_(l), r_(r) {}
  Rep(int n) : Rep(0, n) {}
  I begin() const { return {l_}; }
  I end() const { return {r_}; }
};
struct Per {
  struct I {
    int i;
    void operator++() { --i; }
    int operator*() const { return i; }
    bool operator!=(I o) const { return i > *o; }
  };
  const int l_, r_;
  Per(int l, int r) : l_(l), r_(r) {}
  Per(int n) : Per(0, n) {}
  I begin() const { return {r_ - 1}; }
  I end() const { return {l_ - 1}; }
};

template <class F>
struct Fix : private F {
  Fix(F f) : F(f) {}
  template <class... Args>
  decltype(auto) operator()(Args&&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <class T = int>
T scan() {
  T res;
  std::cin >> res;
  return res;
}

template <class T, class U = T>
bool chmin(T& a, U&& b) {
  return b < a ? a = std::forward<U>(b), true : false;
}
template <class T, class U = T>
bool chmax(T& a, U&& b) {
  return a < b ? a = std::forward<U>(b), true : false;
}

#ifndef LOCAL
#define DUMP(...) void(0)
template <int OnlineJudge, int Local>
constexpr int OjLocal = OnlineJudge;
#endif

using namespace std;

#define ALL(c) begin(c), end(c)

#pragma endregion

using Mint = ModularInt<int(1e9) + 7>;
using C = Combination<Mint>;

template <>
Mint& Mint::operator/=(Mint o) {
  if (static bool first = true; first)
    first = false, DivMint<Mint>::init(1 << 8);
  return DivMint<Mint>::div_assign(*this, o.v_);
}

Mint binom_naive(int n, int k) {
  Mint res = 1;
  for (int i : Rep(k)) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int k = scan();

  vector pre(2 * k + 1, vector<Mint>(2 * k + 1));
  for (int i : Rep(2 * k + 1))
    for (int j : Rep(2 * k + 1)) pre[i][j] = binom_naive(n - i, j);

  vector p(k + 2, vector<Mint>(k + 1));
  for (int i : Rep(1, k + 2)) {
    p[i][0] = 1;
    p[i][1] = 1 / Mint(i);
    for (int j : Rep(2, k + 1)) p[i][j] = p[i][j - 1] * p[i][1];
  }

  vector f(k + 1, vector<Mint>(k + 1));
  f[0][0] = 1;
  for (int len : Rep(2, k + 2))
    for (int i : Per(k + 1))
      for (int j : Per(k + 1)) {
        if (f[i][j] == 0) continue;
        for (int x = 1; max(i + x, j + x * (len - 1)) <= k; ++x) {
          auto c = pre[i + j][len * x];
          c *= C::fact(len * x);
          c *= C::inv_fact(x);
          c *= p[len][x];
          f[i + x][j + x * (len - 1)] += f[i][j] * c;
        }
      }

  for (int j : Rep(1, k + 1)) {
    Mint ans;
    for (int i = j; i >= 0; i -= 2)
      for (auto&& e : f) ans += e[i];
    cout << ans << " \n"[j == k];
  }
}