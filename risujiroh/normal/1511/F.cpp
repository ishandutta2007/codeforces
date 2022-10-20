#include <bits/stdc++.h>

// https :  // github.com/ecnerwala/cp-book/blob/master/src/bm.hpp
template <typename num>
std::vector<num> BerlekampMassey(const std::vector<num>& s) {
  int n = int(s.size()), L = 0, m = 0;
  std::vector<num> C(n), B(n), T;
  C[0] = B[0] = 1;

  num b = 1;
  for (int i = 0; i < n; i++) {
    ++m;
    num d = s[i];
    for (int j = 1; j <= L; j++) d += C[j] * s[i - j];
    if (d == 0) continue;
    T = C;
    num coef = d / b;
    for (int j = m; j < n; j++) C[j] -= coef * B[j - m];
    if (2 * L > i) continue;
    L = i + 1 - L;
    B = T;
    b = d;
    m = 0;
  }

  C.resize(L + 1);
  C.erase(C.begin());
  for (auto& x : C) {
    x = -x;
  }
  return C;
}

template <typename num>
num linearRec(const std::vector<num>& S, const std::vector<num>& tr,
              long long k) {
  int n = int(tr.size());
  assert(S.size() >= tr.size());

  auto combine = [&](std::vector<num> a, std::vector<num> b) {
    std::vector<num> res(n * 2 + 1);
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) res[i + j] += a[i] * b[j];
    for (int i = 2 * n; i > n; --i)
      for (int j = 0; j < n; j++) res[i - 1 - j] += res[i] * tr[j];
    res.resize(n + 1);
    return res;
  };

  std::vector<num> pol(n + 1), e(pol);
  pol[0] = e[1] = 1;

  for (++k; k; k /= 2) {
    if (k % 2) pol = combine(pol, e);
    e = combine(e, e);
  }

  num res = 0;
  for (int i = 0; i < n; i++) res += pol[i + 1] * S[i];
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

using Mint = ModularInt<998244353>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int m = scan();
  vector<string> s(n);
  generate(ALL(s), scan<string>);
  vector<string> suff;
  for (auto&& e : s)
    for (int i : Rep(size(e) + 1)) suff.push_back(e.substr(i));
  sort(ALL(suff));
  suff.erase(unique(ALL(suff)), end(suff));

  int lim = 100;
  vector f(lim + 1, vector<Mint>(size(suff)));
  f[0][0] = 1;

  for (int len : Rep(lim))
    for (int i : Rep(size(suff)))
      for (auto&& e : s)
        if (size(e) < size(suff[i])) {
          if (suff[i].substr(0, size(e)) != e) continue;
          if (len + int(size(e)) > lim) continue;
          f[len + size(e)][lower_bound(ALL(suff), suff[i].substr(size(e))) -
                           begin(suff)] += f[len][i];
        } else {
          if (e.substr(0, size(suff[i])) != suff[i]) continue;
          if (len + int(size(suff[i])) > lim) continue;
          f[len + size(suff[i])]
           [lower_bound(ALL(suff), e.substr(size(suff[i]))) - begin(suff)] +=
              f[len][i];
        }

  vector<Mint> a(lim + 1);
  for (int i : Rep(lim + 1)) a[i] = f[i][0];
  cout << linearRec(a, BerlekampMassey(a), m) << '\n';
}