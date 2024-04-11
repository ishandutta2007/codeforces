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
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  vector<int> res;
  for (int x = a.back() - n + 1; x < a.back(); ++x) {
    bool ok = true;
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
      while (ptr < n and a[ptr] <= x + i) {
        ++ptr;
      }
      if ((ptr - i) % p == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      res.push_back(x);
    }
  }
  int k = size(res);
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i] << " \n"[i == k - 1];
  }
}