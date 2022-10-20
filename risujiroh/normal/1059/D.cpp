#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr double eps = 5e-7;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<double> x(n), y(n); for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) if (y[0] * y[i] < 0) return cout << -1 << '\n', 0;
  if (y[0] < 0) for (int i = 0; i < n; i++) y[i] *= -1;
  auto chk = [&](double rad) {
    double l_max = -1e10, r_min = 1e10;
    for (int i = 0; i < n; i++) {
      double d = y[i] * (2 * rad - y[i]);
      if (d < eps) return false;
      l_max = max(l_max, x[i] - sqrt(d));
      r_min = min(r_min, x[i] + sqrt(d));
    }
    return l_max - r_min < eps;
  };
  double ng = 0, ok = 1e20;
  while ((ok - ng) / max(1.0, ok) > eps) {
    double mid = (ng + ok) / 2;
    if (chk(mid)) ok = mid;
    else ng = mid;
  }
  cout << fixed << setprecision(15) << ok << '\n';
}