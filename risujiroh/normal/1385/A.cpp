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
    vector<int> a(3);
    for (auto&& e : a) cin >> e;
    sort(begin(a), end(a));
    if (a[1] == a[2]) {
      cout << "YES\n";
      cout << a[0] << ' ' << a[0] << ' ' << a[1] << '\n';
    } else {
      cout << "NO\n";
    }
  }
}