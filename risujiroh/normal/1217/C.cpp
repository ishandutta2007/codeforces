#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    string s; cin >> s;
    int n = s.size();
    int res = count(begin(s), end(s), '1');
    for (int i = 0; i < n; ++i) {
      res += s.substr(i, 2) == "10";
    }

    int z = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] == '0') {
        ++z;
        if (s[i + 1] == '1') {
          for (int k = 1; k <= 18 and i + 1 + k <= n; ++k) {
            int x = stoi(s.substr(i + 1, k), nullptr, 2);
            res += x >= 3 and x - (1 + __lg(x)) <= z;
          }
        }
      } else {
        z = 0;
      }
    }
    cout << res << '\n';
  }
}