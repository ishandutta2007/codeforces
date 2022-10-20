#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


bool recl(int v, int l, const V<>& a, VV<>& memol, VV<>& memor, const VV<>& gcd);
bool recr(int v, int r, const V<>& a, VV<>& memol, VV<>& memor, const VV<>& gcd);

bool recl(int v, int l, const V<>& a, VV<>& memol, VV<>& memor, const VV<>& gcd) {
  if (memol[v][l] != -1) return memol[v][l];
  if (l == v) return memol[v][l] = true;
  for (int x = l; x < v; ++x) if (gcd[v][x] > 1) {
    if (recl(x, l, a, memol, memor, gcd) and recr(x, v, a, memol, memor, gcd)) return memol[v][l] = true;
  }
  return memol[v][l] = false;
}

bool recr(int v, int r, const V<>& a, VV<>& memol, VV<>& memor, const VV<>& gcd) {
  if (memor[v][r] != -1) return memor[v][r];
  if (r == v + 1) return memor[v][r] = true;
  for (int x = v + 1; x < r; ++x) if (gcd[v][x] > 1) {
    if (recl(x, v + 1, a, memol, memor, gcd) and recr(x, r, a, memol, memor, gcd)) return memor[v][r] = true;
  }
  return memor[v][r] = false;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  VV<> memol, memor; assign(memol, n, n, -1); assign(memor, n, n + 1, -1);
  VV<> gcd; assign(gcd, n, n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) gcd[i][j] = __gcd(a[i], a[j]);
  for (int x = 0; x < n; ++x) if (recl(x, 0, a, memol, memor, gcd) and recr(x, n, a, memol, memor, gcd)) return cout << "Yes" << '\n', 0;
  cout << "No" << '\n';
}