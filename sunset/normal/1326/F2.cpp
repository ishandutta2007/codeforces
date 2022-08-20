#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
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
  vector<vector<long long>> only(1 << n, vector<long long>(n + 1));
  for (int s = 1; s < 1 << n; ++s) {
    vector<long long> dp(n), new_dp(n);
    vector<int> bits;
    for (int i = 0; i < n; ++i) {
      if (s >> i & 1) {
        bits.push_back(i);
        dp[i] = 1;
      }
    }
    for (int len = 1; len <= n; ++len) {
      for (int i = 0; i < n; ++i) {
        only[s][len] += dp[i];
      }
      for (int i : bits) {
        for (int j : bits) {
          if (g[i][j] == '1') {
            new_dp[j] += dp[i];
          }
        }
      }
      for (int i = 0; i < n; ++i) {
        dp[i] = new_dp[i];
        new_dp[i] = 0;
      }
    }
  }
  auto solve = [&](vector<int> c) {
    long long res = 0;
    for (int s = 1; s < 1 << n; ++s) {
      long long ways = 1;
      for (int x : c) {
        ways *= only[s][x];
      }
      if ((__builtin_popcount(s) ^ n) & 1) {
        res -= ways;
      } else {
        res += ways;
      }
    }
    ways[c] = res;
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