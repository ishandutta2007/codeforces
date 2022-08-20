#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == -1) {
        a[i] = i + 1;
      } else {
        --a[i];
      }
      adj[a[i]].push_back(i);
    }
    vector<int> ans(n + 1);
    int cur = n;
    function<void(int)> dfs = [&](int x) {
      ans[x] = cur--;
      for (auto y : adj[x]) {
        dfs(y);
      }
    };
    dfs(n);
    vector<int> s(1, n);
    bool valid = true;
    for (int i = n - 1; ~i; --i) {
      while (ans[i] > ans[s.back()]) {
        s.pop_back();
      }
      if (s.back() != a[i]) {
        valid = false;
        break;
      }
      s.push_back(i);
    }
    if (valid) {
      for (int i = 0; i < n; ++i) {
        if (i) {
          cout << " ";
        }
        cout << ans[i] + 1;
      }
      cout << "\n";
    } else {
      cout << -1 << "\n";
    }
  }
  return 0;
}