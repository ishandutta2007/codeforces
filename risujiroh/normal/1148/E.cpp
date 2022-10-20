#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> s(n); for (auto&& e : s) cin >> e;
  V<> t(n); for (auto&& e : t) cin >> e;
  sort(begin(t), end(t));
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return s[i] < s[j]; });
  V<> v;
  VV<> res;
  for (int k = 0; k < n; ++k) {
    int i = idx[k];
    if (s[i] < t[k]) v.push_back(k);
    else {
      while (t[k] < s[i]) {
        if (v.empty()) return cout << "NO" << '\n', 0;
        int d = min(t[v.back()] - s[idx[v.back()]], s[i] - t[k]);
        res.emplace_back(V<>{idx[v.back()], i, d});
        s[idx[v.back()]] += d;
        s[i] -= d;
        if (t[v.back()] == s[idx[v.back()]]) v.pop_back();
      }
    }
  }
  if (!v.empty()) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  int m = res.size();
  cout << m << '\n';
  for (const auto& v : res) {
    cout << v[0] + 1 << ' ' << v[1] + 1 << ' ' << v[2] << '\n';
  }
}