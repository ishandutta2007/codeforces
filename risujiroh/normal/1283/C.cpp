#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  set<int> se;
  for (int i = 0; i < n; ++i) {
    se.insert(i);
  }
  for (auto&& e : a) {
    cin >> e;
    --e;
    se.erase(e);
  }
  vector<int> idx;
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      if (se.count(i)) {
        idx.push_back(i);
      }
    }
  }
  int m = idx.size();
  if (m == 1) {
    for (int i = 0; i < n; ++i) {
      if (i != idx[0] and a[i] == -1) {
        idx.push_back(i);
      }
    }
    for (int i : idx) {
      int x = *begin(se);
      if (x == i) {
        a[i] = *rbegin(se);
      } else {
        a[i] = x;
      }
      se.erase(a[i]);
    }
  } else {
    for (int t = 0; t < m; ++t) {
      a[idx[t]] = idx[(t + 1) % m];
      se.erase(idx[t]);
    }
    for (int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        a[i] = *begin(se);
        se.erase(a[i]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] + 1 << " \n"[i == n - 1];
  }
}