#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

inline void add(int &x, int y) {
  x += y;
  if (x >= md) {
    x -= md;
  }
}

inline int mul(int x, int y) {
  return (long long) x * y % md;
}

inline int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = mul(x, x)) {
    if (y & 1) {
      res = mul(res, x);
    }
  }
  return res;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  long long n;
  int m;
  cin >> n >> m;
  vector<pair<int, int>> primes;
  for (int i = 2; (long long) i * i <= n; ++i) {
    if (n % i == 0) {
      int e = 0;
      while (n % i == 0) {
        n /= i;
        ++e;
      }
      primes.emplace_back(i, e);
    }
  }
  if (n != 1) {
    primes.emplace_back(n % md, 1);
  }
  int ans = 1;
  for (auto p : primes) {
    int e = p.second;
    vector<int> dp(e + 1);
    dp[e] = 1;
    for (int i = 0; i < m; ++i) {
      vector<int> new_dp(e + 1);
      for (int j = 0; j <= e; ++j) {
        int coef = mul(dp[j], power(j + 1, md - 2));
        for (int k = 0; k <= j; ++k) {
          add(new_dp[k], coef);
        }
      }
      swap(dp, new_dp);
    }
    int res = 0, cur = 1;
    for (int i = 0; i <= e; ++i) {
      add(res, mul(cur, dp[i]));
      cur = mul(cur, p.first);
    }
    ans = mul(ans, res);
  }
  cout << ans << "\n";
  return 0;
}