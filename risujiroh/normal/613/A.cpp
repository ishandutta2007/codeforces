#include <bits/extc++.h>

#ifndef DUMP
#define DUMP(...) (void)0
#endif

using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << fixed << setprecision(20);
  using ld = double;
  int n;
  cin >> n;
  ld a, b;
  cin >> a >> b;
  vector<ld> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  x.push_back(x[0]);
  y.push_back(y[0]);
  ld mn = numeric_limits<ld>::max(), mx = -mn;
  for (int i = 0; i < n; ++i) {
    auto f = [&](ld m) {
      return hypot(x[i] + m * (x[i + 1] - x[i]) - a,
                   y[i] + m * (y[i + 1] - y[i]) - b);
    };
    ld l = 0, r = 1;
    for (int _ = 100; _--;) {
      ld ml = (2 * l + r) / 3, mr = (l + 2 * r) / 3;
      if (f(ml) < f(mr))
        r = mr;
      else
        l = ml;
    }
    mn = min(mn, f(l));
    mx = max({mx, f(0), f(1)});
  }
  cout << acosl(-1) * (mx * mx - mn * mn) << '\n';
}