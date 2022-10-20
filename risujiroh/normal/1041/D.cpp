#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, h; cin >> n >> h;
  V<lint> xl(n), xr(n); for (int i = 0; i < n; i++) cin >> xl[i] >> xr[i];
  V<lint> a(n);
  for (int i = 0; i < n - 1; i++) a[i] = xl[i + 1] - xr[i];
  a[n - 1] = 1e10;
  V<lint> ca(n + 1);
  for (int i = 0; i < n - 1; i++) ca[i + 1] = ca[i] + a[i];
  int res = 0;
  auto f = [&](int i) {
    int ok = i, ng = n;
    while (ng - ok > 1) {
      int m = (ok + ng) / 2;
      if (ca[m] < h + ca[i]) ok = m;
      else ng = m;
    }
    return ok - 1;
  };
  for (int i = 0; i < n; i++) {
    int tmp = 0;
    int j = f(i);
    tmp = xr[j + 1] - xl[i] + h - (ca[j + 1] - ca[i]);
    res = max(res, tmp);
  }
  cout << res << '\n';
}