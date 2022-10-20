#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int x = 0x3f3f3f3f, y = 0;
    bool ok = true;
    while (n--) {
      int a;
      cin >> a;
      if (not ok) continue;
      if (a < y) {
        ok = false;
        continue;
      }
      x = min(x, a - y);
      y = a - x;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}