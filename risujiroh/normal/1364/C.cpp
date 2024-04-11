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
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  set<int> se;
  for (int i = 0; i <= 2 * n; ++i) {
    se.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > i + 1) {
      cout << "-1\n";
      exit(0);
    }
    se.erase(a[i]);
  }
  multiset ms(begin(a), end(a));
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = *begin(se);
    ms.erase(ms.find(a[i]));
    if (not ms.count(a[i])) {
      se.insert(a[i]);
    }
    se.erase(b[i]);
  }
  for (int i = 0; i < n; ++i) {
    cout << b[i] << " \n"[i == n - 1];
  }
}