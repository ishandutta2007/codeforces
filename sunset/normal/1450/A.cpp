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
    string s;
    cin >> n >> s;
    string ans = "";
    for (auto c : s) {
      if (c != 't') {
        ans += c;
      }
    }
    for (auto c : s) {
      if (c == 't') {
        ans += c;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}