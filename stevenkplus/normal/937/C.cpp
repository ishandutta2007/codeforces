#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {
  ld k, d, t;
  cin >> k >> d >> t;
  d = ceil(k / d) * d;
  ld cook = k + (d - k) / 2;
  ld rounds = floor(t / cook);
  ld left = t - rounds * cook;
  ld ans = rounds * d;

  if (left < k) {
    ans += left;
  } else {
    ans += k + (left - k) * 2;
  }

  cout << setprecision(10) << fixed << ans << "\n";
}