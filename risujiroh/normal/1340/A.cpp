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
    vector<int> ord(n);
    for (int i = 0; i < n; ++i) {
      int p;
      cin >> p;
      --p;
      ord[p] = i;
    }
    bool ok = true;
    vector<bool> used(n);
    used[ord[0]] = true;
    for (int t = 1; t < n; ++t) {
      int i = ord[t], pi = ord[t - 1];
      if (pi + 1 < n and not used[pi + 1] and i != pi + 1) {
        ok = false;
        break;
      }
      used[i] = true;
    }
    cout << (ok ? "Yes\n" : "No\n");
  }
}