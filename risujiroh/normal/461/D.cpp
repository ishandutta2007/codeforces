#include <bits/stdc++.h>

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

class Dsu {
 public:
  Dsu() {}
  explicit Dsu(int n) : dat(n, -1), num_ccs_(n) {}

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
    --num_ccs_;
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
  int num_ccs() const { return num_ccs_; }

 private:
  std::vector<int> dat;
  int num_ccs_;
};

template <class T, class N>
constexpr T power(T a, N n) {
  static_assert(std::is_integral_v<N>);
  assert(n >= 0);
  T res = n & 1 ? a : 1;
  while (n >>= 1) {
    a *= a;
    if (n & 1) res *= a;
  }
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
  if (OjLocal<0, 1>) {
    constexpr int N = 3;
    vector bs(N, vector<bitset<N>>(N));
    for (int j : Rep(N)) {
      bs[0][j][j] = 1;
      if (j + 2 < N) bs[0][j][j + 2] = 1;
    }

    constexpr array di{-1, -1, -2};
    constexpr array dj{-1, +1, 0};

    for (int i : Rep(1, N))
      for (int j : Rep(N)) {
        for (int k : Rep(3)) {
          int ni = i + di[k];
          int nj = j + dj[k];
          if (ni < 0 or ni >= N or nj < 0 or nj >= N) continue;
          bs[i][j] ^= bs[ni][nj];
        }
      }
    DUMP(bs);
  }

  int n = scan();
  Dsu d(2 * n + 1);
  for (int k = scan(); k--;) {
    int i = scan() - 1;
    int j = scan() - 1;
    int f = min({i + 1, n - i, j + 1, n - j});
    int u = abs(j - i);
    int v = u + 2 * f;
    if (scan<char>() == 'o') {
      if (v < n) {
        d.unite(u, n + v);
        d.unite(n + u, v);
      } else {
        d.unite(n + u, 2 * n);
      }
    } else {
      if (v < n) {
        d.unite(u, v);
        d.unite(n + u, n + v);
      } else {
        d.unite(u, 2 * n);
      }
    }
  }
  for (int v : Rep(n)) {
    if (d.same(v, n + v)) {
      cout << "0\n";
      exit(0);
    }
  }
  int ans = 0;
  for (int v : Rep(n))
    ans +=
        d.root(v) == v and (not d.same(v, 2 * n) and not d.same(n + v, 2 * n));
  cout << power<Mint>(2, ans) << '\n';
}