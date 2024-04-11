#include <bits/stdc++.h>
using namespace std;

template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = 1) {
  assert(n >= 0);
  T res = e;
  while (n) {
    if (n & 1) res = op(res, a);
    if (n >>= 1) a = op(a, a);
  }
  return res;
}

unsigned mod = 2;
struct Mint {
  using M = Mint;
  unsigned v;
  Mint(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
  M operator-() const { return M() -= *this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % mod; return *this; }
  M& operator/=(M r) { return *this *= power(r, mod - 2); }
  M& operator+=(M r) { if ((v += r.v) >= mod) v -= mod; return *this; }
  M& operator-=(M r) { if ((v += mod - r.v) >= mod) v -= mod; return *this; }
  friend M operator*(M l, M r) { return l *= r; }
  friend M operator/(M l, M r) { return l /= r; }
  friend M operator+(M l, M r) { return l += r; }
  friend M operator-(M l, M r) { return l -= r; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n >> mod;
  vector<Mint> fact(n + 1, 1), inv_fact(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fact[i] = i * fact[i - 1];
    inv_fact[i] = 1 / fact[i];
  }
  auto comb = [&](int a, int b) -> Mint {
    if (b < 0 or b > a) {
      return 0;
    }
    return fact[a] * inv_fact[b] * inv_fact[a - b];
  };
  Mint res;
  for (int k = 1; k <= n; ++k) {
    Mint x = n - k + 1;
    res += x * x / comb(n, k);
  }
  res *= fact[n];
  cout << res.v << '\n';
}