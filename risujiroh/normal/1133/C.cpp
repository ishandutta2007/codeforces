#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int curr = upper_bound(begin(a), end(a), a[i] + 5) - begin(a);
    curr -= i;
    res = max(res, curr);
  }
  cout << res << '\n';
}