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
  for (int i = 0; i < 2e6; ++i) {
    se.insert(i);
  }
  string res(2e6, '?');
  while (n--) {
    string t;
    cin >> t;
    int m = size(t);
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      --x;
      auto it = se.lower_bound(x);
      while (it != end(se) and *it < x + m) {
        res[*it] = t[*it - x];
        it = se.erase(it);
      }
    }
  }
  while (res.back() == '?') {
    res.pop_back();
  }
  for (auto&& e : res) {
    if (e == '?') {
      e = 'a';
    }
  }
  cout << res << '\n';
}