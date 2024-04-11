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
    vector<int> cnt(n + 1);
    bool first = true;
    for (int i = 0; i < 2 * n; ++i) {
      int a;
      cin >> a;
      if (cnt[a]++ == 0) {
        if (not exchange(first, false)) {
          cout << ' ';
        }
        cout << a;
      }
    }
    cout << '\n';
  }
}