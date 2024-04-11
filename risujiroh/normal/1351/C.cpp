#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    set<array<int, 4>> se;
    int x = 0, y = 0;
    int res = 0;
    for (char c : s) {
      int nx = x, ny = y;
      if (c == 'S') --ny;
      if (c == 'N') ++ny;
      if (c == 'W') --nx;
      if (c == 'E') ++nx;
      if (se.count({x, y, nx, ny}) or se.count({nx, ny, x, y})) {
        res += 1;
      } else {
        res += 5;
      }
      se.insert({x, y, nx, ny});
      x = nx, y = ny;
    }
    cout << res << '\n';
  }
}