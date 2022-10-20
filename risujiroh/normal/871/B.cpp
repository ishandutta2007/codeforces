#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int j = 0; j < n; ++j) {
    cout << "? 0 " << j << endl;
    cin >> x[j];
  }
  y[0] = x[0];
  for (int i = 1; i < n; ++i) {
    cout << "? " << i << " 0" << endl;
    cin >> y[i];
  }
  int cnt = 0;
  vector<int> res;
  for (int p0 = 0; p0 < n; ++p0) {
    vector<int> b(n, -1);
    for (int j = 0; j < n; ++j) {
      b[j] = x[j] ^ p0;
      if (b[j] < 0 or b[j] >= n) {
        b[j] = -1;
        break;
      }
    }
    if (find(begin(b), end(b), -1) != end(b)) {
      continue;
    }
    vector<int> p(n);
    for (int j = 0; j < n; ++j) {
      p[b[j]] = j;
    }
    bool ok = true;
    for (int j = 0; j < n; ++j) {
      if (x[j] != (p[0] ^ b[j])) {
        ok = false;
        break;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (y[i] != (p[i] ^ b[0])) {
        ok = false;
        break;
      }
    }
    if (not ok) {
      continue;
    }
    ++cnt;
    res = p;
  }
  cout << '!' << endl;
  cout << cnt << endl;
  for (int i = 0; i < n; ++i) {
    cout << res[i];
    if (i < n - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }
}