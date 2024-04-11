#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string l, r; cin >> l >> r;
  VV<> il(27), ir(27);
  for (int i = 0; i < n; ++i) {
    if (l[i] != '?') il[l[i] - 'a'].push_back(i);
    else il.back().push_back(i);
    if (r[i] != '?') ir[r[i] - 'a'].push_back(i);
    else ir.back().push_back(i);
  }
  V<> jl, jr;
  V< pair<int, int> > res;
  for (int i = 0; i < 26; ++i) {
    int mn = min(il[i].size(), ir[i].size());
    for (int j = 0; j < mn; ++j) {
      res.emplace_back(il[i][j], ir[i][j]);
    }
    for (int j = mn; j < il[i].size(); ++j) {
      jl.push_back(il[i][j]);
    }
    for (int j = mn; j < ir[i].size(); ++j) {
      jr.push_back(ir[i][j]);
    }
  }
  int mn = min(il.back().size(), jr.size());
  for (int i = 0; i < mn; ++i) {
    res.emplace_back(il.back()[i], jr[i]);
  }
  V<> kl;
  for (int i = mn; i < il.back().size(); ++i) {
    kl.push_back(il.back()[i]);
  }
  mn = min(ir.back().size(), jl.size());
  for (int i = 0; i < mn; ++i) {
    res.emplace_back(jl[i], ir.back()[i]);
  }
  V<> kr;
  for (int i = mn; i < ir.back().size(); ++i) {
    kr.push_back(ir.back()[i]);
  }
  mn = min(kl.size(), kr.size());
  for (int i = 0; i < mn; ++i) {
    res.emplace_back(kl[i], kr[i]);
  }
  cout << res.size() << '\n';
  for (const auto& e : res) {
    cout << e.first + 1 << ' ' << e.second + 1 << '\n';
  }
}