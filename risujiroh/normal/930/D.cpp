#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

long long fn(const vector<pair<int, int>>& p) {
  constexpr int n = 2e5 + 1;
  vector<int> mn(n, inf<int>), mx(n, -inf<int>);
  for (auto [x, y] : p) {
    mn[x] = min(mn[x], y);
    mx[x] = max(mx[x], y);
  }
  vector lmn(n + 1, inf<int>), rmn = lmn;
  vector lmx(n + 1, -inf<int>), rmx = lmx;
  for (int i = 0; i < n; ++i) {
    lmn[i + 1] = min(lmn[i], mn[i]);
    lmx[i + 1] = max(lmx[i], mx[i]);
  }
  for (int i = n; i--; ) {
    rmn[i] = min(mn[i], rmn[i + 1]);
    rmx[i] = max(mx[i], rmx[i + 1]);
  }
  long long res = 0;
  for (int i = 1; i < n; ++i) {
    res += max(min(lmx[i], rmx[i]) - max(lmn[i], rmn[i]), 0);
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int>> p0, p1;
  while (n--) {
    int x, y;
    cin >> x >> y;
    if ((x + y) % 2 == 0) {
      p0.emplace_back((x - y) / 2 + 1e5, (x + y) / 2 + 1e5);
    } else {
      ++x;
      p1.emplace_back((x - y) / 2 + 1e5, (x + y) / 2 + 1e5);
    }
  }
  cout << fn(p0) + fn(p1) << '\n';
}