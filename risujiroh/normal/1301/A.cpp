#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size();
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (c[i] != a[i] and c[i] != b[i]) {
        ok = false;
        break;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}