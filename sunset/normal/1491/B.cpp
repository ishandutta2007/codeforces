#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    bool found = false;
    for (int i = 0; i < n - 1; ++i) {
      if (abs(a[i] - a[i + 1]) > 1) {
        found = true;
      }
    }
    if (found) {
      cout << 0 << "\n";
      continue;
    }
    for (int i = 0; i < n - 1; ++i) {
      if (abs(a[i] - a[i + 1]) == 1) {
        found = true;
      }
    }
    if (found) {
      cout << min(u, v) << "\n";
      continue;
    }
    cout << v + min(u, v) << "\n";
  }
  return 0;
}