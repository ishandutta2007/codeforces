#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m, vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> ans;
  for (int i = 0; i < m; ++i) {
    ans.push_back(i);
  }
  for (int i = 0; i < n - 1; ++i) {
    vector<pair<int, int>> by;
    int s = 0;
    for (int j = 0; j < m; ++j) {
      s += a[j][n - 1] - a[j][i];
      by.emplace_back(a[j][i] - a[j][n - 1], j);
    }
    sort(by.begin(), by.end());
    for (int j = 0; j <= m; ++j) {
      if (s <= 0) {
        if ((int) ans.size() > j) {
          ans.clear();
          for (int k = 0; k < j; ++k) {
            ans.push_back(by[k].second);
          }
        }
        break;
      }
      s += by[j].first;
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
  return 0;
}