#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  string t; cin >> t;
  int n = t.size();
  V<string> s(3, string(n, 0));
  for (int i = 0; i < n; ++i) {
    s[0][i] = 'a' + i % 26;
    s[1][i] = 'a' + i / 26 % 26;
    s[2][i] = 'a' + i / 26 / 26;
  }
  V<string> r(3);
  for (int i = 0; i < 3; ++i) {
    cout << "? " << s[i] << endl;
    cin >> r[i];
  }
  V<> idx(n);
  for (int i = 0; i < n; ++i) {
    idx[i] = (r[0][i] - 'a') + 26 * (r[1][i] - 'a') + 26 * 26 * (r[2][i] - 'a');
  }
  string res(n, 0);
  for (int i = 0; i < n; ++i) {
    res[idx[i]] = t[i];
  }
  cout << "! " << res << endl;
}