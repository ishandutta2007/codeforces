#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long n, a, b;
    cin >> n >> a >> b;
    auto chk = [&](long long x) {
      long long s = x / (a + b) * a;
      x %= a + b;
      s += min(x, a);
      return 2 * s >= n;
    };
    long long ng = n - 1, ok = 2e18;
    while (ok - ng > 1) {
      long long mid = (ng + ok) / 2;
      (chk(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}