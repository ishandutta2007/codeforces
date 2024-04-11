#include <bits/extc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto&& e : h) cin >> e;

  constexpr int inf = 0x3f3f3f3f;

  // right-to-left
  vector<int> minima, maxima;
  vector dp(n, inf);
  for (int i = n; i--;) {
    if (i == n - 1) dp[i] = 0;
    {
      bool any = false;
      while (not empty(minima) and not(h[i] < h[minima.back()])) {
        any |= h[i] == h[minima.back()];
        dp[i] = min(dp[i], 1 + dp[minima.back()]);
        minima.pop_back();
      }
      if (not empty(minima) and not any)
        dp[i] = min(dp[i], 1 + dp[minima.back()]);
      minima.push_back(i);
    }
    {
      bool any = false;
      while (not empty(maxima) and not(h[i] > h[maxima.back()])) {
        any |= h[i] == h[maxima.back()];
        dp[i] = min(dp[i], 1 + dp[maxima.back()]);
        maxima.pop_back();
      }
      if (not empty(maxima) and not any)
        dp[i] = min(dp[i], 1 + dp[maxima.back()]);
      maxima.push_back(i);
    }
  }

  cout << dp[0] << '\n';
}