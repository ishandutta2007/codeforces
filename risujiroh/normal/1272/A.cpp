#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  while (q--) {
    long long a[3];
    for (int i = 0; i < 3; ++i) {
      cin >> a[i];
    }
    long long res = 1e18;
    for (int k = 0; k < 27; ++k) {
      long long na[3];
      int t = k;
      for (int i = 0; i < 3; ++i) {
        na[i] = a[i];
        if (t % 3 == 0) {
          ++na[i];
        } else if (t % 3 == 1) {
          --na[i];
        }
        t /= 3;
      }
      long long crr = 0;
      for (int i = 0; i < 3; ++i) {
        crr += abs(na[i] - na[(i + 1) % 3]);
      }
      res = min(res, crr);
    }
    cout << res << '\n';
  }
}