#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define CHECK(...)
#endif

namespace {

template<int MOD>
struct Integral {
  int v_ = 0;

  Integral(int v) : v_(norm(v)) {}  // Implicit conversion is allowed.
  Integral(long long v) : v_(norm(v)) {}  // Implicit conversion is allowed.
  Integral() = default;
  ~Integral() = default;

  template<typename T> T norm(T v) const {
    if constexpr(std::is_same<long long, T>::value) {
      v %= MOD;
      if (v < 0) v += MOD;
    } else {
      if (v >= MOD) v -= MOD;
      if (v < 0) v += MOD;
      if (v >= MOD || v < 0) {
        v %= MOD;
        if (v < 0) v += MOD;
      }
    }
    return v;
  }

  int val() const { return v_; }
  Integral& operator+=(const Integral& rhs) { v_ += rhs.val(); if (v_ >= MOD) v_ -= MOD; return *this; }
  Integral& operator-=(const Integral& rhs) { v_ += MOD - rhs.val(); if (v_ >= MOD) v_ -= MOD; return *this; }
  Integral& operator*=(const Integral& rhs) { v_ = v_ * 1LL * rhs.val() % MOD; return *this; }
  Integral& operator/=(const Integral& rhs) { v_ = v_ * 1LL * rhs.inv().val() % MOD; return *this; }
  Integral operator+(const Integral& rhs) const { Integral ret = *this; return ret += rhs; }
  Integral operator-(const Integral& rhs) const { Integral ret = *this; return ret -= rhs; }
  Integral operator*(const Integral& rhs) const { Integral ret = *this; return ret *= rhs; }
  Integral operator/(const Integral& rhs) const { Integral ret = *this; return ret /= rhs; }
  bool operator==(const Integral& rhs) const { return val() == rhs.val(); }
  bool operator!=(const Integral& rhs) const { return !(*this == rhs); }
  const Integral operator-() const { return Integral(-val()); }
  const Integral& operator++() { v_ += 1; if (v_ >= MOD) v_ -= MOD; return *this; }
  const Integral operator++(int) { Integral ret = *this; ++(*this); return ret; }
  const Integral& operator--() { v_ += MOD - 1; if (v_ >= MOD) v_ -= MOD; return *this; }
  const Integral operator--(int) { Integral ret = *this; --(*this); return ret; }

  Integral power(long long b) const {
    long long ret = 1 % MOD, a = v_;
    for ( ; b; b >>= 1, a = a * a % MOD) if (b & 1) ret = ret * a % MOD; return ret;
  }
  Integral inv() const { return power(MOD - 2); }

  std::string to_string() const { return std::string("{") + std::to_string(val()) + "}"; }
};

template<int MOD>
std::string to_string(const Integral<MOD>& v) {
  return v.to_string();
}

template<int MOD, bool kAllowBruteForce = false>
struct Binomial final {
  std::vector<Integral<MOD>> factor, inv_factor;

  explicit Binomial(int n = 0) : factor(n + 1), inv_factor(n + 1) {
    factor[0] = 1;
    for (int i = 1; i <= n; ++i) factor[i] = factor[i - 1] * i;
    inv_factor[n] = factor[n].inv();
    for (int i = n; i >= 1; --i) inv_factor[i - 1] = inv_factor[i] * i;
  }
  ~Binomial() = default;

  template<typename T>
  Integral<MOD> operator()(T a, T b) const {
    if (a < b || b < 0) return 0;
    if (a < factor.size()) return factor[a] * inv_factor[b] * inv_factor[a - b];
    if constexpr(!kAllowBruteForce) {
      throw std::out_of_range("Binomial");
    } else {
      b = std::min(b, a - b);
      Integral<MOD> ret = 1;
      for (T i = 1; i <= b; ++i) ret = ret * (a + 1 - i) / i;
      return ret;
    }
  }
};

template<int MOD>
struct PowerTable final : public std::vector<Integral<MOD>> {
  PowerTable(int n, const Integral<MOD>& g) {
    static_assert(sizeof(PowerTable) == sizeof(std::vector<Integral<MOD>>), "");
    this->resize(n + 1);
    this->at(0) = 1;
    this->at(1) = g;
    for (int i = 2; i < this->size(); ++i) this->at(i) = this->at(i - 1) * this->at(1);
  }
};

const int MOD = 1e9 + 7;
using Mint = Integral<MOD>;
using Binom = Binomial<MOD>;
using Power = PowerTable<MOD>;

// Binom binom(200000);
// Power pw2(200000, 2);

struct Solver {
  using State = std::pair<Mint, Mint>;
  std::vector<std::vector<std::vector<std::vector<State>>>> f;
  int n, m, rb, cb, rd, cd, p;

  void solve(int ca, std::istream& reader) {
    reader >> n >> m >> rb >> cb >> rd >> cd >> p;
    --rb;
    --cb;
    --rd;
    --cd;
    f.resize(n, std::vector<std::vector<std::vector<State>>>(m, std::vector<std::vector<State>>(2, std::vector<State>(2))));
    f[rb][cb][1][1] = State(1, 0);
    int x = rb, y = cb, dx = 1, dy = 1;
    while (true) {
      State cur = f[x][y][dx == 1][dy == 1];
      // DUMP(x, y, dx, dy, cur);

      Mint p1 = 0, p2 = 0;
      if (x == rd || y == cd) {
        p1 = Mint(1) - Mint(p) / 100;
        p2 = Mint(1) - p1;
      } else {
        p1 = 1;
        p2 = 0;
      }

      if ((x + 1 == n && dx == 1) || (x == 0 && dx == -1)) dx *= -1;
      if ((y + 1 == m && dy == 1) || (y == 0 && dy == -1)) dy *= -1;
      x += dx;
      y += dy;

      State& nex = f[x][y][dx == 1][dy == 1];
      State candidate = State(cur.first / p1, (cur.second - p2) / p1 - 1);
      // DUMP(x, y, dx, dy, nex);
      // DUMP();
      if (nex == State(0, 0)) {
        nex = candidate;
      } else {
        Mint result = (candidate.second - nex.second) / (nex.first - candidate.first) - 1;
        printf("%d\n", result.val());
        return;
      }
    }
  }
};

}  // namespace

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}