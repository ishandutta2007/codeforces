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
  lint T; cin >> T;
  V<> x(n); for (int i = 0; i < n; ++i) cin >> x[i];
  V<> t(n); for (int i = 0; i < n; ++i) cin >> t[i];
  VV<> chi(n);
  V<> l(n);
  for (int v = 1; v < n; ++v) {
    int p;
    cin >> p >> l[v], --p;
    chi[p].push_back(v);
  }
  map<int, lint> mp;
  auto dfs = [&](const auto& dfs, int v, lint tl, lint s) -> lint {
    V< pair<int, lint> > memo;
    mp[t[v]] += x[v];
    memo.emplace_back(t[v], x[v]);
    s += x[v];
    tl -= (lint) t[v] * x[v];
    for (auto itr = --end(mp); tl < 0;) {
      lint y = min((-tl + itr->first - 1) / itr->first, itr->second);
      itr->second -= y;
      memo.emplace_back(itr->first, -y);
      s -= y;
      tl += itr->first * y;
      if (itr == begin(mp)) break;
      if (itr->second == 0) itr = --mp.erase(itr);
      else --itr;
    }
    lint mx0 = -1, mx1 = -1;
    if (tl >= 0) {
      for (int w : chi[v]) {
        lint curr = dfs(dfs, w, tl - 2 * l[w], s);
        if (curr > mx0) {
          mx1 = mx0;
          mx0 = curr;
        } else if (curr > mx1) {
          mx1 = curr;
        }
      }
    } else {
      s = -1;
    }
    for (const auto& e : memo) {
      mp[e.first] -= e.second;
      if (mp[e.first] == 0) mp.erase(e.first);
    }
    return max(s, v ? mx1 : mx0);
  };
  cout << dfs(dfs, 0, T, 0) << '\n';
}