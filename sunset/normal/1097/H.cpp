#include <bits/stdc++.h>

using namespace std;

const int MAX = 30000;

struct info {
  bitset<MAX> prefix;
  bitset<MAX> suffix;
  long long ans = 0;
  long long len = 0;
};

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int d, m;
  cin >> d >> m;
  vector<int> gen(d);
  for (int i = 0; i < d; ++i) {
    cin >> gen[i];
  }
  int n;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  long long l, r;
  cin >> l >> r;
  bitset<MAX> one;
  for (int i = 0; i < n - 1; ++i) {
    one[i] = 1;
  }
  auto merge = [&](const info &l, const info &r) {
    info res;
    res.prefix = l.prefix;
    res.suffix = r.suffix;
    res.ans = l.ans + r.ans;
    res.len = l.len + r.len;
    if (l.len < n - 1) {
      res.prefix &= r.prefix >> l.len | one << n - 1 - l.len;
    }
    if (r.len < n - 1) {
      res.suffix &= l.suffix << r.len | one >> n - 1 - r.len;
    }
    if (l.len + r.len >= n) {
      bitset<MAX> b = l.suffix & r.prefix;
      if (l.len < n - 1) {
        b &= one >> n - 1 - l.len;
      }
      if (r.len < n - 1) {
        b &= one << n - 1 - r.len;
      }
      res.ans += b.count();
    }
    return res;
  };
  vector<vector<info>> dp(1, vector<info>(m));
  for (int i = 0; i < m; ++i) {
    dp[0][i].len = 1;
    if (n == 1) {
      dp[0][i].ans = b[0] >= i;
    } else {
      for (int j = 0; j < n - 1; ++j) {
        if (b[j + 1] >= i) {
          dp[0][i].prefix[j] = true;
        }
        if (b[j] >= i) {
          dp[0][i].suffix[j] = true;
        }
      }
    }
  }
  long long sz = 1;
  while (sz <= r / d) {
    int cur = dp.size();
    dp.push_back(dp.back());
    for (int i = 0; i < m; ++i) {
      for (int j = 1; j < d; ++j) {
        dp[cur][i] = merge(dp[cur][i], dp[cur - 1][(i + gen[j]) % m]);
      }
    }
    sz *= d;
  }
  auto solve = [&](long long k) {
    long long cur = sz;
    int diff = 0;
    info res;
    for (int i = dp.size() - 1; ~i; --i, cur /= d) {
      for (int j = 0; j < d; ++j) {
        if (k >= cur) {
          res = merge(res, dp[i][(diff + gen[j]) % m]);
          k -= cur;
        } else {
          diff = (diff + gen[j]) % m;
          break;
        }
      }
    }
    return res.ans;
  };
  cout << solve(r) - solve(l + n - 2) << "\n";
  return 0;
}