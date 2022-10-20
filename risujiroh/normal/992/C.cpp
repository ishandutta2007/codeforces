#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint mod = 1e9 + 7;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }
inline lint powm(lint a, lint n, lint p = mod) { return !n ? 1 : powm(a * a % p, n >> 1, p) * (n & 1 ? a : 1) % p; }

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint x, k; cin >> x >> k;
  if (!x) return cout << 0 << '\n', 0;
  cout << emod(1 + powm(2, k) * (2 * x % mod - 1)) << '\n';
}