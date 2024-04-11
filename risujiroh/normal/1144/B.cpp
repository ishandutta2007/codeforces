#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  int odd = 0, even = 0;
  V<> b, c;
  for (int i = 0; i < n; ++i) {
    if (a[i] & 1) {
      ++odd;
      b.push_back(a[i]);
    } else {
      ++even;
      c.push_back(a[i]);
    }
  }
  sort(begin(b), end(b));
  sort(begin(c), end(c));
  if (even + 1 < odd) {
    int t = max(odd - even - 1, 0);
    int res = accumulate(begin(b), begin(b) + t, 0);
    cout << res << '\n';
  } else if (odd + 1 < even) {
    int t = max(even - odd - 1, 0);
    int res = accumulate(begin(c), begin(c) + t, 0);
    cout << res << '\n';
  } else {
    cout << 0 << '\n';
  }
}