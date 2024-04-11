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
  int n;
  cin >> n;
  set<int> se;
  while (n--) {
    int y;
    cin >> y;
    se.insert(y);
  }
  for (bool updated = true; exchange(updated, false); ) {
    int mx = *rbegin(se);
    for (int i = mx / 2; i; i >>= 1) {
      if (not se.count(i)) {
        updated = true;
        se.insert(i);
        se.erase(mx);
        break;
      }
    }
  }
  for (auto it = begin(se); it != end(se); ++it) {
    cout << *it << " \n"[it == prev(end(se))];
  }
}