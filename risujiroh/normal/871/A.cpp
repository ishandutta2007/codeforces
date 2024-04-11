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
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    if (n <= 3 or n == 5 or n == 7 or n == 11) {
      cout << "-1\n";
    } else {
      if (n % 4 == 0) {
        cout << n / 4 << '\n';
      } else if (n % 4 == 1) {
        cout << n / 4 - 1 << '\n';
      } else if (n % 4 == 2) {
        cout << n / 4 << '\n';
      } else {
        cout << n / 4 - 1 << '\n';
      }
    }
  }
}