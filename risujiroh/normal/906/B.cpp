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
  int n, m;
  cin >> n >> m;
  bool tr = n > m;
  if (tr) {
    swap(n, m);
  }
  vector res(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (tr) {
        res[i][j] = i + n * j + 1;
      } else {
        res[i][j] = i * m + j + 1;
      }
    }
  }
  if (m >= 5) {
    for (int i = 0; i < n; ++i) {
      vector<int> v;
      for (int j = i & 1; j < m; j += 2) {
        v.push_back(res[i][j]);
      }
      for (int j = ~i & 1; j < m; j += 2) {
        v.push_back(res[i][j]);
      }
      swap(res[i], v);
    }
  } else if (m == 4) {
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        swap(res[i][0], res[i][2]);
        swap(res[i][1], res[i][2]);
        swap(res[i][2], res[i][3]);
      } else {
        swap(res[i][0], res[i][1]);
        swap(res[i][1], res[i][3]);
        swap(res[i][2], res[i][3]);
      }
    }
  } else if (m == 3) {
    if (n < 3) {
      cout << "NO\n";
      exit(0);
    }
    res[0] = {9, 2, 4};
    res[1] = {1, 7, 6};
    res[2] = {5, 3, 8};
  } else if (m == 2) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  if (tr) {
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        cout << res[i][j] << " \n"[i == n - 1];
      }
    }
  } else {
    for (auto e : res) {
      for (int j = 0; j < m; ++j) {
        cout << e[j] << " \n"[j == m - 1];
      }
    }
  }
}