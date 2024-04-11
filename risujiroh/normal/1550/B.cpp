#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int ans = a * n;
    if (b < 0) {
      int c = 0;
      for (int i = 0; i < n; ++i) c += i == 0 || s[i - 1] != s[i];
      ans += (c / 2 + 1) * b;
    } else {
      ans += b * n;
    }
    cout << ans << '\n';
  }
}