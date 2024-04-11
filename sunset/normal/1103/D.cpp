#include <bits/stdc++.h>

using namespace std;

const long long inf = 1ll << 60;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  vector<int> b(n);
  long long gcd = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    gcd = __gcd(gcd, a[i]);
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  vector<long long> primes;
  for (int i = 2; (long long) i * i <= gcd; ++i) {
    if (gcd % i == 0) {
      primes.push_back(i);
      while (gcd % i == 0) {
        gcd /= i;
      }
    }
  }
  if (gcd != 1) {
    primes.push_back(gcd);
  }
  int m = primes.size();
  map<vector<long long>, vector<int>> f;
  for (int i = 0; i < n; ++i) {
    vector<long long> e(m, 1);
    for (int j = 0; j < m; ++j) {
      while (a[i] % primes[j] == 0) {
        a[i] /= primes[j];
        e[j] *= primes[j];
      }
    }
    f[e].push_back(b[i]);
  }
  vector<vector<long long>> dp(1 << m, vector<long long>(m + 1, inf));
  dp[0][0] = 0;
  for (auto p : f) {
    sort(p.second.begin(), p.second.end());
    vector<int> can(1 << m);
    for (int i = 0; i < 1 << m; ++i) {
      long long prod = 1;
      for (int j = 0; j < m; ++j) {
        if (i >> j & 1) {
          prod *= p.first[j];
        }
      }
      if (prod <= k) {
        can[i] = 1;
      }
    }
    for (int i = 1; i < 1 << m; i <<= 1) {
      for (int j = 0; j < m; j += i << 1) {
        for (int k = 0; k < i; ++k) {
          can[j + k] += can[j + k + i];
        }
      }
    }
    vector<int> useful;
    for (int i = 1; i < 1 << m; ++i) {
      if (can[i] == 1) {
        useful.push_back(i);
      }
    }
    for (auto v : p.second) {
      bool changed = false;
      for (int i = (1 << m) - 1; ~i; --i) {
        for (int j = m - 1; ~j; --j) {
          for (auto k : useful) {
            if (dp[i | k][j + 1] > dp[i][j] + v) {
              dp[i | k][j + 1] = dp[i][j] + v;
              changed = true;
            }
          }
        }
      }
      if (!changed) {
        break;
      }
    }
  }
  long long ans = inf;
  for (int i = 0; i <= m; ++i) {
    if (dp[(1 << m) - 1][i] != inf) {
      ans = min(ans, dp[(1 << m) - 1][i] * i);
    }
  }
  if (ans == inf) {
    ans = -1;
  }
  cout << ans << "\n";
  return 0;
}