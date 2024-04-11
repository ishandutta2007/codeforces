#include <iostream>
using namespace std;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int x = min(a, d);
  int y = min(min(b, c), d);

  int ans = 0;
  for (int x = 0; x <= d && x <= a; ++x) {
    int y = min(min(b, c), d - x);
    int cost = x * e + y * f;
    if (cost > ans) ans = cost;
  }
  cout << ans << "\n";
}