#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto&& e : d) cin >> e;
    sort(begin(d), end(d));
    int64_t ans = d.back();
    for (int i = 1; i < n; ++i) {
      ans -= int64_t(d[i] - d[i - 1]) * i * (n - i);
    }
    cout << ans << '\n';
  }
}