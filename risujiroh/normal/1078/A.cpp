#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  double a, b, c; cin >> a >> b >> c;
  V<double> x(6), y(6);
  cin >> x[0] >> y[0] >> x[5] >> y[5];
  double res;
  if (a * b == 0) res = abs(x[5] - x[0]) + abs(y[5] - y[0]);
  else {
    VV<double> d; assign(d, 6, 6, 1e10);
    for (int i = 0; i < 6; ++i) d[i][i] = 0;
    x[1] = x[0], y[1] = (-c - a * x[0]) / b;
    x[2] = (-c - b * y[0]) / a, y[2] = y[0];
    x[3] = x[5], y[3] = (-c - a * x[5]) / b;
    x[4] = (-c - b * y[5]) / a, y[4] = y[5];
    for (int i : {1, 2}) d[0][i] = d[i][0] = hypot(x[i] - x[0], y[i] - y[0]);
    for (int i : {3, 4}) d[5][i] = d[i][5] = hypot(x[i] - x[5], y[i] - y[5]);
    for (int i = 1; i < 5; ++i) for (int j = 1; j < 5; ++j) if (i != j) {
      d[i][j] = d[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
    }
    for (int k = 0; k < 6; ++k) for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j) {
      d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    res = d[0][5];
  }
  res = min(res, abs(x[5] - x[0]) + abs(y[5] - y[0]));
  cout << fixed << setprecision(15) << res << '\n';
  for (int i = 1; i < 5; ++i) {
    cerr << x[i] << ' ' << y[i] << '\n';
  }
}