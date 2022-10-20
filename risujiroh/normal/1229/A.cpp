#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> a(n);
  map<lint, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++mp[a[i]];
  }
  V<> b(n); for (auto&& e : b) cin >> e;
  
  lint res = 0;
  for (int i = 0; i < n; ++i) if (mp[a[i]] >= 2) {
    res += b[i];
  } else {
    bool ok = false;
    for (const auto& e : mp) if (e.second >= 2) {
      if ((a[i] | e.first)  == e.first) {
        ok = true;
        break;
      }
    }
    if (ok) {
      res += b[i];
    }
  }
  cout << res << '\n';
}