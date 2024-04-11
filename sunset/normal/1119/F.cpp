#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> adj(n);
  long long everything = 0;
  for (int i = 0; i < n - 1; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    --from;
    --to;
    adj[from].emplace_back(to, cost);
    adj[to].emplace_back(from, cost);
    everything += cost;
  }
  for (int i = 0; i < n; ++i) {
    sort(adj[i].begin(), adj[i].end(), [&](pair<int, int> a, pair<int, int> b) {
      return adj[a.first].size() < adj[b.first].size();
    });
  }
  vector<int> interesting(n);
  for (int i = 0; i < n; ++i) {
    interesting[i] = i;
  }
  sort(interesting.begin(), interesting.end(), [&](int a, int b) {
    return adj[a].size() > adj[b].size();
  });
  vector<multiset<int>> costs(n);
  vector<long long> foo(n);
  vector<long long> bar(n);
  vector<long long> baz(n);
  vector<int> visit(n, -1);
  vector<int> ptr(n);
  cout << everything;
  for (int d = 1; d < n; ++d) {
    function<void(int, int)> dfs = [&](int x, int p) {
      visit[x] = d;
      while (ptr[x] < (int) adj[x].size() && (int) adj[adj[x][ptr[x]].first].size() <= d) {
        baz[x] += adj[x][ptr[x]].second;
        costs[x].insert(adj[x][ptr[x]++].second);
      }
      while ((int) costs[x].size() > (int) adj[x].size() - d) {
        baz[x] -= *--costs[x].end();
        costs[x].erase(--costs[x].end());
      }
      vector<int> insert, erase;
      long long sum = 0;
      for (int i = ptr[x]; i < (int) adj[x].size(); ++i) {
        int y = adj[x][i].first;
        if (y != p) {
          dfs(y, x);
          sum += foo[y];
          insert.push_back(bar[y] + adj[x][i].second - foo[y]);
          baz[x] += bar[y] + adj[x][i].second - foo[y];
          costs[x].insert(bar[y] + adj[x][i].second - foo[y]);
        }
      }
      while ((int) costs[x].size() > (int) adj[x].size() - d) {
        if (*--costs[x].end() <= 0) {
          break;
        }
        erase.push_back(*--costs[x].end());
        baz[x] -= *--costs[x].end();
        costs[x].erase(--costs[x].end());
      }
      foo[x] = bar[x] = baz[x] + sum;
      if (!costs[x].empty()) {
        bar[x] -= max(0, *--costs[x].end());
      }
      for (auto c : erase) {
        baz[x] += c;
        costs[x].insert(c);
      }
      for (auto c : insert) {
        baz[x] -= c;
        costs[x].erase(costs[x].find(c));
      }
    };
    long long ans = 0;
    for (auto x : interesting) {
      if ((int) adj[x].size() <= d) {
        break;
      }
      if (visit[x] != d) {
        dfs(x, -1);
        ans += foo[x];
      }
    }
    cout << " " << ans;
  }
  cout << "\n";
  return 0;
}