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
  int n, q;
  cin >> n >> q;
  set<int> se;
  int id = 0;
  vector<vector<int>> v(n);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      --x;
      se.insert(id);
      v[x].push_back(id);
      ++id;
    } else if (type == 2) {
      int x;
      cin >> x;
      --x;
      for (int e : v[x]) {
        se.erase(e);
      }
      v[x].clear();
    } else {
      int t;
      cin >> t;
      while (not empty(se) and *begin(se) < t) {
        se.erase(begin(se));
      }
    }
    cout << size(se) << '\n';
  }
}