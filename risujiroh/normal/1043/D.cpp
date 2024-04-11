#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint mod1 = 1e9 + 7, mod2 = 1e9 + 9;
inline lint emod(lint a, lint p) { return (a % p + p) % p; }
constexpr int b1 = 17, b2 = 23;
  
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a; assign(a, m, n);
  for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) cin >> a[j][i], --a[j][i];
  VV<> ia; assign(ia, m, n);
  for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) ia[j][a[j][i]] = i;
  VV<lint> h1, h2; assign(h1, m, n + 1), assign(h2, m, n + 1);
  for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i) {
    h1[j][i + 1] = (h1[j][i] * b1 + a[j][i]) % mod1;
    h2[j][i + 1] = (h2[j][i] * b2 + a[j][i]) % mod2;
  }
  V<lint> powm1(n + 1, 1), powm2(n + 1, 1);
  for (int i = 0; i < n; ++i) {
    powm1[i + 1] = powm1[i] * b1 % mod1;
    powm2[i + 1] = powm2[i] * b2 % mod2;
  }
  auto chk = [&](int l, int x) -> bool {
    if (x > n) return false;
    for (int j = 1; j < m; ++j) {
      if (ia[j][a[0][l]] + x - l > n) return false;
      if (emod(h1[0][x] - h1[0][l] * powm1[x - l], mod1) !=
          emod(h1[j][ia[j][a[0][l]] + x - l] - h1[j][ia[j][a[0][l]]] * powm1[x - l], mod1)) return false;
      if (emod(h2[0][x] - h2[0][l] * powm2[x - l], mod2) !=
          emod(h2[j][ia[j][a[0][l]] + x - l] - h2[j][ia[j][a[0][l]]] * powm2[x - l], mod2)) return false;
    }
    return true;
  };
  int l = 0;
  lint res = 0;
  while (l < n) {
    int ok = l + 1, ng = n + 1;
    while (ng - ok > 1) {
      int med = ok + ng >> 1;
      if (chk(l, med)) ok = med;
      else ng = med;
    }
    res += (lint) (ok - l) * (ok - l + 1) / 2;
    l = ok;
  }
  cout << res << '\n';
}