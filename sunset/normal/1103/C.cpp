#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> adj(n);
  vector<int> from(m), to(m);
  for (int i = 0; i < m; ++i) {
    cin >> from[i] >> to[i];
    --from[i];
    --to[i];
    adj[from[i]].emplace_back(to[i], i);
    adj[to[i]].emplace_back(from[i], i);
  }
  vector<bool> tree(m);
  vector<int> depth(n);
  vector<int> pr(n);
  vector<int> leaves;
  depth[0] = 1;
  pr[0] = -1;
  function<void(int)> dfs = [&](int x) {
    bool leaf = true;
    for (auto p : adj[x]) {
      if (!depth[p.first]) {
        tree[p.second] = true;
        leaf = false;
        depth[p.first] = depth[x] + 1;
        pr[p.first] = x;
        dfs(p.first);
      }
    }
    if (leaf) {
      leaves.push_back(x);
    }
  };
  dfs(0);
  auto get_path = [&](int x, int y) {
    vector<int> res;
    while (x != pr[y]) {
      res.push_back(x);
      x = pr[x];
    }
    return res;
  };
  for (auto x : leaves) {
    if ((long long) depth[x] * k >= n) {
      vector<int> ans = get_path(x, 0);
      cout << "PATH" << "\n";
      cout << ans.size() << "\n";
      for (int i = 0; i < ans.size(); ++i) {
        if (i) {
          cout << " ";
        }
        cout << ans[i] + 1;
      }
      cout << "\n";
      return 0;
    }
  }
  vector<vector<int>> up(n);
  for (int i = 0; i < m; ++i) {
    if (!tree[i]) {
      if (depth[from[i]] > depth[to[i]]) {
        up[from[i]].push_back(to[i]);
      } else {
        up[to[i]].push_back(from[i]);
      }
    }
  }
  cout << "CYCLES" << "\n";
  for (int i = 0; i < k; ++i) {
    int x = leaves[i], y = up[x][0], z = up[x][1];
    if (depth[y] < depth[z]) {
      swap(y, z);
    }
    vector<int> ans;
    if ((depth[x] - depth[y] + 1) % 3) {
      ans = get_path(x, y);
    } else if ((depth[x] - depth[z] + 1) % 3) {
      ans = get_path(x, z);
    } else {
      ans = get_path(y, z);
      ans.push_back(x);
      reverse(ans.begin(), ans.end());
    }
    cout << ans.size() << "\n";
    for (int j = 0; j < ans.size(); ++j) {
      if (j) {
        cout << " ";
      }
      cout << ans[j] + 1;
    }
    cout << "\n";
  }
  return 0;
}