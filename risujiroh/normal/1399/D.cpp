#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    array<set<int>, 2> se;
    for (int i = 0; i < n; ++i) {
      se[s[i] - '0'].insert(i);
    }
    int k = 0;
    vector<int> res(n);
    while (not empty(se[0]) or not empty(se[1])) {
      ++k;
      int nxt = empty(se[0]) or (not empty(se[1]) and *begin(se[1]) < *begin(se[0]));
      int pos = *begin(se[nxt]);
      while (true) {
        res[pos] = k;
        se[nxt].erase(pos);
        nxt ^= 1;
        auto it = se[nxt].upper_bound(pos);
        if (it == end(se[nxt])) break;
        pos = *it;
      }
    }
    cout << k << '\n';
    for (int i = 0; i < n; ++i) {
      cout << res[i] << " \n"[i == n - 1];
    }
  }
}