#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    n += 2;
    vector<int> a(n);
    for (int i = 1; i < n - 1; ++i) cin >> a[i];
    int64_t ans = 0;
    for (int i = 1; i < n; ++i) ans += abs(a[i] - a[i - 1]);
    for (int i = 1; i < n - 1; ++i) ans -= max(a[i] - max(a[i - 1], a[i + 1]), 0);
    cout << ans << '\n';
  }
}