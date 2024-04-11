#include <bits/stdc++.h>

#define pb push_back
#define int long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ld long double
using namespace std;
const int M = 998244353;
const int N = 1000009;
int lcd[N], d[N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  lcd[1] = 1;
  for (int i = 2; i < N; i++) {
    if (lcd[i] == 0) {
      for (int x = i; x < N; x += i) {
        lcd[x] = i;
      }
    }
  }
  d[1] = 1;
  for (int i = 2; i < N; i++) {
    int x = i, l = lcd[i];
    int c = 0;
    while (x % l == 0) {
      x /= l;
      c++;
    }
    d[i] = d[x] * (c + 1);
  }
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  int sumdp = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] += d[i] - 1;
    dp[i] += sumdp % M;
    dp[i] %= M;
    sumdp += dp[i];
    sumdp %= M;
  }
  cout << dp[n] << '\n';
}