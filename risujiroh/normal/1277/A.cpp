#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int res = 0;
    for (int s = 1; s <= n; s = 10 * s + 1) {
      for (int i = 1; i <= 9; ++i) {
        res += s * i <= n;
      }
    }
    cout << res << '\n';
  }
}