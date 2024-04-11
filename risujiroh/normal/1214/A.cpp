#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, d, e; cin >> n >> d >> e;
  e *= 5;
  // n %= d * e;
  bitset<100000001> dp;
  dp[0] = true;
  for (int x = 0; x <= 1e8; ++x) if (dp[x]) {
    if (x + d <= 1e8) dp[x + d] = true;
    if (x + e <= 1e8) dp[x + e] = true;
  }
  auto m = n;
  while (!dp[n]) {
    --n;
  }
  cout << m - n << '\n';
}