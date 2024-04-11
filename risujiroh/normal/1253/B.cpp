#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> c(1e6 + 1);
  int num = 0;
  V<> res;
  int p = 0;
  set<int> se;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      if (c[-a[i]] != 1) {
        return cout << -1 << '\n', 0;
      }
      c[-a[i]] = 0;
      --num;
    } else {
      if (c[a[i]] != 0 or se.count(a[i])) {
        return cout << -1 << '\n', 0;
      }
      c[a[i]] = 1;
      ++num;
      se.insert(a[i]);
    }
    if (num == 0) {
      res.push_back(i + 1 - p);
      p = i + 1;
      set<int>().swap(se);
    }
  }
  if (num) {
    return cout << -1 << '\n', 0;
  }
  int m = res.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[i == m - 1];
  }
}