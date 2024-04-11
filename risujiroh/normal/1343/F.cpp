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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n - 1);
    vector<int> num(n);
    for (auto&& v : a) {
      int k;
      cin >> k;
      v.resize(k);
      for (auto&& e : v) {
        cin >> e;
        --e;
        ++num[e];
      }
    }
    for (int s = 0; s < n - 1; ++s) {
      if (size(a[s]) != 2) {
        continue;
      }
      auto res = a[s];
      vector<bool> used(n - 1), ex(n);
      used[s] = true;
      ex[a[s][0]] = ex[a[s][1]] = true;
      if (num[res[0]] > num[res[1]]) {
        swap(res[0], res[1]);
      }
      vector<int> ord{s};
      while ((int)size(res) < n) {
        int ni = -1;
        for (int i = 0; i < n - 1; ++i) {
          if (used[i]) {
            continue;
          }
          int cnt = 0;
          for (auto e : a[i]) {
            cnt += not ex[e];
          }
          if (cnt == 1) {
            ni = i;
            break;
          }
        }
        if (ni == -1) {
          break;
        }
        ord.push_back(ni);
        used[ni] = true;
        for (auto e : a[ni]) {
          if (not ex[e]) {
            res.push_back(e);
            ex[e] = true;
            break;
          }
        }
      }
      if ((int)size(res) != n) {
        continue;
      }
      assert((int)size(ord) == n - 1);
      bool ok = true;
      for (int k = 0; k < n - 1; ++k) {
        int i = ord[k];
        vector<int> t(begin(res) + (k + 2 - (int)size(a[i])), begin(res) + (k + 2));
        sort(begin(t), end(t));
        if (t != a[i]) {
          ok = false;
          break;
        }
      }
      if (not ok) {
        continue;
      }
      for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " \n"[i == n - 1];
      }
      DEBUG(res);
      break;
    }
  }
}