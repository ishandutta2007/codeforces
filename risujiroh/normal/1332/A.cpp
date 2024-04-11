#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y, lx, ly, rx, ry;
    cin >> x >> y >> lx >> ly >> rx >> ry;
    bool ok = true;
    if (lx == rx and a + b) {
      ok = false;
    }
    if (ly == ry and c + d) {
      ok = false;
    }
    x -= a, x += b;
    y -= c, y += d;
    if (x < lx or rx < x) {
      ok = false;
    }
    if (y < ly or ry < y) {
      ok = false;
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}