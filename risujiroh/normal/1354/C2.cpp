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
  constexpr double pi = acos(-1);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    double r = 1 / (2 * sin(pi / (2 * n)));
    double th = pi / n * ((n + 1) / 4);
    double res = r * (cos(th) + sin(th));
    res *= sqrt(2);
    cout << res << '\n';
  }
}