#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
template <typename T>
class fenwick2d {
 public:
  vector<vector<T>> fenw;
  int n, m;
 
  fenwick2d(int _n, int _m) : n(_n), m(_m) {
    fenw.resize(n);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }
 
  inline void modify(int i, int j, T v) {
    int x = i;
    while (x < n) {
      int y = j;
      while (y < m) {
        fenw[x][y] += v;
        y |= (y + 1);
      }
      x |= (x + 1);
    }
  }
 
  inline T get(int i, int j) {
    T v{};
    int x = i;
    while (x >= 0) {
      int y = j;
      while (y >= 0) {
        v += fenw[x][y];
        y = (y & (y + 1)) - 1;
      }
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> at(n * n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int v;
      cin >> v;
      --v;
      at[v] = make_pair(i, j);
    }
  }
  fenwick2d<int> fenw(n + n, n + n);
  vector<string> res(n, string(n, ' '));
  int cc = 0;
  for (int v = n * n - 1; v >= 0; v--) {
    int i = at[v].first;
    int j = at[v].second;
    int x = i + j;
    int y = i - j + (n - 1);
    int xa = max(0, x - k);
    int ya = max(0, y - k);
    int xb = min(n + n - 1, x + k);
    int yb = min(n + n - 1, y + k);
    int sum = fenw.get(xb, yb) - fenw.get(xa - 1, yb) - fenw.get(xb, ya - 1) + fenw.get(xa - 1, ya - 1);
    if (sum == cc) {
      res[i][j] = 'M';
      fenw.modify(x, y, +1);
      cc += 1;
    } else {
      res[i][j] = 'G';
    }
  }
  for (int i = 0; i < n; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}