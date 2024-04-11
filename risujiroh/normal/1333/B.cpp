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
    for (auto&& e : a) {
      cin >> e;
    }
    vector<int> b(n);
    for (auto&& e : b) {
      cin >> e;
    }
    int p = 0;
    while (p < n and a[p] >= b[p]) {
      ++p;
    }
    int q = 0;
    while (q < n and a[q] <= b[q]) {
      ++q;
    }
    bool ok = true;
    if (p < n and find(begin(a), end(a), 1) - begin(a) >= p) {
      ok = false;
    }
    if (q < n and find(begin(a), end(a), -1) - begin(a) >= q) {
      ok = false;
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}