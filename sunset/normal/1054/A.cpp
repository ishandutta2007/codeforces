#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int stairs = abs(x - y) * t1;
  int elevator = (abs(x - y) + abs(x - z)) * t2 + 3 * t3;
  puts(elevator <= stairs ? "YES" : "NO");
  return 0;
}