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
  vector<vector<int>> s(2);
  for (auto&& e : s) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      e.push_back(x);
    }
  }
  vector f(2, vector(n, 0));
  queue<pair<int, int>> que;
  f[0][0] = f[1][0] = -1;
  que.emplace(0, 0);
  que.emplace(1, 0);
  vector cnt(2, vector(n, 0));
  while (not empty(que)) {
    auto [t, i] = que.front();
    que.pop();
    for (int e : s[1 - t]) {
      int ni = (i + n - e) % n;
      if (f[1 - t][ni]) continue;
      if (f[t][i] == -1) {
        f[1 - t][ni] = 1;
        que.emplace(1 - t, ni);
      } else {
        if (++cnt[1 - t][ni] == (int)size(s[1 - t])) {
          f[1 - t][ni] = -1;
          que.emplace(1 - t, ni);
        }
      }
    }
  }
  for (auto&& e : f) {
    for (int i = 1; i < n; ++i) {
      cout << (e[i] == 1 ? "Win" : e[i] == -1 ? "Lose" : "Loop") << " \n"[i == n - 1];
    }
  }
}