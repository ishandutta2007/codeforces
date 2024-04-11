#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    string x, y; cin >> x >> y;
    reverse(begin(x), end(x));
    reverse(begin(y), end(y));
    int i = y.find('1');
    int res = x.find('1', i) - i;
    cout << res << '\n';
  }
}