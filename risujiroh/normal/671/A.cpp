#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int ax, ay, bx, by, tx, ty;
  cin >> ax >> ay >> bx >> by >> tx >> ty;
  int n;
  cin >> n;
  vector<double> p(n), q(n);
  double res = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    p[i] = hypot(x - ax, y - ay) - hypot(x - tx, y - ty);
    q[i] = hypot(x - bx, y - by) - hypot(x - tx, y - ty);
    res += 2 * hypot(x - tx, y - ty);
  }
  double mn = min(*min_element(begin(p), end(p)), *min_element(begin(q), end(q)));
  vector<double> cuml(n + 1), cumr(n + 1);
  for (int i = 0; i < n; ++i) {
    cuml[i + 1] = min(cuml[i], q[i]);
  }
  for (int i = n; i--; ) {
    cumr[i] = min(q[i], cumr[i + 1]);
  }
  for (int i = 0; i < n; ++i) {
    mn = min(mn, p[i] + min(cuml[i], cumr[i + 1]));
  }
  res += mn;
  cout << res << '\n';
}