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
  for (int tt = scan(); tt--;) {
    int n = scan();
    vector<int> a(n);
    generate(ALL(a), scan<>);

    vector<int64_t> suff(n + 1);
    for (int i : Per(n)) suff[i] = a[i] + suff[i + 1];

    vector<int64_t> aux(n + 1);
    for (int i : Per(n)) aux[i] = power(-1, i) * a[i] + aux[i + 1];

    auto f = [&](int l, int r) -> int64_t {
      assert(~(r - l) & 1);
      int64_t sum = 0;
      sum -= suff[0] - suff[l];
      sum += power(-1, l) * (aux[l] - aux[r]);
      sum += suff[r] - suff[n];
      return sum;
    };

    Mint ans;
    for (int r : Rep(n + 1)) {
      {
        int ok = (r & 1) - 2, ng = r + 2;
        while (ng - ok > 2) {
          int mid = ok + (ng - ok) / 4 * 2;
          (f(mid, r) > 0 ? ok : ng) = mid;
        }
        if (ng - ok == 2) ans += (ok - ((r & 1) - 2)) / 2;
      }
      if (n - r >= 3) {
        int ok = (r & 1) - 2, ng = r + 2;
        while (ng - ok > 2) {
          int mid = ok + (ng - ok) / 4 * 2;
          (f(mid, r) - 2 * a.back() > 0 ? ok : ng) = mid;
        }
        if (ng - ok == 2) ans += (ok - ((r & 1) - 2)) / 2;
      }
      {
        int ok = r & 1 ? 1 : 2, ng = r + 2;
        while (ng - ok > 2) {
          int mid = ok + (ng - ok) / 4 * 2;
          (f(mid, r) + 2 * a[0] > 0 ? ok : ng) = mid;
        }
        if (ng - ok == 2) ans += (ok - (r & 1 ? 1 : 2)) / 2;
      }
      if (n - r >= 3) {
        int ok = r & 1 ? 1 : 2, ng = r + 2;
        while (ng - ok > 2) {
          int mid = ok + (ng - ok) / 4 * 2;
          (f(mid, r) + 2 * a[0] - 2 * a.back() > 0 ? ok : ng) = mid;
        }
        if (ng - ok == 2) ans += (ok - (r & 1 ? 1 : 2)) / 2;
      }
      // DUMP(r, ans);
    }

    for (int m : Rep(2, n - 1)) ans += suff[0] - suff[m] > suff[m] - suff[n];
    cout << ans << '\n';
  }
}