#include <bits/stdc++.h>

template <class> class GetInverse;
template <uint32_t P> class Fp {
 public:
  static_assert([](int n) -> bool {
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0) return false;
    return 3 <= n and n < 1 << 30;
  }(P));
  static constexpr int mod() { return P; }

  Fp() : v(0) {}
  template <class Int> Fp(const Int& a) : v(a % mod()) { v = (uint64_t(v + P) << 32) % P; }
  int val() const {
    int res = reduce(v) - P;
    return res < 0 ? res + P : res;
  }
  Fp& operator++() { return *this += 1; }
  Fp& operator--() { return *this -= 1; }
  Fp& operator*=(Fp o) { return v = reduce(uint64_t(v) * o.v), *this; }
  Fp& operator/=(Fp o) { return *this *= GetInverse<Fp>{}(o); }
  Fp& operator+=(Fp o) { return v = int(v += o.v - 2 * P) < 0 ? v + 2 * P : v, *this; }
  Fp& operator-=(Fp o) { return v = int(v -= o.v) < 0 ? v + 2 * P : v, *this; }

  friend Fp operator++(Fp& a, int) { return std::exchange(a, ++Fp(a)); }
  friend Fp operator--(Fp& a, int) { return std::exchange(a, --Fp(a)); }
  friend Fp operator+(Fp a) { return a; }
  friend Fp operator-(Fp a) { return Fp{} -= a; }
  friend Fp operator*(Fp a, Fp b) { return a *= b; }
  friend Fp operator/(Fp a, Fp b) { return a /= b; }
  friend Fp operator+(Fp a, Fp b) { return a += b; }
  friend Fp operator-(Fp a, Fp b) { return a -= b; }
  friend bool operator==(Fp a, Fp b) { return a.v == b.v; }
  friend bool operator!=(Fp a, Fp b) { return a.v != b.v; }

 private:
  static constexpr uint32_t R = []() -> uint32_t {
    uint32_t res = -P;
    for (int _ = 4; _--;) res *= P * res + 2;
    return res;
  }();
  static uint32_t reduce(uint64_t x) { return (x + P * uint64_t(R * uint32_t(x))) >> 32; }

  uint32_t v;
};
template <uint32_t P> class GetInverse<Fp<P>> {
 public:
  static void init(int n) {
    inv.reserve(n + 1);
    for (int i = std::size(inv); i <= n;) {
      int q = P / i, j = std::min<int>(P / q, n);
      for (; i <= j; ++i) inv.push_back(-q * inv[P - q * i]);
    }
  }

  Fp<P> operator()(Fp<P> a) const {
    __glibcxx_assert(a.val());
    if ((-a).val() < int(std::size(inv))) return -inv[(-a).val()];
    int y0 = 0, z0 = P, y1 = 1, z1 = a.val();
    while (z1 >= std::max<int>(std::size(inv), 2)) std::swap(y0 -= z0 / z1 * y1, y1), std::swap(z0 %= z1, z1);
    return z1 > 1 ? y1 * inv[z1] : y1;
  }

 private:
  static inline std::vector<Fp<P>> inv{0, 1};
};

// clang-format off
using namespace std;
class Rep{struct I{int i;void operator++(){++i;}int operator*(){return i;}bool operator!=(I o){return i<*o;}}b,e;
public:Rep(int l,int r):b{l},e{r}{}Rep(int n):Rep(0,n){}I begin(){return b;}I end(){return e;}};
class Per{struct I{int i;void operator++(){--i;}int operator*(){return i;}bool operator!=(I o){return i>*o;}}b,e;
public:Per(int l,int r):b{r-1},e{l-1}{}Per(int n):Per(0,n){}I begin(){return b;}I end(){return e;}};
template<class F>struct Fix:F{Fix(F f):F(f){}
template<class...T>decltype(auto)operator()(T&&...a){return F::operator()(*this,forward<T>(a)...);}};
template<class T=int>T scan(){T r;cin>>r;return r;}
template<class T,class U=T>bool chmin(T&a,U&&b){return b<a?a=forward<U>(b),1:0;}
template<class T,class U=T>bool chmax(T&a,U&&b){return a<b?a=forward<U>(b),1:0;}
#ifndef LOCAL
#define DUMP(...) void(0)
#endif
#define ALL(c) begin(c), end(c)
// clang-format on

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n = scan();

  vector<int> num_divisors(n + 1);
  for (int d : Rep(1, n + 1))
    for (int i = d; i <= n; i += d) ++num_divisors[i];

  using Mint = Fp<998244353>;

  vector<Mint> pref(n + 1);
  for (int i : Rep(1, n + 1)) {
    pref[i] = pref[i - 1] + num_divisors[i];
    pref[i] += pref[i - 1];
  }

  Mint ans = pref[n] - pref[n - 1];
  cout << ans.val() << '\n';
}