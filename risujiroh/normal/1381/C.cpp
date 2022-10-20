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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> b(n), cnt(n + 1);
    for (auto&& e : b) {
      cin >> e;
      --e;
      ++cnt[e];
    }
    int z = find(begin(cnt), end(cnt), 0) - begin(cnt);
    priority_queue<pair<int, int>> pq;
    for (int c = 0; c <= n; ++c) {
      pq.emplace(cnt[c], c);
    }
    vector<int> rest(n + 1);
    for (int _ = x; _--; ) {
      auto [k, c] = pq.top();
      pq.pop();
      assert(k == cnt[c] and k > 0);
      ++rest[c];
      pq.emplace(--cnt[c], c);
    }
    vector<int> a(n, -1);
    fill(begin(cnt), end(cnt), 0);
    for (int i = 0; i < n; ++i) {
      if (rest[b[i]]-- > 0) {
        a[i] = b[i];
      } else {
        ++cnt[b[i]];
      }
    }
    y -= x;
    int mc = max_element(begin(cnt), end(cnt)) - begin(cnt);
    if (y > (n - x) - max(2 * cnt[mc] - (n - x), 0)) {
      cout << "NO\n";
      continue;
    }
    int need = (n - x) - max(2 * cnt[mc] - (n - x), 0) - y;
    vector<int> idx;
    for (int i = 0; i < n; ++i) {
      if (a[i] != -1) continue;
      idx.push_back(i);
    }
    sort(begin(idx), end(idx), [&](int i, int j) {
      return b[i] < b[j];
    });
    assert((int)size(idx) == n - x);
    for (int t = 0; t < n - x; ++t) {
      a[idx[t]] = b[idx[(t + (n - x) / 2) % (n - x)]];
      if (a[idx[t]] == b[idx[t]]) {
        a[idx[t]] = z;
      }
    }
    DEBUG(need);
    for (int t = 0; t < n - x; ++t) {
      if (a[idx[t]] == z) continue;
      if (need-- > 0) {
        a[idx[t]] = z;
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      cout << a[i] + 1 << " \n"[i == n - 1];
    }
    // int xx = 0;
    // for (int i = 0; i < n; ++i) {
    //   xx += a[i] == b[i];
    // }
    // sort(begin(a), end(a));
    // sort(begin(b), end(b));
    // vector<int> c;
    // set_intersection(begin(a), end(a), begin(b), end(b), back_inserter(c));
    // int yy = size(c);
    // DEBUG(xx, yy);
  }
}