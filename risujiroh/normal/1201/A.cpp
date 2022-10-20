#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V< map<char, int> > mp(m);
  while (n--) {
    string s; cin >> s;
    for (int i = 0; i < m; ++i) {
      ++mp[i][s[i]];
    }
  }
  int res = 0;
  for (int i = 0; i < m; ++i) {
    int a; cin >> a;
    int mx = 0;
    for (const auto& e : mp[i]) {
      mx = max(mx, e.second);
    }
    res += a * mx;
  }
  cout << res << '\n';
}