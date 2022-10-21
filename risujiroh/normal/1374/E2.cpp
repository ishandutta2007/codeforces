#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

struct ds {
  multiset<int> lower, upper;
  int sum = 0;
  void insert(int x) {
    upper.insert(x);
  }
  void erase(int x) {
    if (lower.find(x) != end(lower)) {
      lower.erase(lower.find(x));
      sum -= x;
    } else {
      assert(upper.find(x) != end(upper));
      upper.erase(upper.find(x));
    }
  }
  int query(int k) {
    assert((int)size(lower) + (int)size(upper) >= k);
    while ((int)size(lower) < k) {
      assert(not empty(upper));
      auto it = begin(upper);
      lower.insert(*it);
      sum += *it;
      upper.erase(it);
    }
    while ((int)size(lower) > k) {
      assert(not empty(lower));
      auto it = prev(end(lower));
      upper.insert(*it);
      sum -= *it;
      lower.erase(it);
    }
    return sum;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> x, y, z;
  vector<int> t(n), a(n), b(n);
  ds d;
  for (int i = 0; i < n; ++i) {
    cin >> t[i] >> a[i] >> b[i];
    if (a[i] and b[i]) {
      z.push_back(t[i]);
    } else if (a[i]) {
      x.push_back(t[i]);
    } else if (b[i]) {
      y.push_back(t[i]);
    } else {
      d.insert(t[i]);
    }
  }
  int nx = size(x);
  int ny = size(y);
  int nz = size(z);
  if (nz + min(nx, ny) < k) {
    cout << "-1\n";
    exit(0);
  }
  sort(begin(x), end(x));
  sort(begin(y), end(y));
  sort(begin(z), end(z));
  partial_sum(begin(x), end(x), begin(x));
  partial_sum(begin(y), end(y), begin(y));
  partial_sum(begin(z), end(z), begin(z));
  x.insert(begin(x), 0);
  y.insert(begin(y), 0);
  z.insert(begin(z), 0);
  for (int i = 0; i < nz; ++i) {
    d.insert(z[i + 1] - z[i]);
  }
  for (int i = k; i < nx; ++i) {
    d.insert(x[i + 1] - x[i]);
  }
  for (int i = k; i < ny; ++i) {
    d.insert(y[i + 1] - y[i]);
  }
  int res = numeric_limits<int>::max(), mi = -1;
  for (int i = 0; i <= min(k, nz); ++i) {
    int j = k - i;
    if (i) {
      d.erase(z[i] - z[i - 1]);
      if (0 <= j and j < nx) {
        d.insert(x[j + 1] - x[j]);
      }
      if (0 <= j and j < ny) {
        d.insert(y[j + 1] - y[j]);
      }
    }
    if (j > min(nx, ny)) continue;
    int r = m - i - 2 * j;
    if (r < 0) continue;
    if (chmin(res, z[i] + x[j] + y[j] + d.query(r))) {
      mi = i;
    }
  }
  if (mi == -1) {
    cout << "-1\n";
    exit(0);
  }
  DEBUG(nx, ny, nz, mi);
  cout << res << '\n';
  vector<int> idx, ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return t[i] < t[j];
  });
  vector<bool> used(n);
  for (int i : ord) {
    if (a[i] and b[i]) {
      if (mi-- > 0) {
        used[i] = true;
        idx.push_back(i);
      }
    }
  }
  mi = size(idx);
  int ca = max(k - mi, 0), cb = ca;
  for (int i : ord) {
    if (a[i] and b[i]) continue;
    if (a[i]) {
      if (ca-- > 0) {
        used[i] = true;
        idx.push_back(i);
      }
    } else if (b[i]) {
      if (cb-- > 0) {
        used[i] = true;
        idx.push_back(i);
      }
    }
  }
  int rest = m - size(idx);
  assert(rest >= 0);
  for (int i : ord) {
    if (used[i]) continue;
    if (rest-- > 0) {
      used[i] = true;
      idx.push_back(i);
    }
  }
  for (int i = 0; i < (int)size(idx); ++i) {
    cout << idx[i] + 1 << " \n"[i == (int)size(idx) - 1];
  }
}