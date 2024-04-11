#include <bits/stdc++.h>

using namespace std;

bool solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  string color;
  cin >> color;
  if (n <= 2) {
    return false;
  }
  if (n == 3) {
    int white = 0;
    for (int i = 0; i < n; ++i) {
      if (color[i] == 'W') {
        ++white;
      }
    }
    return white >= 2;
  }
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() >= 4 || (adj[i].size() >= 2 && color[i] == 'W')) {
      return true;
    }
  }
  bool is_chain = true;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 3) {
      is_chain = false;
      int cnt = 0;
      for (auto j : adj[i]) {
        if (adj[j].size() >= 2) {
          ++cnt;
        }
      }
      if (cnt >= 2) {
        return true;
      }
    }
  }
  if (is_chain) {
    int white = 0;
    for (int i = 0; i < n; ++i) {
      if (color[i] == 'W') {
        ++white;
      }
    }
    return white == 2 && n % 2 == 1;
  } else {
    int leaves = 0;
    for (int i = 0; i < n; ++i) {
      if (adj[i].size() == 1) {
        ++leaves;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (color[i] == 'W' && adj[adj[i][0]].size() == 3) {
        return true;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (color[i] == 'W' && n % 2 == 0) {
        return true;
      }
    }
    if (leaves == 4 && n % 2 == 1) {
      return true;
    }
  }
  return false;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; ++qq) {
    cout << (solve() ? "White" : "Draw") << "\n";
  }
  return 0;
}