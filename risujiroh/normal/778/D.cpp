#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

vector<pair<int, int>> f(vector<vector<int>> a) {
  int h = size(a), w = size(a[0]);
  vector<pair<int, int>> res;
  auto op = [&](int i, int j) {
    swap(a[i][j], a[i + 1][j + 1]);
    res.emplace_back(i, j);
  };
  for (int i = 0; i < h; i += 2) {
    for (int j = 0; j < w; ++j) {
      if (a[i][j] == a[i + 1][j]) continue;
      assert(a[i][j] == a[i][j + 1]);
      for (int k = 1; ; ++k) {
        if (a[i + k][j + k - 1] == a[i + k][j + k]) {
          while (--k) {
            op(i + k, j + k);
            op(i + k, j + k - 1);
          }
          op(i, j);
          break;
        }
        if (a[i + k + 1][j + k] == a[i + k][j + k]) {
          while (--k >= 0) {
            op(i + k + 1, j + k);
            op(i + k, j + k);
          }
          break;
        }
      }
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w;
  cin >> h >> w;
  auto read = [&] {
    vector<string> s(h);
    for (auto&& e : s) cin >> e;
    int t = 0;
    vector res(h, vector(w, -1));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (res[i][j] != -1) continue;
        if (s[i][j] == 'L') {
          assert(s[i][j + 1] == 'R');
          res[i][j] = res[i][j + 1] = t++;
        } else {
          assert(s[i][j] == 'U');
          res[i][j] = res[i + 1][j] = t++;
        }
      }
    }
    return res;
  };
  auto a = read(), b = read();
  bool swapped = false;
  if (h & 1) {
    swapped = true;
    swap(h, w);
    vector na(h, vector(w, -1));
    vector nb(h, vector(w, -1));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        na[i][j] = a[j][i];
        nb[i][j] = b[j][i];
      }
    }
    swap(a, na), swap(b, nb);
  }
  for (int i = 0; i < h; ++i) {
    DEBUG(i, a[i], b[i]);
  }
  auto res = f(a);
  auto fb = f(b);
  res.insert(end(res), rbegin(fb), rend(fb));
  cout << size(res) << '\n';
  for (auto [i, j] : res) {
    if (swapped) {
      swap(i, j);
    }
    cout << i + 1 << ' ' << j + 1 << '\n';
  }
}