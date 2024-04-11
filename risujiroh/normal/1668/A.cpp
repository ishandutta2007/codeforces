#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    if (m < n) {
      swap(n, m);
    }
    if (n == 1) {
      if (m < 3) {
        cout << m - 1 << '\n';
      } else {
        cout << "-1\n";
      }
    } else {
      int ans = n + m - 2;
      ans += (m - n) / 2 * 2;
      cout << ans << '\n';
    }
  }
}