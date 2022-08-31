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
  vector<string> g(n);
  for (int i = 0; i < n; ++i) {
    cin >> g[i];
  }
  map<vector<int>, long long> ways;
  auto solve = [&](vector<int> c) {
    vector<int> must;
    for (int s : c) {
      must.push_back(0);
      for (int i = 0; i < s - 1; ++i) {
        must.push_back(1);
      }
    }
    vector<vector<long long>> dp(1 << n, vector<long long>(n));
    for (int i = 0; i < n; ++i) {
      dp[1 << i][i] = 1;
    }
    for (int s = 1; s < (1 << n) - 1; ++s) {
      for (int i = 0; i < n; ++i) {
        if (dp[s][i]) {
          if (must[__builtin_popcount(s)]) {
            for (int j = 0; j < n; ++j) {
              if (!(s >> j & 1) && g[i][j] == '1') {
                dp[s | 1 << j][j] += dp[s][i];
              }
            }
          } else {
            for (int j = 0; j < n; ++j) {
              if (!(s >> j & 1)) {
                dp[s | 1 << j][j] += dp[s][i];
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      ways[c] += dp.back()[i];
    }
  };
  function<void(vector<int>, int, int)> dfs = [&](vector<int> c, int n, int m) {
    if (!n) {
      solve(c);
    } else {
      for (int i = m; i <= n; ++i) {
        c.push_back(i);
        dfs(c, n - i, i);
        c.pop_back();
      }
    }
  };
  dfs({}, n, 1);
  vector<long long> ans(1 << (n - 1));
  for (int s = 0; s < 1 << (n - 1); ++s) {
    vector<int> sz;
    int cur = 1;
    for (int i = 0; i < n - 1; ++i) {
      if (s >> i & 1) {
        ++cur;
      } else {
        sz.push_back(cur);
        cur = 1;
      }
    }
    sz.push_back(cur);
    sort(sz.begin(), sz.end());
    ans[s] = ways[sz];
  }
  for (int i = 1; i < 1 << (n - 1); i <<= 1) {
    for (int j = 0; j < 1 << (n - 1); j += i << 1) {
      for (int k = 0; k < i; ++k) {
        ans[j + k] -= ans[j + k + i];
      }
    }
  }
  for (int i = 0; i < 1 << (n - 1); ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}