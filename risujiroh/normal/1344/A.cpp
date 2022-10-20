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
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      int r = (i + a) % n;
      if (r < 0) {
        r += n;
      }
      v.push_back(r);
    }
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    if ((int)size(v) == n) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}