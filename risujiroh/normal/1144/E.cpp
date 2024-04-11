#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s, t; cin >> s >> t;
  V<> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    a[n - 1 - i] = s[i] - 'a';
    b[n - 1 - i] = t[i] - 'a';
  }
  V<> c(n + 1);
  for (int i = 0; i < n; ++i) {
    c[i] += a[i] + b[i];
    if (c[i] >= 26) {
      ++c[i + 1];
      c[i] -= 26;
    }
  }
  V<> d(n);
  reverse(begin(c), end(c));
  for (int i = 0; i < n; ++i) {
    int x = c[i] * 26 + c[i + 1];
    d[i] = x / 2;
    x -= 2 * d[i];
    c[i] = 0;
    c[i + 1] = x;
  }
  for (int i = 0; i < n; ++i) {
    cout << (char) ('a' + d[i]);
  }
  cout << '\n';
}