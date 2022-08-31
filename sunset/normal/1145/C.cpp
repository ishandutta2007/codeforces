#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int a;
  cin >> a;
  for (int i = 3; ~i; --i) {
    bool ok = true;
    for (int j = i + 1; j < 4; ++j) {
      if (!(a >> j & 1)) {
        ok = false;
      }
    }
    if (ok) {
      a ^= 1 << i;
    }
  }
  cout << a << "\n";
  return 0;
}