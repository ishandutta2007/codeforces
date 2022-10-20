#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    [&] {
      string s; cin >> s;
      string o, e;
      for (char c : s) {
        (c & 1 ? o : e) += c;
      }
      sort(begin(o), end(o));
      sort(begin(e), end(e));
      if (o.empty() or e.empty()) return cout << o + e << '\n', 0;
      if (abs(o.back() - e[0]) != 1) return cout << o + e << '\n', 0;
      if (abs(e.back() - o[0]) != 1) return cout << e + o << '\n', 0;
      cout << "No answer" << '\n';
      return 0;
    }();
  }
}