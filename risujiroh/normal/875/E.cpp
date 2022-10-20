#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, s, t;
  cin >> n >> s >> t;
  vector<int> x(n);
  for (auto&& e : x) {
    cin >> e;
  }
  auto chk = [&](int m) {
    set<int> se;
    if (abs(x[0] - s) <= m) {
      se.insert(s);
    }
    if (abs(x[0] - t) <= m) {
      se.insert(t);
    }
    for (int i = 1; i < n; ++i) {
      if (empty(se)) {
        return false;
      }
      se.erase(x[i]);
      if (abs(x[i] - x[i - 1]) <= m) {
        se.insert(x[i - 1]);
      }
      se.erase(se.upper_bound(x[i] + m), end(se));
      se.erase(begin(se), se.lower_bound(x[i] - m));
    }
    return not empty(se);
  };
  int ng = abs(t - s) - 1, ok = 1e9;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}