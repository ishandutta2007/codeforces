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
    int n = size(s);
    cout << s[0];
    for (int i = 1; i < n; i += 2) {
      cout << s[i];
    }
    cout << '\n';
  }
}