#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  int64_t ans = 0;
  for (int i = n - 1; i--;)
    if (a[i] < a[i + 1] - 1) {
      ans += a[i + 1] - 1 - a[i];
      a[i] = a[i + 1] - 1;
    }
  for (int i = 0; i < n - 1; ++i)
    if (a[i + 1] < a[i]) {
      ans += a[i] - a[i + 1];
      a[i + 1] = a[i];
    }
  cout << ans << '\n';
}