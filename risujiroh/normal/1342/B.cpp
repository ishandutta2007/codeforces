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
    string t;
    cin >> t;
    if (count(begin(t), end(t), t[0]) == size(t)) {
      cout << t << '\n';
    } else {
      for (int _ = size(t); _--; ) {
        cout << "01";
      }
      cout << '\n';
    }
  }
}