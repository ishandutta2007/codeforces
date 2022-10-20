#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    map<int, int> mp;
    while (n--) {
      int s; cin >> s;
      ++mp[__lg(s)];
    }
    bool ok = false;
    while (!mp.empty()) {
      if (mp.count(11)) {
        ok = true;
        break;
      }
      auto itr = begin(mp);
      if (itr->second == 1) {
        mp.erase(itr);
      } else {
        itr->second -= 2;
        ++mp[itr->first + 1];
        if (!itr->second) {
          mp.erase(itr);
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}