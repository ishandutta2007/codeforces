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
  vector<vector<int>> index(m);
  vector<vector<int>> take(m);
  vector<vector<int>> is(m);
  vector<bool> first(n, true);
  vector<int> free(m);
  for (int i = 0; i < m; ++i) {
    int s;
    cin >> s;
    for (int j = 0; j < s; ++j) {
      int p;
      cin >> p;
      index[i].push_back(--p);
      if (first[p]) {
        free[i]++;
        first[p] = false;
      } else {
        take[i].push_back(p);
        is[i].push_back(0);
      }
    }
  }
  if (n == 1) {
    cout << "ACCEPTED" << "\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (first[i]) {
      cout << "REJECTED" << "\n";
      return 0;
    }
  }
  vector<int> a(n, 0);
  function<void(int)> dfs = [&](int d) {
    if (d == m) {
      for (int i = 0; i < n - 1; ++i) {
        if (a[i] == 1 && a[i + 1] == 0) {
          cout << "REJECTED" << "\n";
          exit(0);
        }
      }
    } else {
      int zero = 0;
      for (int j = 0; j < (int) take[d].size(); ++j) {
        is[d][j] = a[take[d][j]];
        if (!is[d][j]) {
          ++zero;
        }
      }
      for (int more = 0; more <= free[d]; ++more) {
        for (int j = 0; j < zero + more; ++j) {
          a[index[d][j]] = 0;
        }
        for (int j = zero + more; j < (int) index[d].size(); ++j) {
          a[index[d][j]] = 1;
        }
        dfs(d + 1);
      }
      for (int j = 0; j < (int) take[d].size(); ++j) {
        a[take[d][j]] = is[d][j];
      }
    }
  };
  dfs(0);
  cout << "ACCEPTED" << "\n";
  return 0;
}