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
    string s;
    cin >> s;
    int n = size(s);
    vector<int> cnt(3);
    int num = 0;
    auto add = [&](int i) {
      num += cnt[s[i] - '1']++ == 0;
    };
    auto rm = [&](int i) {
      num -= --cnt[s[i] - '1'] == 0;
    };
    int res = n + 1;
    for (int l = 0, r = 0; l < n; ++l) {
      while (r < n and num < 3) {
        add(r++);
      }
      if (num == 3) {
        res = min(res, r - l);
      }
      rm(l);
    }
    if (res > n) {
      res = 0;
    }
    cout << res << '\n';
  }
}