#include <bits/stdc++.h>

template <class T>
constexpr T power(T a, int64_t n) {
  assert(n >= 0);
  T res = n & 1 ? a : T{1};
  while (n >>= 1) {
    a *= a;
    if (n & 1) res *= a;
  }
  return res;
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

class Dsu {
 public:
  Dsu() {}
  explicit Dsu(int n) : dat(n, -1), num_components_(n) {}

  int size() const { return std::size(dat); }
  int root(int v) {
    assert(0 <= v), assert(v < size());
    return dat[v] < 0 ? v : dat[v] = root(dat[v]);
  }
  std::pair<int, int> unite(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    u = root(u), v = root(v);
    if (u == v) return {u, -1};
    --num_components_;
    if (-dat[u] < -dat[v]) std::swap(u, v);
    dat[u] += dat[v];
    dat[v] = u;
    return {u, v};
  }
  bool same(int u, int v) {
    assert(0 <= u), assert(u < size());
    assert(0 <= v), assert(v < size());
    return root(u) == root(v);
  }
  int size(int v) {
    assert(0 <= v), assert(v < size());
    return -dat[root(v)];
  }
  int num_components() const { return num_components_; }

 private:
  std::vector<int> dat;
  int num_components_;
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
using Dint = DynamicModularInt64<__COUNTER__>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  Dint::modulus(9223372036854775783);
  vector<Dint> x(n), y(n);
  for (int i : Rep(n)) {
    x[i] = scan();
    x[i] /= scan();
    y[i] = scan();
    y[i] /= scan();
    auto t = x[i] * x[i] + y[i] * y[i];
    x[i] /= t;
    y[i] /= t;
  }

  map<pair<int64_t, int64_t>, vector<pair<Dint, Dint>>> mp;
  for (int i : Rep(n))
    for (int j : Rep(i + 1, n))
      mp[{int64_t(x[i] + x[j]), int64_t(y[i] + y[j])}].emplace_back(
          x[j] - x[i], y[j] - y[i]);

  Mint ans;
  for (auto&& [c, v] : mp) {
    if (size(v) < 2) continue;
    Dsu d(size(v));
    for (int i : Rep(size(v)))
      for (int j : Rep(i + 1, size(v)))
        if (v[i].first * v[j].second == v[i].second * v[j].first) d.unite(i, j);
    Mint cur = 1;
    for (int i : Rep(size(v)))
      if (d.root(i) == i) cur *= d.size(i) + 1;
    --cur;
    cur -= size(v);
    DUMP(cur);
    ans += cur;
  }
  cout << ans << '\n';
}