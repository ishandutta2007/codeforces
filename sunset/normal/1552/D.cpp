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
    int ans = 0;
    function<void(int, int)> dfs = [&](int p, int s) {
      if (p == n) {
        if (!s) {
          ++ans;
        }
        return;
      }
      dfs(p + 1, s - a[p]);
      dfs(p + 1, s);
      dfs(p + 1, s + a[p]);
    };
    dfs(0, 0);
    cout << (ans >= 2 ? "YES" : "NO") << "\n";
  }
  return 0;
}