#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  multiset<int> se;
  int res = 0;
  V<> c(1e5 + 1);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    if (c[a]) {
      se.erase(se.lower_bound(c[a]));
    }
    se.insert(++c[a]);
    if ((int)se.size() == 1 or *prev(end(se)) - *begin(se) == 1 and *prev(end(se), 2) == *begin(se) or *begin(se) == 1 and *next(begin(se)) == *prev(end(se))) {
      res = i + 1;
    }
  }
  cout << res << '\n';
}