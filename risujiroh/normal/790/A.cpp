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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  iota(begin(a), end(a), 0);
  for (int i = k - 1; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "YES") {
      set<int> se(begin(a) + (i - k + 1), begin(a) + i);
      for (int x = 0; ; ++x) {
        if (not se.count(x)) {
          a[i] = x;
          break;
        }
      }
    } else {
      a[i] = a[i - k + 1];
    }
  }
  DEBUG(a);
  for (int i = 0; i < n; ++i) {
    string s;
    if (a[i] < 26) {
      s = 'A' + a[i];
    } else {
      s = string(1, 'A' + (a[i] - 26)) + "a";
    }
    cout << s << " \n"[i == n - 1];
  }
}