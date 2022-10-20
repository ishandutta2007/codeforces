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
  int h, w;
  cin >> h >> w;
  vector a(h, vector<int>(w));
  for (auto&& v : a) {
    for (auto&& e : v) {
      cin >> e;
      --e;
    }
  }
  vector<int> b(h * w);
  for (int i = 0; i < h; ++i) {
    b[*max_element(begin(a[i]), end(a[i]))] |= 1;
  }
  for (int j = 0; j < w; ++j) {
    int mx = -1;
    for (int i = 0; i < h; ++i) {
      mx = max(mx, a[i][j]);
    }
    b[mx] |= 2;
  }
  vector c(h, vector<int>(w, 3));
  vector<set<pair<int, int>>> se(4);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      se[c[i][j]].emplace(i, j);
    }
  }
  auto valid = [&](int i, int j) {
    bool fr = (j and c[i][j - 1] == -1) or (j + 1 < w and c[i][j + 1] == -1);
    bool fc = (i and c[i - 1][j] == -1) or (i + 1 < h and c[i + 1][j] == -1);
    if (c[i][j] == 0) {
      return fr and fc;
    } else if (c[i][j] == 1) {
      return fc;
    } else if (c[i][j] == 2) {
      return fr;
    } else {
      return c[i][j] != -1;
    }
  };
  for (int x = h * w; x--; ) {
    assert(not empty(se[b[x]]));
    auto [i, j] = *begin(se[b[x]]);
    se[b[x]].erase({i, j});
    a[i][j] = x;
    c[i][j] = -1;
    if (b[x] & 1) {
      for (int nj = 0; nj < w; ++nj) {
        if (c[i][nj] == -1) continue;
        se[c[i][nj]].erase({i, nj});
        c[i][nj] &= ~1;
      }
    }
    if (b[x] & 2) {
      for (int ni = 0; ni < h; ++ni) {
        if (c[ni][j] == -1) continue;
        se[c[ni][j]].erase({ni, j});
        c[ni][j] &= ~2;
      }
    }
    for (int nj = 0; nj < w; ++nj) {
      if (valid(i, nj)) {
        se[c[i][nj]].emplace(i, nj);
      }
    }
    for (int ni = 0; ni < h; ++ni) {
      if (valid(ni, j)) {
        se[c[ni][j]].emplace(ni, j);
      }
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cout << a[i][j] + 1 << " \n"[j == w - 1];
    }
  }
}