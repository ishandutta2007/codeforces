#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  vector<vector<int>> adj_a(n), adj_b(n);
  while (m--) {
    int from, to, cost;
    cin >> from >> to >> cost;
    --from;
    --to;
    if (cost == a) {
      adj_a[from].push_back(to);
      adj_a[to].push_back(from);
    } else {
      adj_b[from].push_back(to);
      adj_b[to].push_back(from);
    }
  }
  vector<int> who(n, -1);
  vector<int> id(n, -1);
  int big = 0;
  for (int i = 0; i < n; ++i) {
    if (id[i] == -1) {
      vector<int> order;
      order.push_back(i);
      id[i] = 1 << big;
      who[i] = i;
      for (int j = 0; j < (int) order.size(); ++j) {
        int x = order[j];
        for (auto y : adj_a[x]) {
          if (id[y] == -1) {
            id[y] = 1 << big;
            who[y] = i;
            order.push_back(y);
          }
        }
      }
      if ((int) order.size() >= 4) {
        big++;
      } else {
        for (auto x : order) {
          id[x] = 0;
        }
      }
    }
  }
  vector<vector<int>> dist(1 << big, vector<int>(n, inf));
  priority_queue<pair<int, pair<int, int>>> q;
  auto extend = [&](int s, int x, int d) {
    if (dist[s][x] > d) {
      dist[s][x] = d;
      q.emplace(-d, make_pair(s, x));
    }
  };
  extend(id[0], 0, 0);
  while (!q.empty()) {
    int s = q.top().second.first, x = q.top().second.second;
    q.pop();
    for (auto y : adj_a[x]) {
      extend(s, y, dist[s][x] + a);
    }
    for (auto y : adj_b[x]) {
      if (who[x] != who[y] && !(s & id[y])) {
        extend(s | id[y], y, dist[s][x] + b);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    int ans = inf;
    for (int j = 0; j < 1 << big; ++j) {
      ans = min(ans, dist[j][i]);
    }
    if (i) {
      cout << " ";
    }
    cout << ans;
  }
  cout << "\n";
  return 0;
}