#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> lr(n);
    for (auto&& [l, r] : lr) {
      cin >> l >> r;
      --l;
    }
    lr.emplace_back(-1, 2e5);
    ++n;
    sort(begin(lr), end(lr));
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) {
      return lr[i].second - lr[i].first < lr[j].second - lr[j].first;
    });
    vector<int> w(n);
    for (int i : ord) {
      auto [li, ri] = lr[i];
      int cur = 0;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      pq.emplace(0, 0);
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        auto [l, r] = lr[j];
        if (li <= l and r <= ri) {
          while (not empty(pq) and pq.top().first <= l) {
            cur = max(cur, pq.top().second);
            pq.pop();
          }
          pq.emplace(r, cur + w[j]);
        }
      }
      while (not empty(pq)) {
        cur = max(cur, pq.top().second);
        pq.pop();
      }
      w[i] = cur + 1;
    }
    cout << w[0] - 1 << '\n';
  }
}