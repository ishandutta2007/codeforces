#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int m = 256 * 255 / 2;
    int q = n / m, r = n - q * m;
    string res = "1" + string(256, '3');
    res.insert(3, string(r, '7'));
    res += string(q, '7');
    cout << res << '\n';
  }
}