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
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }
  vector<array<int, 4>> v;
  vector<int> w(10000);
  for (int t0 = 0; t0 < 10; ++t0) {
    for (int t1 = t0; t1 < 10; ++t1) {
      for (int t2 = t1; t2 < 10; ++t2) {
        for (int t3 = t2; t3 < 10; ++t3) {
          w[t0 + 10 * (t1 + 10 * (t2 + 10 * t3))] = size(v);
          v.push_back(array<int, 4>{t0, t1, t2, t3});
        }
      }
    }
  }
  auto to_id = [&](int t0, int t1, int t2, int t3) {
    return w[t0 + 10 * (t1 + 10 * (t2 + 10 * t3))];
  };
  auto _ = [&](int i, int id, int x) {
    return i * 715 * 9 + id * 9 + x;
  };
  vector<int> d((n + 1) * 715 * 9, -1);
  queue<tuple<int, int, int>> que;
  d[_(0, 714, 0)] = 0;
  que.emplace(0, 714, 0);
  while (not empty(que)) {
    auto [i, id, x] = que.front();
    que.pop();
    if (i == n and id == 714) {
      cout << d[_(i, id, x)] << '\n';
      exit(0);
    }
    auto add = [&](int ni, int nid, int nx, int nd) {
      if (d[_(ni, nid, nx)] != -1) return;
      d[_(ni, nid, nx)] = nd;
      que.emplace(ni, nid, nx);
    };
    int nd = d[_(i, id, x)] + 1;
    if (x) {
      add(i, id, x - 1, nd);
    }
    if (x + 1 < 9) {
      add(i, id, x + 1, nd);
    }
    if (i < n and a[i] == x and v[id][3] == 9) {
      auto arr = v[id];
      arr[3] = b[i];
      sort(begin(arr), end(arr));
      add(i + 1, to_id(arr[0], arr[1], arr[2], arr[3]), x, nd);
    }
    for (int j = 0; j < 4; ++j) {
      if (v[id][j] == x) {
        auto arr = v[id];
        arr[j] = 9;
        sort(begin(arr), end(arr));
        add(i, to_id(arr[0], arr[1], arr[2], arr[3]), x, nd);
      }
    }
  }
}