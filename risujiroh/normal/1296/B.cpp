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
    while (n) {
      if (n < 10) {
        res += n;
        break;
      }
      int x = n / 10 * 10;
      res += x;
      n -= x / 10 * 9;
    }
    cout << res << '\n';
  }
}