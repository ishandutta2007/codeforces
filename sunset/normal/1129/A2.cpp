#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n), near(n, n);
  while (m--) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    ++cnt[x];
    near[x] = min(near[x], (y + n - x) % n);
  }
  for (int i = 0; i < n; ++i) {
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      if (cnt[j]) {
        ans = max(ans, (j + n - i) % n + near[j] + (cnt[j] - 1) * n);
      }
    }
    if (i) {
      cout << " ";
    }
    cout << ans;
  }
  cout << "\n";
  return 0;
}