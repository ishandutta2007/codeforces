#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (int) ((long long) x * y % md);
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  int ans = 0;
  for (int m = 1; m < n; ++m) {
    vector<vector<pair<int, int>>> adj(n + m);
    for (int i = 0; i < n - 1 - i; ++i) {
      adj[i].emplace_back(n - 1 - i, 0);
      adj[n - 1 - i].emplace_back(i, 0);
    }
    for (int i = 0; i < m - 1 - i; ++i) {
      adj[n + i].emplace_back(n + m - 1 - i, 0);
      adj[n + m - 1 - i].emplace_back(n + i, 0);
    }
    for (int i = 0; i < m; ++i) {
      if (s[n - 1 - i] != '?') {
        adj[n - 1 - i].emplace_back(n + m - 1 - i, s[n - 1 - i] == '1');
        adj[n + m - 1 - i].emplace_back(n - 1 - i, s[n - 1 - i] == '1');
      }
    }
    adj[0].emplace_back(n, 0);
    adj[n].emplace_back(0, 0);
    for (int i = 0; i < n - m; ++i) {
      if (s[i] != '?') {
        adj[0].emplace_back(i, s[i] == '0');
        adj[i].emplace_back(0, s[i] == '0');
      }
    }
    vector<int> color(n + m, -1);
    bool valid = true;
    int cnt = 0;
    function<bool(int)> dfs = [&](int x) {
      for (auto p : adj[x]) {
        int y = p.first, w = p.second;
        if (color[y] == -1) {
          color[y] = color[x] ^ w;
          if (!dfs(y)) {
            return false;
          }
        } else if (color[y] != (color[x] ^ w)) {
          return false;
        }
      }
      return true;
    };
    for (int i = 0; i < n + m; ++i) {
      if (color[i] == -1) {
        color[i] = 0;
        ++cnt;
        if (!dfs(i)) {
          valid = false;
          break;
        }
      }
    }
    --cnt;
    if (valid) {
      int ways = 1;
      for (int i = 0; i < cnt; ++i) {
        ways = mul(ways, 2);
      }
      add(ans, ways);
    }
  }
  cout << ans << "\n";
  return 0;
}