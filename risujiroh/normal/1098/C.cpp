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
  lint n, s; cin >> n >> s;
  if (s < 2 * n - 1 or s > n * (n + 1) / 2) return cout << "No" << '\n', 0;
  cout << "Yes" << '\n';
  if (s == n * (n + 1) / 2) {
    for (int i = 1; i < n; ++i) {
      cout << i << (i != n - 1 ? ' ' : '\n');
    }
    return 0;
  }
  auto calc = [&](int k) -> lint {
    if (k == 0) return 9e18;
    if (k == 1) return n * (n + 1) / 2;
    queue<int> que;
    int t = 0;
    que.push(t++);
    VV<> chi(n);
    while (t < n) {
      int v = que.front(); que.pop();
      while (t < n and chi[v].size() < k) {
        chi[v].push_back(t);
        que.push(t++);
      }
    }
    lint res = 0;
    auto dfs = [&](const auto& dfs, int v, int dep) -> void {
      res += dep;
      for (int w : chi[v]) {
        dfs(dfs, w, dep + 1);
      }
    };
    dfs(dfs, 0, 1);
    return res;
  };
  int ng = 0, ok = n;
  while (ok - ng > 1) {
    int mid = ng + ok >> 1;
    (calc(mid) <= s ? ok : ng) = mid;
  }
  int k = ng;
  queue<int> que;
  int t = 0;
  que.push(t++);
  VV<> chi(n);
  while (t < n) {
    int v = que.front(); que.pop();
    while (t < n and chi[v].size() < k) {
      chi[v].push_back(t);
      que.push(t++);
    }
  }
  V<> dep(n);
  auto dfs = [&](const auto& dfs, int v) -> void {
    for (int w : chi[v]) {
      dep[w] = dep[v] + 1;
      dfs(dfs, w);
    }
  };
  dep[0] = 1;
  dfs(dfs, 0);
  lint x = accumulate(begin(dep), end(dep), 0LL);
  set< pair<int, int> > se;
  for (int v = 0; v < n; ++v) {
    se.emplace(dep[v], v);
  }
  auto itr = begin(se);
  V<> par(n);
  for (int v = 0; v < n; ++v) for (int w : chi[v]) {
    par[w] = v;
  }
  while (x > s) {
    auto p = --end(se);
    while (x - (p->first - itr->first - 1) < s) {
      ++itr;
    }
    x -= p->first - itr->first - 1;
    int pv = p->second;
    se.erase(p);
    assert(chi[par[pv]].back() == pv);
    chi[par[pv]].pop_back();
    par[pv] = itr->second;
    se.emplace(itr->first + 1, pv);
    chi[itr->second].push_back(pv);
    while (chi[itr->second].size() == ok) {
      ++itr;
    }
  }
  for (int v = 1; v < n; ++v) {
    cout << par[v] + 1 << (v != n - 1 ? ' ' : '\n');
  }
}