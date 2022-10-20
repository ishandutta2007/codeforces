#include <bits/stdc++.h>

template <class T>
constexpr T power(T a, int64_t n) {
  assert(n >= 0);
  T res = n & 1 ? a : 1;
  while (n >>= 1) {
    a *= a;
    if (n & 1) res *= a;
  }
  return res;
}

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
  D operator+() const { return *this; }
  D operator-() const { return raw(v_ ? modulus_ - v_ : 0); }
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

bool miller_rabin(int64_t n, std::initializer_list<int64_t> bases) {
  using Mint = DynamicModularInt64<__COUNTER__>;
  Mint::modulus(n);
  int tz = __builtin_ctzll(n - 1);
  for (Mint a : bases) {
    if (a == 0) continue;
    a = power(a, n >> tz);
    int i = tz;
    while (a != 1 and a != -1 and i--) a *= a;
    if (a != -1 and i != tz) return false;
  }
  return true;
}

bool is_prime(int64_t n) {
  if (n < 2 or n % 6 % 4 != 1) return n == 2 or n == 3;
  if (n < 291831) return miller_rabin(n, {126401071349994536});
  if (n < 1050535501) return miller_rabin(n, {336781006125, 9639812373923155});
  if (n < 273919523041)
    return miller_rabin(n, {15, 7363882082, 992620450144556});
  if (n < 47636622961201)
    return miller_rabin(n, {2, 2570940, 211991001, 3749873356});
  if (n < 7999252175582851)
    return miller_rabin(n, {2, 4130806001517, 149795463772692060,
                            186635894390467037, 3967304179347715805});
  if (n < 585226005592931977)
    return miller_rabin(
        n, {2, 123635709730000, 9233062284813009, 43835965440333360,
            761179012939631437, 1263739024124850375});
  return miller_rabin(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  vector<int> x, y;
  for (int i : Rep(9)) {
    int p = power(10, i);
    while (not is_prime(p)) ++p;
    x.push_back(p);
    ++p;
    while (not is_prime(p)) ++p;
    y.push_back(p);
  }
  DUMP(x);
  DUMP(y);
  for (int tt = scan(); tt--;) {
    int a = scan() - 1;
    int b = scan() - 1;
    int c = scan() - 1;
    cout << x[a - c] * power(10, c) << ' ' << y[b - c] * power(10, c) << '\n';
  }
}