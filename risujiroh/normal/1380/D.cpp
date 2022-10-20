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
  int n, m;
  cin >> n >> m;
  long long x, k, y;
  cin >> x >> k >> y;
  vector<int> a(n), b(m);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  vector<int> p{-1};
  for (int e : b) {
    static int ptr = 0;
    while (ptr < n and a[ptr] != e) {
      ++ptr;
    }
    if (ptr == n) {
      cout << "-1\n";
      exit(0);
    }
    p.push_back(ptr++);
  }
  p.push_back(n);
  auto res = 0LL;
  for (int t = 0; t < (int)size(p) - 1; ++t) {
    int l = p[t] + 1, r = p[t + 1];
    if (l == r) continue;
    int mx = -1;
    if (l) {
      mx = max(mx, a[l - 1]);
    }
    if (r < n) {
      mx = max(mx, a[r]);
    }
    if (r - l < k) {
      if (*max_element(begin(a) + l, begin(a) + r) > mx) {
        cout << "-1\n";
        exit(0);
      }
      res += (r - l) * y;
      continue;
    }
    res += x;
    int rest = r - l - k;
    res += y * (rest % k);
    res += min(x, y * k) * (rest / k);
    if (y * k < x and *max_element(begin(a) + l, begin(a) + r) < mx) {
      res -= x;
      res += y * k;
    }
    DEBUG(l, r, res);
  }
  cout << res << '\n';
}