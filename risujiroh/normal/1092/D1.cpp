#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i], a[i] &= 1;
  V<> b;
  int t = 1;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 or a[i] != a[i + 1]) {
      b.push_back(t);
      t = 1;
    } else {
      ++t;
    }
  }
  map<int, int> mp;
  int m = b.size();
  if (m == 1) return cout << "YES" << '\n', 0;
  for (int i = 0; i < m; ++i) mp[i] = b[i];
  for (auto itr = begin(mp); itr != end(mp); ++itr) {
    while (~itr->second & 1) {
      if (itr == begin(mp)) {
        itr->second += next(itr)->second;
        mp.erase(next(itr));
      } else if (itr == --end(mp)) {
        itr->second += prev(itr)->second;
        mp.erase(prev(itr));
      } else {
        itr->second += prev(itr)->second + next(itr)->second;
        mp.erase(prev(itr));
        mp.erase(next(itr));
      }
      if (mp.size() <= 2) break;
    }
    if (mp.size() <= 2) break;
  }
  if (mp.size() > 2) return cout << "NO" << '\n', 0;
  if (begin(mp)->second & 1 and next(begin(mp))->second & 1) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
}