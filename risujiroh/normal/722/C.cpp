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
  vector<long long> cum(n + 1);
  for (int i = n; i--; ) {
    cum[i] = a[i] + cum[i + 1];
  }
  multiset<long long> ms;
  ms.insert(cum[0] - cum[n]);
  set<int> se{-1, n};
  for (int _ = n; _--; ) {
    int pos;
    cin >> pos;
    --pos;
    int prv = *prev(se.lower_bound(pos));
    int nxt = *se.upper_bound(pos);
    ms.erase(ms.find(cum[prv + 1] - cum[nxt]));
    ms.insert(cum[prv + 1] - cum[pos]);
    ms.insert(cum[pos + 1] - cum[nxt]);
    se.insert(pos);
    cout << *rbegin(ms) << '\n';
  }
}