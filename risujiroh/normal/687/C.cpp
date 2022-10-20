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
  int n, k;
  cin >> n >> k;
  vector<bitset<501>> f(501);
  f[0][0] = 1;
  while (n--) {
    int c;
    cin >> c;
    for (int x = 500; x >= 0; --x) {
      if (x + c <= 500) {
        f[x + c] |= f[x] | f[x] << c;
      }
    }
  }
  cout << f[k].count() << '\n';
  for (int i = f[k]._Find_first(); i <= 500; i = f[k]._Find_next(i)) {
    cout << i << ' ';
  }
}