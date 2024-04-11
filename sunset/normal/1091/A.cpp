#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int y, b, r;
  cin >> y >> b >> r;
  y -= 1;
  b -= 2;
  r -= 3;
  cout << min(y, min(b, r)) * 3 + 6 << endl;
  return 0;
}