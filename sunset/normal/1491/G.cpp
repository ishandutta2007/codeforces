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
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<int>> cycles;
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && i != p[i]) {
      int j = i;
      vector<int> cycle;
      while (!vis[j]) {
        vis[j] = true;
        cycle.push_back(j);
        j = p[j];
      }
      cycles.push_back(cycle);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i + 1 < (int) cycles.size(); i += 2) {
    vector<int> foo = cycles[i];
    vector<int> bar = cycles[i + 1];
    for (int j = 0; j < (int) bar.size(); ++j) {
      ans.emplace_back(foo[0], bar[j]);
    }
    for (int j = 1; j < (int) foo.size(); ++j) {
      ans.emplace_back(foo[j], bar[0]);
    }
    ans.emplace_back(foo[0], bar[0]);
  }
  if ((int) cycles.size() % 2 == 1) {
    vector<int> foo = cycles.back();
    if ((int) foo.size() == 2) {
      int bar = 0;
      while (bar == foo[0] || bar == foo[1]) {
        bar++;
      }
      ans.emplace_back(foo[0], bar);
      ans.emplace_back(foo[1], bar);
      ans.emplace_back(foo[0], bar);
    } else {
      for (int i = 1; i < (int) foo.size() - 1; ++i) {
        ans.emplace_back(foo[0], foo[i]);
      }
      ans.emplace_back(foo[1], foo.back());
      ans.emplace_back(foo[0], foo.back());
      ans.emplace_back(foo[0], foo[1]);
    }
  }
  cout << ans.size() << "\n";
  for (auto q : ans) {
    cout << q.first + 1 << " " << q.second + 1 << "\n";
  }
  return 0;
}