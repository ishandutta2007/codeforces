#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
struct Mint {
  int v;
  Mint(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
  Mint operator-() const { return Mint() -= *this; }
  Mint& operator*=(Mint r) { return *this = 1LL * v * r.v; }
  Mint& operator/=(Mint r) { return *this *= r.inv(); }
  Mint& operator+=(Mint r) { if ((v += r.v) >= mod) v -= mod; return *this; }
  Mint& operator-=(Mint r) { if ((v -= r.v) < 0) v += mod; return *this; }
  friend Mint operator*(Mint l, Mint r) { return l *= r; }
  friend Mint operator/(Mint l, Mint r) { return l /= r; }
  friend Mint operator+(Mint l, Mint r) { return l += r; }
  friend Mint operator-(Mint l, Mint r) { return l -= r; }
  Mint pow(long long n) const {
    assert(n >= 0);
    Mint res = 1;
    for (Mint t = *this; n; t *= t, n >>= 1) if (n & 1) res *= t;
    return res;
  }
  Mint inv() const { assert(v != 0); return pow(mod - 2); }
  friend string to_string(Mint a) { return to_string(a.v); }
};

constexpr int lim = 1e4;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  Mint p = Mint(m).inv(), q = 1 - p;
  vector<Mint> pow(lim + 1), powp(lim + 1), powq(lim + 1);
  for (int i = 0; i <= lim; ++i) {
    pow[i] = Mint(i).pow(k);
    powp[i] = p.pow(i);
    powq[i] = q.pow(i);
  }
  vector<Mint> fact(lim + 1, 1);
  for (int i = 1; i <= lim; ++i) {
    fact[i] = i * fact[i - 1];
  }
  vector<Mint> finv(lim + 1);
  finv[lim] = fact[lim].inv();
  for (int i = lim; i; --i) {
    finv[i - 1] = i * finv[i];
  }
  auto comb = [&](int a, int b) -> Mint {
    if (b < 0 or b > a) {
      return 0;
    }
    return fact[a] * finv[b] * finv[a - b];
  };
  Mint res;
  for (int a = 0; a <= k; ++a) {
    Mint crr;
    for (int x = 0; x <= a; ++x) {
      crr += pow[x] * comb(a, x) * powp[x] * powq[a - x];
    }
    Mint num = 1, den = 1;
    for (int i = 0; i <= k; ++i) {
      if (i != a) {
        num *= n - i;
        den *= a - i;
      }
    }
    res += crr * num / den;
  }
  cout << res.v << '\n';
}