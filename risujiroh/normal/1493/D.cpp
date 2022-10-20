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

std::pair<std::vector<int>, std::vector<int>> linear_sieve(int n) {
  std::vector<int> primes, lpf(n + 1);
  for (int d = 2; d <= n; ++d) {
    if (lpf[d] == 0) lpf[d] = d, primes.push_back(d);
    for (int p : primes) {
      if (p * d > n or p > lpf[d]) break;
      lpf[p * d] = p;
    }
  }
  return {primes, lpf};
}
std::vector<int> factor(int n, const std::vector<int>& lpf) {
  assert(n >= 1);
  std::vector<int> res;
  for (; n > 1; n /= res.back()) res.push_back(lpf[n]);
  return res;
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

using Mint = ModularInt<int(1e9) + 7>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  auto [primes, lpf] = linear_sieve(2e5);
  int n = scan();
  int q = scan();
  vector<map<int, int>> mp(n);
  for (int i : Rep(n))
    for (int p : factor(scan(), lpf)) ++mp[i][p];

  vector<multiset<int>> ms(2e5 + 1);
  for (int i : Rep(n))
    for (auto&& [p, e] : mp[i]) ms[p].insert(e);

  Mint ans = 1;
  for (int p : primes)
    if (int(size(ms[p])) == n) ans *= power<Mint>(p, *begin(ms[p]));

  while (q--) {
    int i = scan() - 1;
    int x = scan();
    set<int> se;
    for (int p : factor(x, lpf)) se.insert(p);
    for (int p : se)
      if (int(size(ms[p])) == n) ans /= power<Mint>(p, *begin(ms[p]));
    for (int p : se)
      if (mp[i].count(p)) ms[p].erase(ms[p].find(mp[i][p]));
    for (int p : factor(x, lpf)) ++mp[i][p];
    for (int p : se) ms[p].insert(mp[i][p]);
    for (int p : se)
      if (int(size(ms[p])) == n) ans *= power<Mint>(p, *begin(ms[p]));
    cout << ans << '\n';
  }
}