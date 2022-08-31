#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> parent(n, -1), depth(n);
  int pa = min_element(a.begin(), a.end()) - a.begin();
  int pb = min_element(b.begin(), b.end()) - b.begin();
  
  function<void(int)> dfs = [&](int x) {
    for (auto y : adj[x]) {
      if (y != parent[x]) {
        depth[y] = depth[x] + 1;
        parent[y] = x;
        dfs(y);
      }
    }
  };

  dfs(pb);
  long long answer = 0;
  for (int i = pa; ~parent[i]; i = parent[i]) {
    swap(a[i], a[parent[i]]);
    ++answer;
  }

  auto no_solution = [&]() {
    cout << -1 << endl;
    exit(0);
  };

  int p = -1, q = -1, s = -1, t = -1;
  vector<int> cycle;

  auto find_cycle = [&]() {
    vector<bool> visit(n);
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] && (!~p || depth[i] > depth[p])) {
        p = i;
      }
    }
    if (!~p) {
      cout << 0 << " " << answer << endl;
      exit(0);
    }
    for (int i = p; a[i] != b[i]; i = parent[i]) {
      visit[i] = true;
      cycle.push_back(i);
      s = parent[i];
    }
    reverse(cycle.begin(), cycle.end());
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] && (!~q || depth[i] > depth[q]) && !visit[i]) {
        q = i;
      }
    }
    if (~q) {
      for (int i = q; a[i] != b[i]; i = parent[i]) {
        visit[i] = true;
        cycle.push_back(i);
        t = parent[i];
      }
    } else {
      q = t = parent[cycle[0]];
    }
    if (s != t || cycle.size() != depth[p] + depth[q] - (depth[s] << 1)) {
      no_solution();
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] && !visit[i]) {
        no_solution();
      }
    }
  };

  find_cycle();
  int diff = 0;
  for (int i = 0; i < cycle.size(); ++i) {
    if (b[cycle[i]] == a[cycle[0]]) {
      diff = i;
    }
  }
  for (int i = 0; i < cycle.size(); ++i) {
    if (b[cycle[(i + diff) % cycle.size()]] != a[cycle[i]]) {
      no_solution();
    }
  }

  vector<bool> visit(n);
  for (int i = pa; ~i; i = parent[i]) {
    visit[i] = true;
  }
  int pos = 0;
  if (!visit[cycle[0]]) {
    reverse(cycle.begin(), cycle.end());
    diff = cycle.size() - diff;
  }
  if (visit[cycle[0]]) {
    pos = cycle.size();
    for (int i = 0; i < cycle.size(); ++i) {
      if (!visit[cycle[i]]) {
        pos = i;
        break;
      }
    }
  }
  answer += min((long long)diff * ((int)cycle.size() + 1), (long long)((int)cycle.size() - diff) * ((int)cycle.size() + 1) - (pos << 1));

  for (int i = s; !visit[i]; i = parent[i]) {
    answer += 2;
  }
  if (p > q) {
    swap(p, q);
  }
  cout << p + 1 << " " << q + 1 << " " << answer << endl;

  return 0;
}