#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  if (n > (lint) k * (k - 1)) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  V< pair<int, int> > res;
  int b = 1, g = 2;
  for (int i = 0; i < n; ++i) if (i & 1) {
    res.emplace_back(res.back().second, res.back().first);
  } else {
    res.emplace_back(b, g);
    if (++g > k) {
      ++b;
      g = b + 1;
    }
  }
  for (const auto& e : res) {
    cout << e.first << ' ' << e.second << '\n';
  }
}