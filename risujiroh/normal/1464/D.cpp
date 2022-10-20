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

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  for (int tt = scan(); tt--;) {
    int n = scan();
    Dsu d(n);
    for (int i : Rep(n)) d.unite(i, scan() - 1);
    vector<int> a;
    for (int i : Rep(n))
      if (d.root(i) == i) a.push_back(d.size(i));
    DUMP(a);

    int ans = 0;
    if (n % 3 == 0) {
      array<int, 3> num{};
      for (auto&& e : a) {
        ans += (e - 1) / 3;
        ++num[e % 3];
      }
      {
        int t = min(num[1], num[2]);
        ans += t;
        num[1] -= t;
        num[2] -= t;
        if (num[1]) {
          assert(num[2] == 0);
          assert(num[1] % 3 == 0);
          ans += num[1] / 3 * 2;
        }
        if (num[2]) {
          assert(num[1] == 0);
          assert(num[2] % 3 == 0);
          ans += num[2] / 3 * 3;
        }
      }
    } else if (n % 3 == 1) {
      array<int, 3> num{};
      for (auto&& e : a) {
        ans += (e - 1) / 3;
        ++num[e % 3];
      }
      if (num[2] >= 2) {
        num[2] -= 2;
      } else if (num[2] == 1) {
        --num[2];
        assert(num[1] >= 2);
        num[1] -= 2;
        ++ans;
      } else if (num[2] == 0) {
        assert(num[1] % 3 == 1);
        if (num[1] == 1) {
          --num[1];
          int x = -1;
          for (auto&& e : a)
            if (e % 3 == 1) {
              assert(x == -1);
              x = e;
            }
          if (x == 1) {
            ans += 2;
          } else {
          }
        } else {
          assert(num[1] >= 4);
          num[1] -= 4;
          ans += 2;
        }
      } else
        assert(false);
      {
        int t = min(num[1], num[2]);
        ans += t;
        num[1] -= t;
        num[2] -= t;
        if (num[1]) {
          assert(num[2] == 0);
          assert(num[1] % 3 == 0);
          ans += num[1] / 3 * 2;
        }
        if (num[2]) {
          assert(num[1] == 0);
          assert(num[2] % 3 == 0);
          ans += num[2] / 3 * 3;
        }
      }
      {
        int nans = 0;
        num.fill(0);
        for (auto&& e : a) {
          nans += (e - 1) / 3;
          ++num[e % 3];
        }
        if (num[1]) {
          --num[1];
          int x = -1;
          for (auto&& e : a)
            if (e % 3 == 1) {
              chmax(x, e);
            }
          if (x == 1) {
            ++nans;
          } else {
            --nans;
          }
          {
            int t = min(num[1], num[2]);
            nans += t;
            num[1] -= t;
            num[2] -= t;
            if (num[1]) {
              assert(num[2] == 0);
              assert(num[1] % 3 == 0);
              nans += num[1] / 3 * 2;
            }
            if (num[2]) {
              assert(num[1] == 0);
              assert(num[2] % 3 == 0);
              nans += num[2] / 3 * 3;
            }
          }
          chmin(ans, nans);
        }
      }
    } else if (n % 3 == 2) {
      array<int, 3> num{};
      for (auto&& e : a) {
        ans += (e - 1) / 3;
        ++num[e % 3];
      }
      if (num[2]) {
        --num[2];
      } else {
        assert(num[1] >= 2);
        num[1] -= 2;
        ++ans;
      }
      {
        int t = min(num[1], num[2]);
        ans += t;
        num[1] -= t;
        num[2] -= t;
        if (num[1]) {
          assert(num[2] == 0);
          assert(num[1] % 3 == 0);
          ans += num[1] / 3 * 2;
        }
        if (num[2]) {
          assert(num[1] == 0);
          assert(num[2] % 3 == 0);
          ans += num[2] / 3 * 3;
        }
      }
    } else
      assert(false);

    Mint mx = 1;
    if (n % 3 == 0)
      mx = power<Mint>(3, n / 3);
    else if (n % 3 == 1)
      mx = 4 * power<Mint>(3, (n - 4) / 3);
    else if (n % 3 == 2)
      mx = 2 * power<Mint>(3, (n - 2) / 3);
    else
      assert(false);
    cout << mx << ' ' << ans << '\n';
  }
}