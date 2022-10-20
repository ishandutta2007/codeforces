#include <bits/stdc++.h>
using namespace std;

template <unsigned Mod> struct ModularInt {
  using M = ModularInt;
  unsigned v;
  ModularInt(long long a = 0) : v((a %= Mod) < 0 ? a + Mod : a) {}
  M operator-() const { return M() -= *this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % Mod; return *this; }
  M& operator/=(M r) { return *this *= r.inv(); }
  M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
  M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
  friend M operator*(M l, M r) { return l *= r; }
  friend M operator/(M l, M r) { return l /= r; }
  friend M operator+(M l, M r) { return l += r; }
  friend M operator-(M l, M r) { return l -= r; }
  M pow(long long n) const {
    assert(n >= 0);
    M res = 1;
    for (M t = *this; n; t *= t, n >>= 1) if (n & 1) res *= t;
    return res;
  }
  M inv() const { assert(v != 0); return pow(Mod - 2); }
  friend string to_string(M a) { return to_string(a.v); }
};
constexpr unsigned mod = 998244353;
using Mint = ModularInt<mod>;

constexpr int lim = 1e6;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Mint> c(lim), p(lim);
  auto in = Mint(n).inv();
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    auto ik = Mint(k).inv();
    for (int j = 0; j < k; ++j) {
      int a;
      cin >> a;
      --a;
      c[a] += 1;
      p[a] += in * ik;
    }
  }
  Mint res;
  for (int x = 0; x < lim; ++x) {
    res += p[x] * c[x] * in;
  }
  cout << res.v << '\n';
}