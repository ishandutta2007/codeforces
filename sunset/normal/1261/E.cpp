#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> ans(n, vector<int>(n + 1, -1));
  vector<vector<int>> groups(1);
  for (int i = 0; i <= n; ++i) {
    groups[0].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int y = min(x, n + 1 - x);
    for (auto g : groups) {
      if ((int) g.size() > 1) {
        if (y) {
          ans[i][g[0]] = 1;
          ans[i][g[1]] = 0;
          y--;
          x--;
        }
      }
    }
    vector<vector<int>> new_groups;
    for (auto g : groups) {
      vector<int> zero;
      vector<int> one;
      for (int p : g) {
        if (ans[i][p] == -1) {
          if (x > 0) {
            ans[i][p] = 1;
            x--;
          } else {
            ans[i][p] = 0;
          }
        }
        if (ans[i][p] == 1) {
          one.push_back(p);
        } else {
          zero.push_back(p);
        }
      }
      if (!zero.empty()) {
        new_groups.push_back(zero);
      }
      if (!one.empty()) {
        new_groups.push_back(one);
      }
    }
    swap(groups, new_groups);
  }
  cout << n + 1 << "\n";
  for (int i = 0; i < n + 1; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[j][i];
    }
    cout << "\n";
  }
  return 0;
}