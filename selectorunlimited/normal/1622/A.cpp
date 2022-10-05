#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    bool ok = 0;
    if ((x == y && x == z) || (x + y == z || y + z == x) ||
        (x + z == y || y + x == z))
      ok = 1;
    if (x == y && x + y > z && x + z > y) ok = 1;
    if (x == z && x + z > y && x + y > z) ok = 1;
    if (y == z && y + z > x && y + x > z) ok = 1;
    if ((x == y || y == z || x == z) && (x + y + z) % 2 == 0) ok = 1;
    if ((x + y + z) & 1) ok = 0;
    printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}