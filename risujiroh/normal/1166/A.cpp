#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> c(26);
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    ++c[s[0] - 'a'];
  }
  int res = 0;
  for (int e : c) {
    int x = e / 2, y = e - x;
    res += x * (x - 1) / 2 + y * (y - 1) / 2;
  }
  cout << res << '\n';
}