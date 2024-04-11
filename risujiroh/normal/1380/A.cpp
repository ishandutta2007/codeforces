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
    vector<int> p(n);
    for (auto&& e : p) cin >> e;
    [&] {
      for (int i = 1; i < n - 1; ++i) {
        if (p[i - 1] < p[i] and p[i] > p[i + 1]) {
          cout << "YES\n";
          cout << i << ' ' << i + 1 << ' ' << i + 2 << '\n';
          return;
        }
      }
      cout << "NO\n";
    }();
  }
}