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
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  V< pair<int, int> > b;
  int t = 1;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 or a[i] != a[i + 1]) {
      b.emplace_back(a[i], t);
      t = 1;
    } else {
      ++t;
    }
  }
  map< int, pair< int, int > > mp;
  int m = b.size();
  if (m == 1) return cout << "YES" << '\n', 0;
  for (int i = 0; i < m; ++i) mp[i] = b[i];
  using namespace chrono;
  auto start_t = steady_clock::now();
  while (duration_cast<milliseconds>(steady_clock::now() - start_t).count() < 1800) {
    for (auto itr = begin(mp); itr != end(mp); ++itr) {
      while (true) {
        auto& p0 = itr->second;
        while (itr != begin(mp) and prev(itr)->second.first == p0.first) {
          p0.second += prev(itr)->second.second;
          mp.erase(prev(itr));
        }
        while (itr != --end(mp) and p0.first == next(itr)->second.first) {
          p0.second += next(itr)->second.second;
          mp.erase(next(itr));
        }
        if (itr == --end(mp)) break;
        auto& p1 = next(itr)->second;
        if (p0.first < p1.first and ~p0.second & 1) {
          p0.first = p1.first;
          p0.second += p1.second;
          mp.erase(next(itr));
        } else if (p0.first > p1.first and ~p1.second & 1) {
          p0.second += p1.second;
          mp.erase(next(itr));
        } else break;
      }
      // for (const auto& e : mp) {
      //   cerr << e.second.first << ' ' << e.second.second << '\t';
      // }
      // cerr << endl;
    }
  }
  if (mp.size() > 1) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
}