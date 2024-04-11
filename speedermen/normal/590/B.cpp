#include <bits/stdc++.h>

using namespace std;

#define double long double

pair < double, double > st, fi, v, w;
double vmax, t, angX, angY;

double calc(pair <double, double> v, double t) {
  double l = 0, r = t, ans = 1e+40;
  while (abs(r - l) > 1e-9) {
    double m = (l + r) / 2;
    pair < double, double > cur = make_pair(fi.first - st.first - v.first * m, fi.second - st.second - v.second * m);
    if (hypotl(cur.first, cur.second) <= vmax * m) {
      ans = m;
      r = m;
    } else {
      l = m;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin >> st.first >> st.second >> fi.first >> fi.second;
  fi.first -= st.first;
  fi.second -= st.second;
  st = make_pair(0, 0);
  cin >> vmax >> t;
  cin >> v.first >> v.second >> w.first >> w.second;
  double l = calc(v, t);
  if (l <= t) {
    cout.precision(15);
    cout << fixed << l << '\n';
  } else {
    double ans = 1e+10;
    double pi = acos(-1.0);
    for (int s = 0, N = 4; s < N; ++s) {
        double l = 2 * pi / N * s, r = 2 * pi / N * (s + 1);
        while (abs(r - l) > 1e-9) {
          double dl = l + (r - l) / 3, dr = r - (r - l) / 3;
          double fl, fr;
          angX = vmax * sin(dl) + v.first;
          angY = vmax * cos(dl) + v.second;
          st = make_pair(angX * t, angY * t);
          fl = t + calc(w, 1e+10);
          angX = vmax * sin(dr) + v.first;
          angY = vmax * cos(dr) + v.second;
          st = make_pair(angX * t, angY * t);
          fr = t + calc(w, 1e+10);
          ans = min(ans, fl);
          ans = min(ans, fr);
          if (fl < fr) {
            r = dr;
          } else {
            l = dl;
          }
        }
    }
    cout.precision(15);
    cout << fixed << ans << endl;
  }
  return 0;
}