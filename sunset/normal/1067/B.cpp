#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  
  auto no_solution = [&]() {
    cout << "No" << endl;
    exit(0);
  };

  if (n == 1) {
    no_solution();
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int s = -1;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 1) {
      s = i;
      break;
    }
  }
  vector<int> depth(n, 0), parent(n, -1);
  
  function<void(int)> dfs = [&](int x) {
    for (auto y : adj[x]) {
      if (y != parent[x]) {
        depth[y] = depth[x] + 1;
        parent[y] = x;
        dfs(y);
      }
    }
  };

  dfs(s);
  int t = max_element(depth.begin(), depth.end()) - depth.begin();
  if (depth[t] < m) {
    no_solution();
  }

  function<void(int, int)> solve = [&](int x, int parent) {
    int size = 0;
    for (auto y : adj[x]) {
      if (y != parent) {
        depth[y] = depth[x] + 1;
        solve(y, x);
        ++size;
      }
    }
    if (!size) {
      if (depth[x] != m) {
        no_solution();
      }
    } else if (size < 3) {
      no_solution();
    }
  };

  for (int i = 0; i < m; ++i) {
    t = parent[t];
  }
  depth[t] = 0;
  solve(t, -1);
  cout << "Yes" << endl;
  return 0;
}