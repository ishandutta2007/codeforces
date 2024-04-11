#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto&& v : a) {
    for (auto&& e : v) {
      cin >> e;
    }
  }
  auto chk = [&](int x, bool out = false) {
    vector<int> c(1 << m);
    for (int i = 0; i < n; ++i) {
      int bt = 0;
      for (int j = 0; j < m; ++j) {
        if (a[i][j] >= x) {
          bt |= 1 << j;
        }
      }
      ++c[bt];
    }
    for (int j = 0; j < m; ++j) {
      for (int bt = 0; bt < 1 << m; ++bt) {
        if (~bt >> j & 1) {
          c[bt] += c[bt | 1 << j];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int bt = 0;
      for (int j = 0; j < m; ++j) {
        if (a[i][j] >= x) {
          bt |= 1 << j;
        }
      }
      if (c[(1 << m) - 1 - bt]) {
        if (out) {
          for (int j = 0; j < n; ++j) {
            int nbt = 0;
            for (int k = 0; k < m; ++k) {
              if (a[j][k] >= x) {
                nbt |= 1 << k;
              }
            }
            if ((bt | nbt) == (1 << m) - 1) {
              cout << i + 1 << ' ' << j + 1 << '\n';
              exit(0);
            }
          }
        }
        return true;
      }
    }
    return false;
  };
  int ok = 0, ng = 1e9 + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  chk(ok, true);
}