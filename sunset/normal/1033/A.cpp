#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, ax, ay, bx, by, cx, cy;
  cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
  bx -= ax;
  by -= ay;
  cx -= ax;
  cy -= ay;
  puts((bx > 0) == (cx > 0) && (by > 0) == (cy > 0) ? "YES" : "NO");
  return 0;
}