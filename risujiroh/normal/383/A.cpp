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
  long long res = 0, t = 0;
  while (n--) {
    int a;
    cin >> a;
    if (a) {
      ++t;
    } else {
      res += t;
    }
  }
  cout << res << '\n';
}