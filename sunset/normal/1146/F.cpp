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
  int n;
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    adj[--p].push_back(i);
  }
  vector<vector<int>> dp(n, vector<int>(2));
  for (int i = n - 1; ~i; --i) {
    if (adj[i].empty()) {
      dp[i][0] = dp[i][1] = 1;
    } else {
      vector<int> ways(3);
      ways[0] = 1;
      for (auto j : adj[i]) {
        vector<int> new_ways(3);
        for (int a = 0; a < 3; ++a) {
          for (int b = 0; b < 2; ++b) {
            add(new_ways[min(a + b, 2)], mul(ways[a], dp[j][b]));
          }
        }
        swap(ways, new_ways);
      }
      for (int a = 0; a < 2; ++a) {
        dp[i][a] = ways[a];
        add(dp[i][a], ways[2]);
      }
    }
  }
  cout << dp[0][0] << "\n";
  return 0;
}