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
  int a, b, c;
  cin >> a >> b >> c;
  int n;
  cin >> n;
  int res = 0;
  while (n--) {
    int x;
    cin >> x;
    res += b < x and x < c;
  }
  cout << res << '\n';
}