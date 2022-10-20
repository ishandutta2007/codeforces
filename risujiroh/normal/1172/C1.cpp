#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<unsigned P> struct ModInt {
  using M = ModInt;
  unsigned v;
  ModInt() : v(0) {}
  template<class Z> ModInt(Z x) : v(x >= 0 ? x % P : (P - -x % P) % P) {}
  constexpr ModInt(unsigned v, int) : v(v) {}
  static constexpr unsigned p() { return P; }
  M operator+() const { return *this; }
  M operator-() const { return {v ? P - v : 0, 0}; }
  explicit operator bool() const noexcept { return v; }
  bool operator!() const noexcept { return !(bool) *this; }
  M operator*(M r) const { return M(*this) *= r; }
  M operator/(M r) const { return M(*this) /= r; }
  M operator+(M r) const { return M(*this) += r; }
  M operator-(M r) const { return M(*this) -= r; }
  bool operator==(M r) const { return v == r.v; }
  bool operator!=(M r) const { return !(*this == r); }
  M& operator*=(M r) { v = (uint64_t) v * r.v % P; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= P) v -= P; return *this; }
  M& operator-=(M r) { if ((v += P - r.v) >= P) v -= P; return *this; }
  M inv() const {
    int a = v, b = P, x = 1, u = 0;
    while (b) {
      int q = a / b;
      swap(a -= q * b, b);
      swap(x -= q * u, u);
    }
    assert(a == 1);
    return x;
  }
  template<class Z> M pow(Z n) const {
    if (n < 0) return pow(-n).inv();
    M res = 1;
    for (M a = *this; n; a *= a, n >>= 1) if (n & 1) res *= a;
    return res;
  }
  template<class Z> friend M operator*(Z l, M r) { return M(l) *= r; }
  template<class Z> friend M operator/(Z l, M r) { return M(l) /= r; }
  template<class Z> friend M operator+(Z l, M r) { return M(l) += r; }
  template<class Z> friend M operator-(Z l, M r) { return M(l) -= r; }
  friend ostream& operator<<(ostream& os, M r) { return os << r.v; }
  friend istream& operator>>(istream& is, M& r) { lint x; is >> x; r = x; return is; }
  template<class Z> friend bool operator==(Z l, M r) { return M(l) == r; }
  template<class Z> friend bool operator!=(Z l, M r) { return !(l == r); }
};
using Mint = ModInt<998244353>;
string to_frac(Mint x) {
  static map< int, pair<int, int> > mp;
  if (mp.empty()) {
    mp[0] = mp[Mint::p()] = {0, 1};
    for (int b = 2; b <= 1000; ++b) {
      for (int a = 1; a < b; ++a) if (__gcd(a, b) == 1) {
        mp[(Mint(a) / b).v] = {a, b};
      }
    }
  }
  auto itr = mp.lower_bound(x.v);
  if (itr != begin(mp) and x.v - prev(itr)->first < itr->first - x.v) --itr;
  auto res = to_string(itr->second.first + itr->second.second * ((int) x.v - itr->first));
  if (itr->second.second > 1) {
    res += '/';
    res += to_string(itr->second.second);
  }
  return res;
}

V<Mint> fact, ifact, inv, powB;
void init(int n, int B = 2) {
  fact.resize(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = i * fact[i - 1];
  }
  ifact.resize(n + 1);
  ifact[n] = fact[n].inv();
  for (int i = n; i > 0; --i) {
    ifact[i - 1] = i * ifact[i];
  }
  inv.resize(n + 1);
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    int q = Mint::p() / i;
    inv[i] = -q * inv[Mint::p() - i * q];
  }
  powB.resize(n + 1);
  powB[0] = 1;
  for (int i = 0; i < n; ++i) {
    powB[i + 1] = powB[i] * B;
  }
}
Mint comb(int n, int r) {
  if (r < 0 or r > n) return 0;
  return fact[n] * ifact[r] * ifact[n - r];
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> w(n); for (auto&& e : w) cin >> e;
  int X = 0, Y = 0;
  for (int i = 0; i < n; ++i) {
    (a[i] ? X : Y) += w[i];
  }
  constexpr int o = 55;
  for (int i = 0; i < n; ++i) {
    VV<Mint> dp(2 * o + 1, V<Mint>(101));
    // dp[X + Y][w[i]] = 1;
    dp[o][w[i]] = 1;
    for (int j = 0; j < m; ++j) {
      VV<Mint> ndp(2 * o + 1, V<Mint>(101));
      for (int s = X + Y - o + 1; s < X + Y + o; ++s) {
        int x = s + j + X - Y >> 1, y = s - x;
        if (y < 0) continue;
        for (int t = 0; t <= 100; ++t) if (dp[o + s - (X + Y)][t]) {
          int ss = o - X - Y + s;
          if (a[i]) {
            if (t + 1 <= 100) ndp[ss + 1][t + 1] += dp[ss][t] * t / s;
            ndp[ss + 1][t] += dp[ss][t] * (x - t) / s;
            ndp[ss - 1][t] += dp[ss][t] * y / s;
          } else {
            if (t) ndp[ss - 1][t - 1] += dp[ss][t] * t / s;
            ndp[ss - 1][t] += dp[ss][t] * (y - t) / s;
            ndp[ss + 1][t] += dp[ss][t] * x / s;
          }
        }
      }
      swap(dp, ndp);
    }
    Mint res;
    for (const auto& v : dp) for (int t = 0; t <= 100; ++t) {
      res += v[t] * t;
    }
    cout << res << '\n';
  }
}