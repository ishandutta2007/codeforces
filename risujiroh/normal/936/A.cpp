#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  long long k, d, t;
  cin >> k >> d >> t;
  long long m = (k + d - 1) / d * d;
  long long a = (2 * t) / (2 * k + (m - k));
  double res = (double)a * m;
  double r = t - a * (k + 0.5 * (m - k));
  if (r < k + 1e-10) {
    res += r;
  } else {
    res += k + 2 * (r - k);
  }
  cout << res << '\n';
}