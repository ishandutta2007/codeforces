#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  multiset<int> se;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    se.insert(x);
  }
  V<> res;
  for (int i = 0; i < n; ++i) {
    auto itr = se.lower_bound(n - a[i]);
    if (itr == end(se)) {
      itr = se.lower_bound(0);
    }
    res.push_back((a[i] + *itr) % n);
    se.erase(itr);
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " \n"[!(n + ~i)];
}