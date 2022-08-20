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
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    bool ans = false;
    for (int i = 0; i < n; ++i) {
      bool valid = true;
      for (int j = 0; j < n; ++j) {
        if (abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) {
          valid = false;
          break;
        }
      }
      if (valid) {
        ans = true;
      }
    }
    cout << (ans ? 1 : -1) << "\n";
  }
  return 0;
}