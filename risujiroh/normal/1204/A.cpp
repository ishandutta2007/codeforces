#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  if (s == "0") return cout << 0 << '\n', 0;
  if (s == "10") return cout << 1 << '\n', 0;
  int res = s.size() + 1 >> 1;
  res -= s.size() & 1 and count(begin(s), end(s), '1') == 1;
  cout << res << '\n';
}