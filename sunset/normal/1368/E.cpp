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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
      int x, y;
      cin >> x >> y;
      x--; y--;
      g[y].push_back(x);
    }
    vector<int> dp(n);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      for (int j : g[i]) {
        if (dp[j] < 2) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      if (dp[i] == 2) {
        ans.push_back(i);
      }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < (int) ans.size(); ++i) {
      if (i) {
        cout << " ";
      }
      cout << ans[i] + 1;
    }
    cout << "\n";
  }
  return 0;
}