#include <bits/stdc++.h>

template <class ForwardIterator,
          class T = typename std::iterator_traits<ForwardIterator>::value_type>
std::vector<std::pair<T, int>> rle(ForwardIterator first,
                                   ForwardIterator last) {
  std::vector<std::pair<T, int>> res;
  int n = 0;
  for (auto it = first; it != last; ++it)
    n += std::next(it) == last or not(*it == *std::next(it));
  res.reserve(n);
  for (; first != last; ++first)
    if (std::empty(res) or not(res.back().first == *first))
      res.emplace_back(*first, 1);
    else
      ++res.back().second;
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
  vector<int> a(n);
  generate(ALL(a), scan<>);
  auto s = accumulate(ALL(a), int64_t(0));
  if (s % n) {
    cout << "0\n";
    exit(0);
  }
  s /= n;
  vector<int> lt, gt;
  for (auto&& e : a) {
    if (e < s) lt.push_back(e);
    if (e > s) gt.push_back(e);
  }
  sort(ALL(lt));
  sort(ALL(gt));
  if (min(size(lt), size(gt)) <= 1) {
    Mint ans = C::fact(n);
    for (auto&& [key, len] : rle(ALL(lt))) ans *= C::inv_fact(len);
    for (auto&& [key, len] : rle(ALL(gt))) ans *= C::inv_fact(len);
    ans *= C::inv_fact(n - size(lt) - size(gt));
    cout << ans << '\n';
  } else {
    Mint ans = C::binom(n, size(lt) + size(gt));
    ans *= C::fact(size(lt));
    ans *= C::fact(size(gt));
    for (auto&& [key, len] : rle(ALL(lt))) ans *= C::inv_fact(len);
    for (auto&& [key, len] : rle(ALL(gt))) ans *= C::inv_fact(len);
    ans *= 2;
    cout << ans << '\n';
  }
}