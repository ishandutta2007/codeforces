#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> adj(n + 1);
  vector<int> p(n + 1);
  vector<int> s(n + 1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
    adj[p[i]].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  long long ans = 0;
  function<void(int)> dfs = [&](int x) {
    if (s[x] == -1) {
      if (adj[x].empty()) {
        s[x] = s[p[x]];
      } else {
        s[x] = INT_MAX;
        for (auto y : adj[x]) {
          s[x] = min(s[x], s[y]);
        }
      }
    }
    if (s[x] < s[p[x]]) {
      cout << -1 << "\n";
      exit(0);
    }
    ans += s[x] - s[p[x]];
    for (auto y : adj[x]) {
      dfs(y);
    }
  };
  dfs(1);
  cout << ans << "\n";
  return 0;
}