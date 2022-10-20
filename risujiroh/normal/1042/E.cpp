#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

const lint mod = 998244353;
inline lint emod(lint a, lint p = mod) { return (a % p + p) % p; }
inline lint invm(lint a, lint p = mod) { a %= p; return a == 1 ? 1 : -p / a * invm(p % a) % p; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  struct cell { int v, i, j; };
  V<cell> a(n * m);
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    int v; cin >> v;
    a[i * m + j] = {v, i, j};
  }
  int r, c; cin >> r >> c, r--, c--;
  sort(a.begin(), a.end(), [](cell x, cell y) { return x.v < y.v; });  
  lint dp = 0, cdp = 0, tdp = 0, cii = 0, tii = 0, ci = 0, ti = 0, cjj = 0, tjj = 0, cj = 0, tj = 0;
  int k = 0, tk = 0;
  for (int i = 0; i < n * m; i++) {
    if (k) dp = ((cdp + cii - 2 * a[i].i * ci + cjj - 2 * a[i].j * cj) % mod * invm(k) + a[i].i * a[i].i + a[i].j * a[i].j) % mod;
    if (a[i].i == r and a[i].j == c) return cout << emod(dp) << '\n', 0;
    tdp += dp;
    tii += a[i].i * a[i].i;
    ti += a[i].i;
    tjj += a[i].j * a[i].j;
    tj += a[i].j;
    tk++;
    if (i < n * m - 1 and a[i].v != a[i + 1].v) {
      (cdp += tdp) %= mod, tdp = 0;
      (cii += tii) %= mod, tii = 0;
      (ci += ti) %= mod, ti = 0;
      (cjj += tjj) %= mod, tjj = 0;
      (cj += tj) %= mod, tj = 0;
      k += tk, tk = 0;
    }
  }
}