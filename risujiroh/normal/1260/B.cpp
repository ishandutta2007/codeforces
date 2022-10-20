#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    bool ok = true;
    if ((a + b) % 3) {
      ok = false;
    }
    if (a > 2 * b) {
      ok = false;
    }
    if (b > 2 * a) {
      ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}