#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.h"
#else
#define DUMP(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto&& e : s) cin >> e;
  if (h >= 4) {
    cout << "-1\n";
    exit(0);
  }
  if (h == 1) {
    cout << "0\n";
    exit(0);
  }
  int res = h * w;
  for (int st = 0; st < 1 << (h - 1); ++st) {
    DUMP(st);
    int goal = st, cur = 0;
    for (int j = 0; j < w; ++j) {
      int min_cost = h;
      for (int bt = 0; bt < 1 << h; ++bt) {
        int t = 0;
        for (int i = 0; i < h - 1; ++i) {
          int p = (bt >> i & 1) + (bt >> (i + 1) & 1);
          p &= 1;
          t |= p << i;
        }
        if (t != goal) continue;
        int cost = 0;
        for (int i = 0; i < h; ++i) {
          cost += (s[i][j] - '0') != (bt >> i & 1);
        }
        min_cost = min(min_cost, cost);
      }
      cur += min_cost;
      goal ^= ~(-1u << (h - 1));
      DUMP(goal);
    }
    res = min(res, cur);
  }
  cout << res << '\n';
}