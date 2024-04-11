#include <bits/stdc++.h>

template <class ForwardIterator, class F>
void bitwise_transform(ForwardIterator first, ForwardIterator last, F f) {
  int n = std::distance(first, last);
  assert((n & (n - 1)) == 0);
  for (int step = 1; step < n; step *= 2)
    for (auto i = first; i != last;) {
      auto j = std::next(i, step);
      for (auto end = j; i != end; ++i, ++j) f(*i, *j);
      i = j;
    }
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
  vector<vector<int>> g(n);
  vector<vector<int>> r(n);
  vector<int> deg(n);
  while (m--) {
    int u = scan() - 1;
    int v = scan() - 1;
    g[u].push_back(v);
    r[v].push_back(u);
    ++deg[u];
  }

  vector<int> que;
  for (int v : Rep(n))
    if (deg[v] == 0) que.push_back(v);

  vector<int> a(n);
  for (int i = 0; i < int(size(que)); ++i) {
    int v = que[i];
    bitset<512> bs;
    bs.set();
    for (int u : g[v]) bs[a[u]] = 0;
    a[v] = bs._Find_first();
    for (int u : r[v])
      if (--deg[u] == 0) que.push_back(u);
  }

  vector<Mint> p(512);
  for (int v : Rep(n)) ++p[a[v]];
  for (auto&& e : p) e /= n;

  auto f = [](auto&& lo, auto&& hi) {
    auto x = lo;
    auto y = hi;
    lo = x + y;
    hi = x - y;
  };

  bitwise_transform(ALL(p), f);
  for (auto&& e : p) e = 1 / (1 + n * (1 - e));
  bitwise_transform(ALL(p), f);
  for (auto&& e : p) e /= 512;
  DUMP(p);
  cout << 1 - p[0] << '\n';
}