#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  V<> f(9); for (auto&& e : f) cin >> e;
  for (int i = 0; i < n; ++i) if (f[s[i] - '1'] > s[i] - '0') {
    for (int j = i; j < n; ++j) {
      if (f[s[j] - '1'] < s[j] - '0') break;
      s[j] = '0' + f[s[j] - '1'];
    }
    break;
  }
  cout << s << '\n';
}