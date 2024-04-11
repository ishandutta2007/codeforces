#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  lint res = (lint)n * (n + 1) / 2;
  for (int l = 0; l < n; ++l) for (int r = l + 1; r <= min(l + 8, n); ++r) {
    string t = s.substr(l, r - l);
    int m = t.size();
    bool be = false;
    for (int i = 0; i < m; ++i) for (int j = i + 2; j < m; j += 2) {
      int k = i + j >> 1;
      if (t[i] == t[k] and t[k] == t[j]) {
        be = true;
        break;
      }
    }
    if (be) continue;
    --res;
  }
  cout << res << '\n';
}