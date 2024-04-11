#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  int b_max = -1;
  int b_second_max = -1;
  long long b_sum = 0;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    if (b > b_second_max) {
      b_second_max = b;
    }
    if (b_second_max > b_max) {
      swap(b_second_max, b_max);
    }
    b_max = max(b_max, b);
    b_sum += b;
  }
  int g_min = 1 << 30;
  long long g_sum = 0;
  for (int i = 0; i < m; ++i) {
    int g;
    cin >> g;
    g_min = min(g_min, g);
    g_sum += g;
  }
  if (b_max > g_min) {
    cout << -1 << "\n";
  } else {
    long long ans = (long long) (b_sum - b_max) * m + g_sum;
    if (b_max < g_min) {
      ans += b_max - b_second_max;
    }
    cout << ans << "\n";
  }
  return 0;
}