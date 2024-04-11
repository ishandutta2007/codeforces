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
  D operator+() const { return *this; }
  D operator-() const { return raw(v_ ? modulus_ - v_ : 0); }
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

using Mint = DynamicModularInt64<__COUNTER__>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n = scan();
  int q = scan();
  int64_t seed = scan();
  int64_t vmax = scan();

  auto rnd = [&] {
    auto ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
  };

  vector<pair<int64_t, int>> a(n);
  for (int i : Rep(n)) a[i] = {rnd() % vmax + 1, 1};

  while (q--) {
    int op = rnd() % 4 + 1;
    int l = rnd() % n + 1;
    int r = rnd() % n + 1;
    if (l > r) swap(l, r);
    int x = op == 3 ? rnd() % (r - l + 1) : rnd() % vmax + 1;
    --l;

    DUMP(a);
    DUMP(op, l, r, x);

    vector<pair<int64_t, int>> na;
    if (op == 1) {
      int pos = 0;
      for (auto&& [v, len] : a) {
        if (pos < l) {
          na.emplace_back(v, min(l - pos, len));
        }
        if (int s = max(l, pos), t = min(r, pos + len); s < t) {
          na.emplace_back(v + x, t - s);
        }
        if (r < pos + len) {
          na.emplace_back(v, min(pos + len - r, len));
        }
        pos += len;
      }
    } else if (op == 2) {
      int pos = 0;
      for (auto&& [v, len] : a) {
        if (pos < l) {
          na.emplace_back(v, min(l - pos, len));
        }
        if (int s = max(l, pos), t = min(r, pos + len); s < t) {
          na.emplace_back(x, t - s);
        }
        if (r < pos + len) {
          na.emplace_back(v, min(pos + len - r, len));
        }
        pos += len;
      }
    } else if (op == 3) {
      int pos = 0;
      for (auto&& [v, len] : a) {
        if (int s = max(l, pos), t = min(r, pos + len); s < t)
          na.emplace_back(v, t - s);
        pos += len;
      }
      sort(ALL(na));
      for (auto&& [v, len] : na) {
        if (x < len) {
          cout << v << '\n';
          break;
        }
        x -= len;
      }
      continue;
    } else if (op == 4) {
      Mint::modulus(rnd() % vmax + 1);
      int pos = 0;
      Mint ans;
      for (auto&& [v, len] : a) {
        if (int s = max(l, pos), t = min(r, pos + len); s < t)
          ans += power<Mint>(v, x) * (t - s);
        pos += len;
      }
      cout << ans << '\n';
      continue;
    } else
      assert(false);

    a.clear();
    for (auto&& [v, len] : na)
      if (empty(a) or a.back().first != v)
        a.emplace_back(v, len);
      else
        a.back().second += len;
  }
}