#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  if (n & 1) return cout << "No" << '\n', 0;
  if (2 * count(begin(s), end(s), '(') != n) return cout << "No" << '\n', 0;
  int t = 0, mn = 0;
  for (char c : s) {
    if (c == '(') ++t;
    else --t;
    mn = min(mn, t);
  }
  if (mn < -1) return cout << "No" << '\n', 0;
  cout << "Yes" << '\n';
}