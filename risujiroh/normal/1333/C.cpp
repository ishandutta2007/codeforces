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
  vector<long long> cum(n + 1);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    cum[i + 1] = cum[i] + a;
  }
  long long res = 0;
  set<long long> se;
  for (int l = 0, r = 0; l < n; ++l) {
    while (r <= n and not se.count(cum[r])) {
      se.insert(cum[r]);
      ++r;
    }
    res += r - l - 1;
    se.erase(cum[l]);
  }
  cout << res << '\n';
}