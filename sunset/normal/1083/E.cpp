#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  ++n;
  vector<pair<pair<int, int>, long long>> a(n);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d %lld", &a[i].first.first, &a[i].first.second, &a[i].second);
  }
  sort(a.begin() + 1, a.end());
  vector<long long> dp(n);
  vector<int> q(n);
  int l = 0, r = 0;
  dp[0] = 0;
  q[r++] = 0;
  auto get = [&](int from, int to) {
    return dp[from] + (long long)(a[to].first.first - a[from].first.first) * a[to].first.second - a[to].second;
  };
  auto slope = [&](int from, int to) {
    return (long double)(dp[to] - dp[from]) / (a[to].first.first - a[from].first.first);
  };
  for (int i = 1; i < n; ++i) {
    while (l + 1 < r && get(q[l], i) < get(q[l + 1], i)) {
      ++l;
    }
    dp[i] = get(q[l], i);
    while (l + 1 < r && slope(q[r - 2], q[r - 1]) < slope(q[r - 2], i)) {
      --r;
    }
    q[r++] = i;
  }
  printf("%lld\n", *max_element(dp.begin(), dp.end()));
  return 0;
}