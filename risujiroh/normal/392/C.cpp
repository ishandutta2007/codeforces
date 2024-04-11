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

template <class T, class N, class Op>
T power(T a, N n, T init, Op op) {
  static_assert(std::is_integral_v<N>);
  assert(n >= 0);
  if (n & 1) init = op(init, a);
  while (n >>= 1) {
    a = op(a, a);
    if (n & 1) init = op(init, a);
  }
  return init;
}
template <class T, class N, class Op>
T power_(const T& a, N n, Op op) {
  static_assert(std::is_integral_v<N>);
  assert(n >= 1);
  return power(a, n - 1, a, op);
}

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

using Mint = ModularInt<int(1e9) + 7>;

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

template <class T>
vector<T> operator-(vector<T> a) {
  for (auto&& e : a) e = -e;
  return a;
}
template <class T>
vector<T>& operator+=(vector<T>& a, const vector<T>& b) {
  a.resize(max(size(a), size(b)));
  for (int i = 0; i < (int)size(b); ++i) a[i] += b[i];
  return a;
}
template <class T>
vector<T> operator+(vector<T> a, const vector<T>& b) {
  return a += b;
}
template <class T>
vector<T>& operator-=(vector<T>& a, const vector<T>& b) {
  a.resize(max(size(a), size(b)));
  for (int i = 0; i < (int)size(b); ++i) a[i] -= b[i];
  return a;
}
template <class T>
vector<T> operator-(vector<T> a, const vector<T>& b) {
  return a -= b;
}
template <class T>
vector<T>& operator<<=(vector<T>& a, size_t n) {
  return a.insert(begin(a), n, 0), a;
}
template <class T>
vector<T> operator<<(vector<T> a, size_t n) {
  return a <<= n;
}
template <class T>
vector<T>& operator>>=(vector<T>& a, size_t n) {
  return a.erase(begin(a), begin(a) + min(size(a), n)), a;
}
template <class T>
vector<T> operator>>(vector<T> a, size_t n) {
  return a >>= n;
}
template <class T>
vector<T> operator*(const vector<T>& a, const vector<T>& b) {
  if (empty(a) or empty(b)) return {};
  vector<T> res(size(a) + size(b) - 1);
  for (int i = 0; i < (int)size(a); ++i)
    for (int j = 0; j < (int)size(b); ++j) res[i + j] += a[i] * b[j];
  return res;
}
template <class T>
vector<T>& operator*=(vector<T>& a, const vector<T>& b) {
  return a = a * b;
}
template <class T>
vector<T> inverse(const vector<T>& a) {
  assert(not empty(a) and not(a[0] == 0));
  vector<T> b{1 / a[0]};
  while (size(b) < size(a)) {
    vector<T> x(begin(a), begin(a) + min(size(a), 2 * size(b)));
    x *= b * b;
    b.resize(2 * size(b));
    for (auto i = size(b) / 2; i < min(size(x), size(b)); ++i) b[i] = -x[i];
  }
  return {begin(b), begin(b) + size(a)};
}
template <class T>
vector<T> operator/(vector<T> a, vector<T> b) {
  if (size(a) < size(b)) return {};
  reverse(begin(a), end(a)), reverse(begin(b), end(b));
  int n = size(a) - size(b) + 1;
  a.resize(n), b.resize(n);
  a *= inverse(b);
  return {rend(a) - n, rend(a)};
}
template <class T>
vector<T>& operator/=(vector<T>& a, const vector<T>& b) {
  return a = a / b;
}
template <class T>
vector<T> operator%(vector<T> a, const vector<T>& b) {
  if (size(a) < size(b)) return a;
  a -= a / b * b;
  return {begin(a), begin(a) + (size(b) - 1)};
}
template <class T>
vector<T>& operator%=(vector<T>& a, const vector<T>& b) {
  return a = a % b;
}

template <class T>
vector<T> bm(const vector<T>& a) {
  T d = 1;
  vector<T> c{1}, nc{1};
  int n = a.size(), k = 0, m = 1;
  for (int i = 0; i < n; ++i) {
    T nd = inner_product(rbegin(nc), rend(nc), begin(a) + (i - k), (T)0);
    if (nd == 0)
      ++m;
    else if (2 * k <= i) {
      auto t = nc;
      nc -= vector<T>{nd / d} * (c << m);
      c = t, d = nd;
      k = i + 1 - k, m = 1;
    } else {
      nc -= vector<T>{nd / d} * (c << m);
      ++m;
    }
  }
  return {rbegin(nc), rend(nc)};
}
template <class T>
T guess_kth(const vector<T>& a, long long k) {
  auto c = bm(a);
  auto b = power_(vector<T>{0, 1}, k,
                  [&](const auto& l, const auto& r) { return l * r % c; });
  return inner_product(begin(b), end(b), begin(a), (T)0);
}

constexpr int lim = 1000;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto n = scan<int64_t>();
  int k = scan();
  vector<Mint> a(lim + 1), f(lim);
  f[1] = 1, f[2] = 2;
  for (int i : Rep(1, lim)) {
    if (i > 2) f[i] = f[i - 1] + f[i - 2];
    a[i + 1] = a[i] + f[i] * power<Mint>(i, k);
  }
  DUMP(a);
  cout << guess_kth(a, n + 1) << '\n';
}