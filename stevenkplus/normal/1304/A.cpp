#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if ((y - x) % (a + b) == 0) {
      int ans = (y - x) / (a + b);
      cout << ans << "\n";
    } else {
      cout << "-1\n";
    }
  }
}