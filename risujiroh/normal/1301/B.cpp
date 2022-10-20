#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    int mn = 2e9, mx = -2e9;
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        if (i and a[i - 1] != -1) {
          mn = min(mn, a[i - 1]);
          mx = max(mx, a[i - 1]);
        }
        if (i < n - 1 and a[i + 1] != -1) {
          mn = min(mn, a[i + 1]);
          mx = max(mx, a[i + 1]);
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        a[i] = (mn + mx) / 2;
      }
    }
    int res = -2e9;
    for (int i = 0; i < n - 1; ++i) {
      res = max(res, abs(a[i + 1] - a[i]));
    }
    cout << res << ' ' << (mn + mx) / 2 << '\n';
  }
}