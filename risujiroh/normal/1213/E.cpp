#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s, t; cin >> s >> t;
  auto chk = [&](const string& a) -> bool {
    for (int i = 0; i < (int)a.size(); ++i) {
      if (a.substr(i, 2) == s) return false;
      if (a.substr(i, 2) == t) return false;
    }
    return true;
  };
  cout << "YES" << '\n';
  string x = "abc";
  do {
    string res;
    for (int _ = 0; _ < n; ++_) res += x;
    if (chk(res)) {
      return cout << res << '\n', 0;
    }
    res = string(n, x[0]) + string(n, x[1]) + string(n, x[2]);
    if (chk(res)) {
      return cout << res << '\n', 0;
    }
  } while (next_permutation(begin(x), end(x)));
  assert(false);
}