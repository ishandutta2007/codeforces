#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    int odd = 0, zero = 0, one = 0;
    for (int _ = 0; _ < n; ++_) {
      string s; cin >> s;
      int m = s.size();
      odd += m & 1;
      zero += count(begin(s), end(s), '0');
      one += count(begin(s), end(s), '1');
    }
    if (odd) {
      cout << n << '\n';
    } else if (zero & 1 or one & 1) {
      cout << n - 1 << '\n';
    } else {
      cout << n << '\n';
    }
  }
}