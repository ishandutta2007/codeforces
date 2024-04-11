#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  cout << "YES\n";
  while (n--) {
    int x, y;
    cin >> x >> y >> x >> y;
    cout << ((x & 1) << 1 | (y & 1)) + 1 << '\n';
  }
}