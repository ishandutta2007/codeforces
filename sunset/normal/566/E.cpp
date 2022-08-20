#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 2) {
    cout << 1 << " " << 2 << "\n";
    return 0;
  }
  vector<bitset<N>> a(n);
  vector<bitset<N>> e(n);
  bitset<N> internal;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    while (c--) {
      int v;
      cin >> v;
      a[i][--v] = true;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      bitset<N> b = a[i] & a[j];
      if (b.count() == 2) {
        int v = b._Find_first();
        b[v] = false;
        int u = b._Find_first();
        b[u] = false;
        e[v][u] = e[u][v] = true;
        internal[u] = internal[v] = true;
      }
    }
  }
  if (!internal.count()) {
    for (int i = 1; i < n; ++i) {
      cout << i << " " << n << "\n";
    }
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    e[i][i] = true;
  }
  for (int i = 0; i < n; ++i) {
    bool minimal = true;
    for (int j = 0; j < n; ++j) {
      if (j != i && (a[i] & a[j]) == a[j] && (j < i || a[i] != a[j])) {
        minimal = false;
      }
    }
    int v = -1;
    if (minimal) {
      bitset<N> b = a[i] & internal;
      if (b.count() > 2) {
        for (int j = 0; j < n; ++j) {
          if (b[j] && e[j] == b) {
            v = j;
            break;
          }
        }
      } else {
        for (int j = 0; j < n; ++j) {
          if (b[j] && e[j].count() == 2) {
            v = j;
            break;
          }
        }
      }
      for (int j = 0; j < n; ++j) {
        if (a[i][j] && !internal[j]) {
          e[v][j] = e[j][v] = true;
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (e[i][j]) {
        cout << i + 1 << " " << j + 1 << "\n";
      }
    }
  }
  return 0;
}