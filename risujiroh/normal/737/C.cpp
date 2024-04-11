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
  int n, s;
  cin >> n >> s;
  --s;
  vector<int> a(n), cnt(n + 1);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (i == s and a[i]) {
      ++res;
      a[i] = 0;
    }
    if (i != s and a[i] == 0) {
      a[i] = n;
    }
    ++cnt[a[i]];
  }
  DEBUG(cnt);
  auto chk = [&](int m) {
    auto b = cnt;
    int l = 0, r = n;
    DEBUG(m);
    while (m--) {
      while (b[l]) {
        ++l;
      }
      while (b[r] == 0) {
        --r;
      }
      if (r <= l) {
        return true;
      }
      ++b[l];
      --b[r];
    }
    DEBUG(b);
    for (int i = 0; i < n; ++i) {
      if (b[i] == 0 and b[i + 1]) {
        return false;
      }
    }
    return true;
  };
  int ng = -1, ok = n - 1;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  res += ok;
  cout << res << '\n';
}