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
  vector<int> min_t(n, m), max_t(n, -1);
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    --x;
    min_t[x] = min(min_t[x], i);
    max_t[x] = max(max_t[x], i);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i - 1; j <= i + 1; ++j) {
      if (j >= 0 && j < n) {
        if (max_t[i] == -1 || max_t[j] == -1 || max_t[j] < min_t[i]) {
          ++ans;
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}