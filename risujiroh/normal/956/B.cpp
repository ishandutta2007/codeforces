#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, u;
  cin >> n >> u;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  double ans = -1;
  for (int i = 0; i < n - 2; ++i) {
    int k = upper_bound(begin(a), end(a), a[i] + u) - begin(a) - 1;
    if (k - i >= 2) ans = max(ans, double(a[k] - a[i + 1]) / (a[k] - a[i]));
  }
  cout.precision(10);
  cout << ans << '\n';
}