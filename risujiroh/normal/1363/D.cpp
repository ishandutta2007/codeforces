#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int query(int from, int to, const vector<int>& ex = {}) {
  vector<int> idx;
  for (int i = from; i <= to; ++i) {
    if (binary_search(begin(ex), end(ex), i)) continue;
    idx.push_back(i);
  }
  cout << "? " << size(idx);
  for (auto e : idx) {
    cout << ' ' << e + 1;
  }
  cout << endl;
  int x;
  cin >> x;
  return x;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> idx(k);
    vector<int> id(n, -1);
    for (int t = 0; t < k; ++t) {
      int c;
      cin >> c;
      idx[t].resize(c);
      for (auto&& e : idx[t]) {
        cin >> e;
        --e;
        id[e] = t;
      }
      sort(begin(idx[t]), end(idx[t]));
    }
    int mx = query(0, n - 1);
    int from = 0, to = n - 1;
    while (from < to) {
      int mid = (from + to) / 2;
      if (query(from, mid) == mx) {
        to = mid;
      } else {
        from = mid + 1;
      }
    }
    vector<int> res(k, mx);
    if (id[from] != -1) {
      res[id[from]] = query(0, n - 1, idx[id[from]]);
    }
    cout << '!';
    for (auto e : res) {
      cout << ' ' << e;
    }
    cout << endl;
    string s;
    cin >> s;
  }
}