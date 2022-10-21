#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  bool ok = []() -> bool {
    int n; cin >> n;
    V<> a(n); for (auto&& e : a) cin >> e;
    sort(begin(a), end(a));
    map<int, int> mp;
    for (int e : a) ++mp[e];
    V<> c;
    for (const auto& e : mp) c.push_back(e.second);
    sort(rbegin(c), rend(c));
    if (c[0] >= 3) return false;
    if (c.size() > 1 and c[1] >= 2) return false;
    bool t = false;
    if (c[0] == 2) {
      int x = -1;
      for (const auto& e : mp) if (e.second == 2) {
        x = e.first;
      }
      if (!x) return false;
      if (mp.count(x - 1)) return false;
      for (auto&& e : a) if (e == x) {
        --e;
        break;
      }
      t = true;
    }
    lint s = 0;
    for (int i = 0; i < n; ++i) s += a[i] - i;
    return s & 1 ^ t;
  }();
  cout << (ok ? "sjfnb" : "cslnb") << '\n';
}