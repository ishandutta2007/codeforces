#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = (a + c - 1) / c;
    int y = (b + d - 1) / d;
    if (x + y > k) {
      cout << "-1\n";
    } else {
      cout << x << ' ' << y << '\n';
    }
  }
}