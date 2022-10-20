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
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    auto chk = [&](int m) {
      deque<int> d(begin(a) + m, end(a));
      int last = -1;
      while (not empty(d)) {
        int t;
        if (d.front() < d.back()) {
          t = d.front();
          d.pop_front();
        } else {
          t = d.back();
          d.pop_back();
        }
        if (t < last) {
          return false;
        }
        last = t;
      }
      return true;
    };
    int ng = -1, ok = n;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (chk(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}