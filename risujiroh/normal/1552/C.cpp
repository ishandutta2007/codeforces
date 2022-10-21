#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(k), y(k);
    vector<bool> v(2 * n, true);
    for (int i = 0; i < k; ++i) {
      cin >> x[i] >> y[i];
      --x[i], --y[i];
      if (x[i] > y[i]) swap(x[i], y[i]);
      v[x[i]] = false;
      v[y[i]] = false;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
      for (int j = 0; j < i; ++j) {
        ans += x[i] < x[j] && x[j] < y[i] && y[i] < y[j];
        ans += x[j] < x[i] && x[i] < y[j] && y[j] < y[i];
      }
      int t = count(begin(v) + x[i], begin(v) + y[i], true);
      ans += min(t, 2 * (n - k) - t);
    }
    ans += (n - k) * (n - k - 1) / 2;
    cout << ans << '\n';
  }
}