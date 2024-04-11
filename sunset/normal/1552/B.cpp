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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> a[i][j];
      }
    }
    auto better = [&](int i, int j) {
      int cnt = 0;
      for (int k = 0; k < 5; ++k) {
        if (a[i][k] < a[j][k]) {
          ++cnt;
        }
      }
      return cnt >= 3;
    };
    int best = 0;
    for (int i = 1; i < n; ++i) {
      if (better(i, best)) {
        best = i;
      }
    }
    bool none = false;
    for (int i = 0; i < n; ++i) {
      if (i != best && better(i, best)) {
        none = true;
        break;
      }
    }
    if (none) {
      cout << -1 << "\n";
      continue;
    }
    cout << best + 1 << "\n";
  }
  return 0;
}