#include <bits/stdc++.h>

using namespace std;

const int md = 1e9 + 7;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<long long> sum(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &sum[i]);
  }
  vector<int> parent(n, -1);
  for (int i = 1; i < n; ++i) {
    scanf("%d", &parent[i]);
    --parent[i];
  }
  for (int i = n - 1; i; --i) {
    sum[parent[i]] += sum[i];
  }
  long long total = sum[0];
  vector<int> ways(n + 1);
  for (int i = 0; i < n; ++i) {
    sum[i] = total / __gcd(total, sum[i]);
    if (sum[i] <= n) {
      ++ways[sum[i]];
    }
  }
  for (int i = n; i; --i) {
    for (int j = i << 1; j <= n; j += i) {
      ways[j] += ways[i];
    }
  }
  vector<int> dp(n + 1);
  int answer = 0;
  dp[1] = 1;
  for (int i = 1; i <= n; ++i) {
    if (ways[i] == i) {
      answer = (answer + dp[i]) % md;
      for (int j = i << 1; j <= n; j += i) {
        dp[j] = (dp[j] + dp[i]) % md;
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}