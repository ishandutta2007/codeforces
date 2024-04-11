#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> p(n);
  for (int i = 0; i < n - 1; ++i) {
    lint q; cin >> q;
    p[i + 1] = p[i] + q;
  }
  lint mn = *min_element(begin(p), end(p));
  map<lint, int> mp;
  for (auto&& e : p) {
    e += 1 - mn;
    ++mp[e];
  }
  for (int i = 1; i <= n; ++i) {
    if (!mp.count(i)) return cout << -1 << '\n', 0;
  }
  for (int i = 0; i < n; ++i) {
    cout << p[i] << " \n"[i == n - 1];
  }
}