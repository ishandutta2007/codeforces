#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  VV<> a(n + 1, V<>(26));
  for (int i = 0; i < n; ++i) {
    a[i + 1] = a[i];
    ++a[i + 1][s[i] - 'a'];
  }
  int m; cin >> m;
  while (m--) {
    string t; cin >> t;
    V<> b(26);
    for (char c : t) ++b[c - 'a'];
    auto chk = [&](int x) -> bool {
      for (int k = 0; k < 26; ++k) {
        if (b[k] > a[x][k]) return false;
      }
      return true;
    };
    int ng = 0, ok = n;
    while (ok - ng > 1) {
      int mid = ng + ok >> 1;
      (chk(mid) ? ok : ng) = mid;
    }
    cout << ok << '\n';
  }
}