#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = 0;
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      for (int j = i; j < n; ++j) {
        if (a[j] % a[i] == 0) {
          vis[j] = true;
        }
      }
      ++ans;
    }
  }
  cout << ans << "\n";
  return 0;
}