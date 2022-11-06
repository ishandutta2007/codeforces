#include <bits/stdc++.h>

using namespace std;

int t, n, m;

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int red = 0, white = 0;
    while (m--) {
      int x, y;
      cin >> x >> y;
      red = max(red, x);
      white = max(white, y);
    }
    if (red + white > n) {
      puts("IMPOSSIBLE");
      continue;
    }
    n -= red, n -= white;
    while (red--) putchar('R');
    while (white--) putchar('W');
    while (n--) putchar('R');
    puts("");
  }
  return 0;
}