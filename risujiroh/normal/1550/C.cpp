#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  auto check = [&](auto a, int n) -> bool {
    for (int k = 2; k < n; ++k)
      for (int j = 1; j < k; ++j)
        for (int i = 0; i < j; ++i) {
          if (a[i] <= a[j] && a[j] <= a[k]) return false;
          if (a[i] >= a[j] && a[j] >= a[k]) return false;
        }
    return true;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    int ans = 0;
    for (int r = 1; r <= n; ++r)
      for (int l = r; l--;) {
        if (r - l == 5) break;
        ans += check(begin(a) + l, r - l);
      }
    cout << ans << '\n';
  }
}