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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto&& e : a) cin >> e;
    for (auto&& e : b) cin >> e;
    while (k--) {
      sort(begin(a), end(a));
      sort(begin(b), end(b));
      if (b.back() > a[0]) {
        swap(a[0], b.back());
      }
    }
    cout << accumulate(begin(a), end(a), 0) << '\n';
  }
}