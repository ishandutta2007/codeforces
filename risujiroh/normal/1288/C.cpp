#include <bits/stdc++.h>
using namespace std;

template <class T, class F = multiplies<T>>
T power(T a, long long n, F op = multiplies<T>(), T e = {1}) {
  assert(n >= 0);
  T res = e;
  while (n) {
    if (n & 1) res = op(res, a);
    if (n >>= 1) a = op(a, a);
  }
  return res;
}

template <unsigned Mod> struct Modular {
  using M = Modular;
  unsigned v;
  Modular(long long a = 0) : v((a %= Mod) < 0 ? a + Mod : a) {}
  M operator-() const { return M() -= *this; }
  M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
  M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
  M& operator*=(M r) { v = (uint64_t)v * r.v % Mod; return *this; }
  M& operator/=(M r) { return *this *= power(r, Mod - 2); }
  friend M operator+(M l, M r) { return l += r; }
  friend M operator-(M l, M r) { return l -= r; }
  friend M operator*(M l, M r) { return l *= r; }
  friend M operator/(M l, M r) { return l /= r; }
  friend bool operator==(M l, M r) { return l.v == r.v; }
};

constexpr long long mod = 1e9 + 7;
using Mint = Modular<mod>;

vector<Mint> fact, inv_fact, minv;
void prepare(int n) {
  fact.resize(n + 1), inv_fact.resize(n + 1), minv.resize(n + 1);
  for (int i = 0; i <= n; ++i) fact[i] = i ? i * fact[i - 1] : 1;
  inv_fact[n] = 1 / fact[n];
  for (int i = n; i; --i) inv_fact[i - 1] = i * inv_fact[i];
  for (int i = 1; i <= n; ++i) minv[i] = inv_fact[i] * fact[i - 1];
}
Mint binom(int n, int k) {
  if (k < 0 or k > n) return 0;
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}
template<> Mint& Mint::operator/=(Mint r) {
  return *this *= r.v < minv.size() ? minv[r.v] : power(r, mod - 2);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  prepare(n + 2 * m);
  Mint res = binom(2 * m + n - 1, 2 * m);
  cout << res.v << '\n';
}