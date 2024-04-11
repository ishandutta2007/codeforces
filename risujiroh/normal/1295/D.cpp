#include <bits/stdc++.h>
using namespace std;

template <class Z> vector<Z> divisor(Z n) {
  vector<Z> res;
  Z i;
  for (i = 1; i * i < n; ++i) if (n % i == 0) res.push_back(i), res.push_back(n / i);
  if (i * i == n) res.push_back(i);
  sort(begin(res), end(res));
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, m;
    cin >> a >> m;
    auto ds = divisor(m);
    int n = ds.size();
    vector<long long> dp(n);
    for (int i = n; i--; ) {
      dp[i] = m / ds[i];
      for (int j = i + 1; j < n; ++j) {
        if (ds[j] % ds[i] == 0) {
          dp[i] -= dp[j];
        }
      }
    }
    long long g = __gcd(a, m);
    int i = lower_bound(begin(ds), end(ds), g) - begin(ds);
    cout << dp[i] << '\n';
  }
}