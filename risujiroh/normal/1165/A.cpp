#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  reverse(begin(s), end(s));
  int res = 0;
  for (int i = 0; i < x; ++i) {
    if (i != y) res += s[i] == '1';
    else res += s[i] == '0';
  }
  cout << res << '\n';
}