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
  vector<vector<int>> adj(n);
  vector<int> from(n - 1);
  vector<int> to(n - 1);
  vector<int> cost(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> from[i] >> to[i] >> cost[i];
    --from[i];
    --to[i];
    adj[from[i]].push_back(to[i]);
    adj[to[i]].push_back(from[i]);
  }
  for (int i = 0; i < n; ++i) {
    if ((int) adj[i].size() == 2) {
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES" << "\n";
  vector<vector<int>> ans;
  for (int i = 0; i < n - 1; ++i) {
    auto get = [&](int x, int y) {
      if ((int) adj[x].size() == 1) {
        return vector<int>{x};
      } else {
        vector<int> v;
        for (auto z : adj[x]) {
          if (z != y) {
            int p = x;
            while ((int) adj[z].size() != 1) {
              for (auto u : adj[z]) {
                if (u != p) {
                  p = z;
                  z = u;
                  break;
                }
              }
            }
            v.push_back(z);
            if ((int) v.size() == 2) {
              break;
            }
          }
        }
        return v;
      }
    };
    vector<int> foo = get(from[i], to[i]);
    vector<int> bar = get(to[i], from[i]);
    if (foo.size() < bar.size()) {
      swap(foo, bar);
    }
    if ((int) foo.size() == 1) {
      ans.push_back({foo[0], bar[0], cost[i]});
    } else if ((int) bar.size() == 1) {
      ans.push_back({foo[0], bar[0], cost[i] / 2});
      ans.push_back({foo[1], bar[0], cost[i] / 2});
      ans.push_back({foo[0], foo[1], -cost[i] / 2});
    } else {
      ans.push_back({foo[0], bar[0], cost[i] / 2});
      ans.push_back({foo[1], bar[1], cost[i] / 2});
      ans.push_back({foo[0], foo[1], -cost[i] / 2});
      ans.push_back({bar[0], bar[1], -cost[i] / 2});
    }
  }
  cout << ans.size() << "\n";
  for (auto v : ans) {
    cout << v[0] + 1 << " " << v[1] + 1 << " " << v[2] << "\n";
  }
  return 0;
}