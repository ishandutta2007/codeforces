#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e5;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<int> need(n);
  long long sum = 0;
  for (int i = 0; i + 1 < n; ++i) {
    need[i] = b[i] - a[i] - (i ? need[i - 1] : 0);
    sum += abs(need[i]);
  }
  if (b[n - 1] - a[n - 1] - need[n - 2] != 0) {
    cout << -1 << "\n";
    return 0;
  }
  cout << sum << "\n";
  vector<pair<int, int>> ans;
  function<void(int)> dfs = [&](int x) {
    if (need[x] > 0) {
      if (a[x + 1] == '9') {
        dfs(x + 1);
      }
      ++a[x];
      ++a[x + 1];
      --need[x];
      ans.emplace_back(x, 1);
    } else {
      if (a[x + 1] == '0') {
        dfs(x + 1);
      }
      --a[x];
      --a[x + 1];
      ++need[x];
      ans.emplace_back(x, -1);
    }
  };
  for (int i = 0; i + 1 < n; ++i) {
    while (need[i] && (int) ans.size() < MAX) {
      dfs(i);
    }
  }
  if ((int) ans.size() > MAX) {
    ans.resize(MAX);
  }
  for (auto p : ans) {
    cout << p.first + 1 << " " << p.second << "\n";
  }
  return 0;
}