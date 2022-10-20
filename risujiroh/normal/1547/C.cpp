#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a(n), b(m);
    for (auto&& e : a) cin >> e;
    for (auto&& e : b) cin >> e;
    vector<int> ans;
    ans.reserve(n + m);
    for (int i = 0, j = 0; i < n || j < m;) {
      if (i < n && a[i] == 0) {
        ans.push_back(a[i]);
        ++i;
        ++k;
        continue;
      }
      if (j < m && b[j] == 0) {
        ans.push_back(b[j]);
        ++j;
        ++k;
        continue;
      }
      if ((i == n || a[i] > k) && (j == m || b[j] > k)) {
        ans.clear();
        break;
      }
      if (i < n && a[i] <= k) {
        ans.push_back(a[i]);
        ++i;
        continue;
      }
      if (j < m && b[j] <= k) {
        ans.push_back(b[j]);
        ++j;
        continue;
      }
    }
    if (empty(ans))
      cout << "-1\n";
    else
      for (int i = 0; i < n + m; ++i) cout << ans[i] << " \n"[i + 1 == n + m];
  }
}