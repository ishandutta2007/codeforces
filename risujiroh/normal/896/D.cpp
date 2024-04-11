#include <bits/stdc++.h>

template <int Id>
class DynamicModularInt64 {
  using D = DynamicModularInt64;

 public:
  static int64_t modulus() { return modulus_; }
  static void modulus(int64_t modulus) {
    assert(modulus >= 1);
    modulus_ = modulus;
  }
  static D raw(uint64_t v) { return *reinterpret_cast<D*>(&v); }

  DynamicModularInt64() : v_(0) {}
  DynamicModularInt64(int64_t v)
      : v_((v %= modulus()) < 0 ? v + modulus() : v) {}

  template <class T>
  explicit operator T() const {
    return v_;
  }
  D& operator++() { return v_ = ++v_ == modulus_ ? 0 : v_, *this; }
  D& operator--() { return --(v_ ? v_ : v_ = modulus_), *this; }
  D& operator*=(D o) {
    v_ = v_ * o.v_ - uint64_t((long double)v_ * o.v_ / modulus_) * modulus_;
    v_ = int64_t(v_) < 0 ? v_ + modulus_ : v_;
    v_ = v_ >= modulus_ ? v_ - modulus_ : v_;
    return *this;
  }
  D& operator/=(D o) {
    auto [inv, gcd] = extgcd(o.v_, modulus_);
    assert(gcd == 1);
    return *this *= inv;
  }
  D& operator+=(D o) {
    return v_ = int64_t(v_ += o.v_ - modulus_) < 0 ? v_ + modulus_ : v_, *this;
  }
  D& operator-=(D o) {
    return v_ = int64_t(v_ -= o.v_) < 0 ? v_ + modulus_ : v_, *this;
  }

  friend D operator++(D& a, int) { return std::exchange(a, ++D(a)); }
  friend D operator--(D& a, int) { return std::exchange(a, --D(a)); }
  friend D operator+(D a) { return a; }
  friend D operator-(D a) { return a.v_ = a.v_ ? modulus_ - a.v_ : 0, a; }
  friend D operator*(D a, D b) { return a *= b; }
  friend D operator/(D a, D b) { return a /= b; }
  friend D operator+(D a, D b) { return a += b; }
  friend D operator-(D a, D b) { return a -= b; }
  friend std::istream& operator>>(std::istream& is, D& x) {
    int64_t v;
    return is >> v, x = v, is;
  }
  friend std::ostream& operator<<(std::ostream& os, D x) { return os << x.v_; }
  friend bool operator==(D a, D b) { return a.v_ == b.v_; }
  friend bool operator!=(D a, D b) { return a.v_ != b.v_; }

 private:
  static std::pair<int64_t, int64_t> extgcd(int64_t a, int64_t b) {
    std::array<int64_t, 2> x{1, 0};
    while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
    return {x[0], a};
  }

  static inline uint64_t modulus_ = std::numeric_limits<int64_t>::max();

  uint64_t v_;
};

template <class T>
struct Combination {
  std::vector<T> fact, ifact;

  Combination() {}
  explicit Combination(int n) : fact(n + 1), ifact(n + 1) {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; ++i)
      fact[i] = fact[i - 1] * T(i), ifact[i] = ifact[i - 1] / T(i);
  }

  T binom(int n, int k) const {
    if (k < 0 or (n >= 0 and k > n)) return 0;
    if (int m = -n + k - 1; n < 0) return k & 1 ? -binom(m, k) : binom(m, k);
    return fact[n] * ifact[k] * ifact[n - k];
  }
  T homo(int n, int k) const {
    if (k < 0 or (-n >= 0 and k > -n)) return 0;
    return k & 1 ? -binom(-n, k) : binom(-n, k);
  }
};

std::vector<int> factor(int n) {
  std::vector<int> res;
  for (int p = 2; p * p <= n; ++p)
    for (; n % p == 0; n /= p) res.push_back(p);
  if (n > 1) res.push_back(n);
  return res;
}

namespace crt {

using Mint = DynamicModularInt64<__COUNTER__>;

struct S {
  static inline int64_t p;

  Mint r;
  int64_t e;

  S() : r(0), e(0) {}
  S(int64_t v) : e(0) {
    for (; v and v % p == 0; v /= p) ++e;
    r = v;
  }

  S& operator*=(S o) { return r *= o.r, e += o.e, *this; }
  S& operator/=(S o) { return r /= o.r, e -= o.e, *this; }

  friend S operator-(S a) { return a.r = -a.r, a; }
  friend S operator*(S a, S b) { return a *= b; }
  friend S operator/(S a, S b) { return a /= b; }
};

struct Info {
  std::vector<int64_t> pw;
  int64_t coeff;
  Combination<S> comb;
};

int64_t m;
std::vector<Info> v;

void init(int64_t modulus, int n) {
  v.clear();
  for (int64_t p : factor(m = modulus))
    if (std::empty(v) or v.back().pw[1] != p)
      v.push_back({{1, p}, 0, {}});
    else
      v.back().pw.push_back(v.back().pw.back() * p);
  for (auto&& [pw, coeff, comb] : v) {
    Mint::modulus(pw.back()), S::p = pw[1];
    coeff = int64_t(1 / Mint(m / pw.back())) * (m / pw.back());
    comb = Combination<S>(n);
  }
}

template <class F>
int64_t solve(F f) {
  Mint res;
  for (auto&& e : v) {
    Mint::modulus(e.pw.back()), S::p = e.pw[1];
    auto t = f(e);
    if (t.e >= int(std::size(e.pw)) - 1) continue;
    Mint::modulus(m);
    res += Mint::raw(e.coeff) * int64_t(t.r) * e.pw[t.e];
  }
  return int64_t(res);
}

int64_t binom(int n, int k) {
  return solve([&](const Info& e) { return e.comb.binom(n, k); });
}

}  // namespace crt

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

using Mint = DynamicModularInt64<__COUNTER__>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  Mint::modulus(scan());
  crt::init(Mint::modulus(), n);
  int l = scan();
  int r = scan();

  Mint ans;
  for (int k : Rep(n + 1)) {
    Mint cur;
    cur += crt::binom(n - k, k + l);
    cur += crt::binom(n - k, k + l + 1);
    cur -= crt::binom(n - k, k + r + 1);
    cur -= crt::binom(n - k, k + r + 2);
    cur *= crt::binom(n, k);
    ans += cur;
  }
  cout << ans << '\n';
}