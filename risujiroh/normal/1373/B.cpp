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
    string s;
    cin >> s;
    int a = count(begin(s), end(s), '0');
    int b = count(begin(s), end(s), '1');
    if (min(a, b) & 1) {
      cout << "DA\n";
    } else {
      cout << "NET\n";
    }
  }
}