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
    string s;
    cin >> s;
    int ans = 1;
    for (auto c : s) {
      ans = max(ans, c - '0');
    }
    cout << ans << "\n";
  }
  return 0;
}