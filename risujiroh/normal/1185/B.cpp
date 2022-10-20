#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    string s, t; cin >> s >> t;
    char c = 0;
    while (!t.empty()) {
      if (!s.empty() and s.back() == t.back()) {
        c = s.back();
        s.pop_back();
        t.pop_back();
      } else if (t.back() == c) {
        t.pop_back();
      } else break;
    }
    cout << (s.empty() and t.empty() ? "YES" : "NO") << '\n';
  }
}