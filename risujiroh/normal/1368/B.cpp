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
  long long k;
  cin >> k;
  for (int n = 10; n <= 400; ++n) {
    int q = n / 10, r = n % 10;
    long long p = 1;
    for (int i = 0; i < 10; ++i) {
      if (i < r) {
        p *= q + 1;
      } else {
        p *= q;
      }
    }
    if (p >= k) {
      for (int i = 0; i < 10; ++i) {
        cout << string(q + (i < r), "codeforces"[i]);
      }
      cout << '\n';
      exit(0);
    }
  }
}