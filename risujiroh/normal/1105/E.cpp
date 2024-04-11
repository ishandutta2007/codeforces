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
  using namespace chrono;
  auto start_t = steady_clock::now();
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V< pair<int, string> > in(n);
  set<string> names;
  for (int i = 0; i < n; ++i) {
    cin >> in[i].first;
    if (in[i].first == 2) {
      cin >> in[i].second;
      names.insert(in[i].second);
    }
  }
  map<string, int> mp;
  int id = 0;
  for (int i = 0; i < n; ++i) if (in[i].first == 2) {
    if (mp.count(in[i].second)) continue;
    mp[in[i].second] = id++;
  }
  VV<> g; assign(g, m, m, 0);
  set<int> se;
  for (int i = 0; i <= n; ++i) {
    if (i == n or in[i].first == 1) {
      for (int v : se) for (int w : se) if (v != w) {
        g[v][w] = 1;
      }
      set<int>().swap(se);
    } else {
      se.insert(mp[in[i].second]);
    }
  }
  V<> vs(m);
  iota(begin(vs), end(vs), 0);
  mt19937 mt(steady_clock::now().time_since_epoch().count());
  int res = 0;
  while (duration_cast<milliseconds>(steady_clock::now() - start_t).count() < 1800) {
    V<> a;
    for (int v : vs) {
      if (all_of(begin(a), end(a), [&](int e) { return g[e][v] == 0; })) {
        a.push_back(v);
      }
    }
    res = max<int>(res, a.size());
    shuffle(begin(vs), end(vs), mt);
  }
  cout << res << '\n';
}