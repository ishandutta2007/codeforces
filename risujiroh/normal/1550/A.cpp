#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int s;
    cin >> s;
    int ans = 0;
    for (int i = 1;; i += 2) {
      ++ans;
      if ((s -= i) <= 0) break;
    }
    cout << ans << '\n';
  }
}