#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr lint mod = 998244353;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }
inline lint invm(lint a, lint p = mod) { a %= p; return a == 1 ? 1 : -p / a * invm(p % a) % p; }
inline lint powm(lint a, lint n, lint p = mod) { return !n ? 1 : powm(a * a % p, n >> 1, p) * (n & 1 ? a : 1) % p; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, m, k; cin >> n >> m >> k;
  V<lint> b(m); for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = m - 1; i; i--) b[i] -= b[i - 1];
  lint res = 1;
  for (int i = 0; i < m; i++) {
    (res *= (powm(k, 2 * b[i]) + powm(k, b[i])) * invm(2) % mod) %= mod;
  }
  res *= powm(k, n - accumulate(b.begin(), b.end(), 0LL) * 2);
  cout << emod(res) << '\n';
}