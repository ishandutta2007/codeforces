#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (a[i] > a[i + 1]) {
        ans += a[i] - a[i + 1];
      }
    }
    cout << ans << "\n";
  }
  return 0;
}