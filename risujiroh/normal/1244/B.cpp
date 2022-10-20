#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        mx = max({mx, i + 1, n - i});
      }
    }
    int res = max(2 * mx, n);
    cout << res << '\n';
  }
}