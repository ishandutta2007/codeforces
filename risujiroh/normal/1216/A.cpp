#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  int res = 0;
  for (int i = 0; i < n; i += 2) {
    auto t = s.substr(i, 2);
    if (t == "aa") {
      s[i] = 'b';
      ++res;
    } else if (t == "bb") {
      s[i] = 'a';
      ++res;
    }
  }
  cout << res << '\n';
  cout << s << '\n';
}