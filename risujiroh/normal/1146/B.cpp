#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string t; cin >> t;
  int n = t.size();
  string u;
  for (int i = 0; i < n; ++i) if (t[i] != 'a') {
    u += t[i];
  }
  int m = u.size();
  if (m & 1) return cout << ":(" << '\n', 0;
  if (u.substr(0, m >> 1) != u.substr(m >> 1, m >> 1)) return cout << ":(" << '\n', 0;
  if (t.substr(n - (m >> 1), m >> 1) != u.substr(0, m >> 1)) return cout << ":(" << '\n', 0;
  cout << t.substr(0, n - (m >> 1)) << '\n';
}