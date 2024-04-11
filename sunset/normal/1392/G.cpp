#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  string s, t;
  cin >> n >> m >> k >> s >> t;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i]; --b[i];
  }
  vector<vector<int>> p(n + 1, vector<int>(k));
  for (int i = 0; i < k; ++i) {
    p[n][i] = i;
  }
  for (int i = n - 1; ~i; --i) {
    p[i] = p[i + 1];
    for (int j = 0; j < k; ++j) {
      if (p[i][j] == a[i]) {
        p[i][j] = b[i];
      } else if (p[i][j] == b[i]) {
        p[i][j] = a[i];
      }
    }
  }
  vector<vector<int>> q(n + 1, vector<int>(k));
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j < k; ++j) {
      q[i][p[i][j]] = j;
    }
  }
  vector<pair<int, int>> dist(1 << k, make_pair(k + 1, -1));
  queue<int> que;
  auto update = [&](int v, pair<int, int> w) {
    if (dist[v] > w) {
      dist[v] = w;
      que.push(v);
    }
  };
  int ans = k + 1;
  pair<int, int> interval;
  for (int i = m; i <= n; ++i) {
    int u = 0;
    for (int j = 0; j < k; ++j) {
      if (s[p[i - m][j]] == '1') {
        u |= 1 << j;
      }
    }
    update(u, make_pair(0, i - m));
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int j = 0; j < k; ++j) {
        update(u ^ (1 << j), make_pair(dist[u].first + 1, i - m));
      }
    }
    u = 0;
    for (int j = 0; j < k; ++j) {
      if (t[p[i][j]] == '1') {
        u |= 1 << j;
      }
    }
    if (ans > dist[u].first) {
      ans = dist[u].first;
      interval = make_pair(dist[u].second, i);
    }
  }
  cout << k - ans << "\n";
  cout << interval.first + 1 << " " << interval.second << "\n";
  return 0;
}