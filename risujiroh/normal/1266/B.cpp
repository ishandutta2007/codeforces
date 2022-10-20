#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;
    bool ok = [&] {
      if (x < 15) {
        return false;
      }
      x %= 14;
      if (1 <= x and x <= 6) {
        return true;
      }
      return false;
    }();
    cout << (ok ? "YES" : "NO") << '\n';
  }
}