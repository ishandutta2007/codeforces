#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    int a, b, c; cin >> a >> b >> c;
    string s; cin >> s;
    string t(n, 0);
    int w = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'R') {
        if (b) t[i] = 'P', --b, ++w;
      } else if (s[i] == 'P') {
        if (c) t[i] = 'S', --c, ++w;
      } else {
        if (a) t[i] = 'R', --a, ++w;
      }
    }
    for (int i = 0; i < n; ++i) if (t[i] == 0) {
      if (a) t[i] = 'R', --a;
      else if (b) t[i] = 'P', --b;
      else {
        assert(c);
        t[i] = 'S', --c;
      }
    }
    if (2 * w >= n) {
      cout << "YES" << '\n';
      cout << t << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
}