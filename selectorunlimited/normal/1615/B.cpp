#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (l == r) {
      cout << 0 << endl;
      continue;
    }
    int l1 = l, r1 = r;
    int mx = 0, mn = 0;
    int ans = 0;
    while (r1 > 0) {
      r1 /= 2;
      ans++;
    }
    while (l1 > 0) {
      l1 /= 2;
      mn++;
    }
    while (ans != mn) {
      ans--;
      mx = pow(2, ans);
    }
    int x = 0, y = 0, z = 0;
    int b = 0;
    while (l <= r) {
      if (l & mx) {
        x++;
      }
      if (!(l & mx)) {
        y++;
      }
      if (l & mx && !l & (mx / 2)) {
        z++;
      }
      l++;
      b++;
    }
    if (b == 2) {
      cout << min(x, y) << endl;
    } else {
      cout << min(x, y) + z << endl;
    }
  }
  return 0;
}