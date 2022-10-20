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

template <class T, int N>
class Combination {
 public:
  static_assert(N >= 0);

  static T fact(int n) {
    static auto fact_ = [] {
      std::vector<T> res{1};
      res.reserve(N + 1);
      for (int i = 1; i <= N; ++i) res.push_back(res.back() * i);
      return res;
    }();
    assert(0 <= n), assert(n <= N);
    return fact_[n];
  }
  static T inv_fact(int n) {
    static auto inv_fact_ = [] {
      std::vector<T> res{1};
      res.reserve(N + 1);
      for (int i = 1; i <= N; ++i) res.push_back(res.back() / i);
      return res;
    }();
    assert(0 <= n), assert(n <= N);
    return inv_fact_[n];
  }
  static T binom(int n, int k) {
    if (k < 0) return 0;
    if (n < 0) {
      int m = -n + k - 1;
      assert(m <= N);
      return k & 1 ? -binom(m, k) : binom(m, k);
    }
    if (n < k) return 0;
    assert(n <= N);
    return fact(n) * inv_fact(k) * inv_fact(n - k);
  }
  static T homo(int n, int k) {
    if (k < 0) return 0;
    if (0 <= -n and -n < k) return 0;
    return k & 1 ? -binom(-n, k) : binom(-n, k);
  }

 private:
  Combination();
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

using Mint = ModularInt<int(1e9) + 7>;

constexpr int Limit = 1 << 20;

template <>
Mint& Mint::operator/=(Mint o) {
  static auto inv = [] {
    std::vector<Mint> res(Limit + 1);
    res[1] = 1;
    for (int l = 2; l <= Limit;) {
      int q = modulus() / l, r = std::min(modulus() / q, Limit) + 1;
      for (int i = l; i < r; ++i) res[i] = -q * res[modulus() - q * i];
      l = r;
    }
    return res;
  }();
  assert(o.v_);
  int v = o.v_;
  while (v > Limit) *this *= -(modulus() / std::exchange(v, modulus() % v));
  return *this *= inv[v];
}

using C = Combination<Mint, Limit>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();

  map<vector<int>, Mint> memo;
  auto go = Fix([&](auto solve, vector<int> a) -> Mint {
    int sum = 0;
    for (int i : Rep(1, n + 1)) sum += i * a[i];
    if (sum == 0) return 1;
    if (memo.count(a)) return memo[a];
    Mint res;
    vector<int> b;
    Fix([&](auto self) -> void {
      if (size(b) == size(a)) {
        int sub = 0;
        for (int i : Rep(1, n + 1)) sub += i * b[i];
        if (sub == sum) return;
        Mint num;
        for (int i : Rep(sub + 1))
          num += C::binom(sub, i) * C::fact(i) * C::fact(n - i - 1);
        int sign = -1;
        Mint coeff = 1;
        for (int i : Rep(1, n + 1)) {
          if ((a[i] - b[i]) & 1) sign = -sign;
          coeff *= C::binom(a[i], b[i]);
        }
        res += sign * coeff * power(num, sum - sub) * solve(b);
        return;
      }
      for (int v : Rep(a[size(b)] + 1)) {
        b.push_back(v);
        self();
        b.pop_back();
      }
    })();
    return memo[a] = res;
  });

  vector<int> p(n);
  generate(ALL(p), [] { return scan() - 1; });
  vector<bool> visited(n);
  vector<int> a(n + 1);
  for (int i : Rep(n))
    if (not visited[i]) {
      int sz = 0;
      for (int j = i;;) {
        visited[j] = true;
        ++sz;
        j = p[j];
        if (j == i) break;
      }
      ++a[sz];
    }
  cout << go(a) << '\n';
}