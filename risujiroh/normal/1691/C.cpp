#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int x = 0;
    while (x < n && s[x] != '1') {
      ++x;
    }

    int y = n - 1;
    while (0 <= y && s[y] != '1') {
      --y;
    }

    if (x < y) {
      int base = 0;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
          if (i == 0) {
            base += 10;
          } else if (i == n - 1) {
            base += 1;
          } else {
            base += 11;
          }
        }
      }

      int ans = base;
      if (0 < x && y < n - 1 && x + (n - y - 1) <= k) {
        ans = base - 11;
      } else if (y < n - 1 && n - y - 1 <= k) {
        ans = base - 10;
      } else if (0 < x && x <= k) {
        ans = base - 1;
      }
      cout << ans << '\n';
    } else if (x == y) {
      if (n - y - 1 <= k) {
        cout << "1\n";
      } else if (x <= k) {
        cout << "10\n";
      } else {
        cout << "11\n";
      }
    } else {
      cout << "0\n";
    }
  }
}