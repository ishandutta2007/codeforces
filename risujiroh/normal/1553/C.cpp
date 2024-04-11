#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> f(1 << 10, -1);
  for (int mask = 0; mask < 1 << 10; ++mask) {
    int a = 0, b = 0;
    int x = 5, y = 5;
    for (int i = 0; i < 10; ++i) {
      if (~i & 1) {
        a += mask >> i & 1;
        --x;
      } else {
        b += mask >> i & 1;
        --y;
      }
      if (a + x < b) {
        f[mask] = i + 1;
        break;
      }
      if (b + y < a) {
        f[mask] = i + 1;
        break;
      }
    }
    if (f[mask] == -1) {
      assert(a == b);
      f[mask] = 10;
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int ans = 1e9;
    for (int mask = 0; mask < 1 << 10; ++mask) {
      bool match = true;
      for (int i = 0; i < 10; ++i) {
        if (mask >> i & 1 && s[i] == '0') match = false;
        if (~mask >> i & 1 && s[i] == '1') match = false;
      }
      if (match) ans = min(ans, f[mask]);
    }
    cout << ans << '\n';
  }
}