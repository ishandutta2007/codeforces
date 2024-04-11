#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      pos[a].push_back(i);
    }
    vector<int> ans(n, n + 1);
    for (int v = 1; v <= n; ++v) {
      if (empty(pos[v])) continue;
      pos[v].insert(begin(pos[v]), -1);
      pos[v].push_back(n);
      int mx{};
      for (int i = 1; i < int(size(pos[v])); ++i) {
        mx = max(mx, pos[v][i] - pos[v][i - 1] - 1);
      }
      ans[mx] = min(ans[mx], v);
    }
    for (int i = 0; i < n; ++i) {
      if (i) ans[i] = min(ans[i], ans[i - 1]);
      cout << (ans[i] <= n ? ans[i] : -1) << " \n"[i == n - 1];
    }
  }
}