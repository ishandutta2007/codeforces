#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto sorted = s;
    sort(begin(sorted), end(sorted));
    int ans = 0;
    for (int i = 0; i < n; ++i) ans += s[i] != sorted[i];
    cout << ans << '\n';
  }
}