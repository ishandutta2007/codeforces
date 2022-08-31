#include <bits/stdc++.h>
 
using namespace std;
 
struct fenwick {
  vector<int> fenw;
  int n, v;
 
  fenwick(int n, int v) : n(n), v(v) {
    fenw = vector<int>(n, v);
  }
 
  void modify(int x, int v) {
    while (x < n) {
      fenw[x] = min(fenw[x], v);
      x |= x + 1;
    }
  }
 
  int query(int x) {
    int res = v;
    while (x >= 0) {
      res = min(res, fenw[x]);
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};
 
int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> d = a;
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(d.begin(), d.end(), a[i]) - d.begin();
  }
  for (int i = 0; i < n; ++i) {
    a.push_back(a[i]);
  }
  int m = d.size();
  fenwick fenw_larger(m, n * 2);
  fenwick fenw_smaller(m, n * 2);
  vector<int> larger(n);
  vector<int> smaller(n);
  for (int i = n * 2 - 1; ~i; --i) {
    if (i < n) {
      larger[i] = fenw_larger.query(m - 2 - a[i]);
      smaller[i] = fenw_smaller.query(lower_bound(d.begin(), d.end(), (d[a[i]] + 1) / 2) - d.begin() - 1);
    }
    fenw_larger.modify(m - a[i] - 1, i);
    fenw_smaller.modify(a[i], i);
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int x, int y) { return a[x] > a[y]; });
  vector<int> ans(n);
  for (int i : order) {
    if (larger[i] < smaller[i]) {
      if (larger[i] >= n) {
        if (ans[larger[i] - n] == -1) {
          ans[i] = -1;
        } else {
          ans[i] = ans[larger[i] - n] + larger[i] - i;
        }
      } else {
        if (ans[larger[i]] == -1) {
          ans[i] = -1;
        } else {
          ans[i] = ans[larger[i]] + larger[i] - i;
        }
      }
    } else if (smaller[i] == n * 2) {
      ans[i] = -1;
    } else {
      ans[i] = smaller[i] - i;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}