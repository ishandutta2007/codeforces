#include <bits/stdc++.h>

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
  M operator+() const { return *this; }
  M operator-() const { return raw(v_ ? Modulus - v_ : 0); }
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
  static std::array<int, 2> extgcd(int a, int b) {
    std::array x{1, 0};
    while (b) std::swap(x[0] -= a / b * x[1], x[1]), std::swap(a %= b, b);
    return {x[0], a};
  }

  uint32_t v_;
};

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

template <class T>
void ntt(std::vector<T>& a, bool inverse) {
  int n = size(a);
  assert((n & (n - 1)) == 0);
  if (n < 2) return;
  assert((T::modulus() - 1) % n == 0);
  static std::vector<T> w{1}, iw{1};
  for (int m = size(w); m < n / 2; m *= 2) {
    static T root = 2;
    while (power(root, (T::modulus() - 1) / 2) == 1) ++root;
    T dw = power(root, (T::modulus() - 1) / (4 * m)), idw = 1 / dw;
    w.resize(2 * m), iw.resize(2 * m);
    for (int i = 0; i < m; ++i) w[m + i] = w[i] * dw, iw[m + i] = iw[i] * idw;
  }
  if (not inverse) {
    for (int m = n; m >>= 1;) {
      for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          T x = a[i], y = a[j] * w[k];
          a[i] = x + y, a[j] = x - y;
        }
      }
    }
  } else {
    for (int m = 1; m < n; m *= 2) {
      for (int s = 0, k = 0; s < n; s += 2 * m, ++k) {
        for (int i = s, j = s + m; i < s + m; ++i, ++j) {
          T x = a[i], y = a[j];
          a[i] = x + y, a[j] = (x - y) * iw[k];
        }
      }
    }
    auto inv = 1 / T(n);
    for (auto&& e : a) e *= inv;
  }
}
template <class T>
std::vector<T> operator*(std::vector<T> a, std::vector<T> b) {
  if (empty(a) or empty(b)) return {};
  int n = size(a), m = size(b), sz = 1 << std::__lg(2 * (n + m - 1) - 1);
  if (std::min(n, m) < 30) {
    std::vector<T> res(n + m - 1);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) res[i + j] += a[i] * b[j];
    return res;
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

using Mint = ModularInt<998244353>;

constexpr int Limit = 1 << 20;

auto fact = [] {
  std::vector<Mint> res(Limit + 1);
  res[0] = 1;
  for (int i = 1; i <= Limit; ++i) res[i] = i * res[i - 1];
  return res;
}();
auto ifact = [] {
  std::vector<Mint> res(Limit + 1);
  res[Limit] = 1 / fact[Limit];
  for (int i = Limit; i--;) res[i] = res[i + 1] * (i + 1);
  return res;
}();
Mint binom(int n, int k) {
  assert(n <= Limit);
  return 0 <= k and k <= n ? fact[n] * ifact[k] * ifact[n - k] : 0;
}
Mint homo(int n, int k) { return n or k ? binom(n + k - 1, k) : 1; }

auto minv = [] {
  std::vector<Mint> res(Limit + 1);
  for (int i = 1; i <= Limit; ++i) res[i] = ifact[i] * fact[i - 1];
  return res;
}();
template <>
Mint& Mint::operator/=(Mint o) {
  assert(o.v_);
  return *this *= o.v_ <= Limit ? minv[o.v_] : extgcd(o.v_, modulus())[0];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int m = scan();
  assert(m == 0);
  auto s = scan<string>();

  int ce = 0, co = 0;
  int we = 0, wo = 0;
  for (int i : Rep(n))
    if (~i & 1) {
      ce += s[i] == '?';
      we += s[i] == 'w';
    } else {
      co += s[i] == '?';
      wo += s[i] == 'w';
    }

  Mint ans;
  if (false)
    for (int i : Rep(ce + 1))
      for (int j : Rep(co + 1))
        if (~(we + wo + i + j) & 1) {
          ans += binom(ce, i) * binom(co, j) * abs(wo + j - we - i) / 2;
        }

  vector<Mint> a(ce + 1), b(co + 1);
  for (int i : Rep(ce + 1)) a[i] = binom(ce, i);
  for (int j : Rep(co + 1)) b[j] = binom(co, j);
  a = a * b;
  Mint sum;
  for (int k : Rep(size(a))) {
    if ((we + wo + k - ce) & 1) continue;
    ans += a[k] * abs(wo - we + k - ce);
    sum += a[k];
  }

  ans /= power<Mint>(2, ce + co);
  cout << ans << '\n';
}