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
  cout << fixed << setprecision(20);
  constexpr double pi = acos(-1);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    cout << tan(pi / 2 - pi / (2 * n)) << '\n';
  }
}