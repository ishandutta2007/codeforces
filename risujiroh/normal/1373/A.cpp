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
  int tt;
  cin >> tt;
  while (tt--) {
    long long a, b, c;
    cin >> a >> b >> c;
    cout << (a < c ? 1 : -1) << ' ' << (c < a * b ? b : -1) << '\n';
  }
}