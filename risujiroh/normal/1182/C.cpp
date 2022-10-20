#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  const string vowels = "aeoiu";
  int n; cin >> n;
  V<string> s(n); for (auto&& e : s) cin >> e;
  V<> a(n), b(n);
  VV<> c;
  VV< V<> > idx;
  for (int i = 0; i < n; ++i) {
    for (char c : vowels) {
      a[i] += count(begin(s[i]), end(s[i]), c);
    }
    for (int j = (int)s[i].size() - 1; j >= 0; --j) {
      b[i] = vowels.find(s[i][j]);
      if (b[i] != -1) break;
    }
    while (a[i] >= (int)c.size()) c.emplace_back(5);
    while (a[i] >= (int)idx.size()) idx.emplace_back(5);
    ++c[a[i]][b[i]];
    idx[a[i]][b[i]].push_back(i);
  }
  int x = 0, y = 0;
  for (const auto& v : c) {
    x += accumulate(begin(v), end(v), 0) >> 1;
    for (int e : v) y += e >> 1;
  }
  int m = min(x >> 1, y);
  VV<> res(m);
  [&] {
    int p = 0;
    for (auto&& v : idx) for (auto&& w : v) {
      while (p < m and w.size() >= 2) {
        res[p].push_back(w.back()), w.pop_back();
        res[p].push_back(w.back()), w.pop_back();
        ++p;
      }
    }
  }();
  [&] {
    int p = 0;
    for (auto&& v : idx) {
      V<> w;
      for (auto&& x : v) {
        w.insert(end(w), begin(x), end(x));
      }
      while (p < m and w.size() >= 2) {
        res[p].push_back(w.back()), w.pop_back();
        res[p].push_back(w.back()), w.pop_back();
        ++p;
      }
    }
  }();
  cout << m << '\n';
  for (const auto& e : res) {
    cout << s[e[2]] << ' ' << s[e[0]] << '\n';
    cout << s[e[3]] << ' ' << s[e[1]] << '\n';
  }
}