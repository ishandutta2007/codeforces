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
    if (n == 1) {
      cout << -1 << "\n";
    } else {
      cout << 8;
      for (int i = 0; i < n - 1; ++i) {
        cout << 9;
      }
      cout << "\n";
    }
  }
  return 0;
}