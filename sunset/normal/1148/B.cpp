#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, s, t, k;
  cin >> n >> m >> s >> t >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] += s;
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  if (n <= k || m <= k) {
    cout << -1 << "\n";
    return 0;
  }
  int ans = 0;
  for (int i = 0; i <= k; ++i) {
    int p = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    if (p + k - i < m) {
      ans = max(ans, b[p + k - i]);
    } else {
      cout << -1 << "\n";
      return 0;
    }
  }
  cout << ans + t << "\n";
  return 0;
}