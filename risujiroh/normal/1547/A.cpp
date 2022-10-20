#include <bits/stdc++.h>

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int xa, ya;
    cin >> xa >> ya;
    int xb, yb;
    cin >> xb >> yb;
    int xf, yf;
    cin >> xf >> yf;
    int ans = abs(xb - xa) + abs(yb - ya);
    if (xa == xb && xa == xf && min(ya, yb) < yf && yf < max(ya, yb)) ans += 2;
    if (ya == yb && ya == yf && min(xa, xb) < xf && xf < max(xa, xb)) ans += 2;
    cout << ans << '\n';
  }
}