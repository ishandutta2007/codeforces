#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    lint n; cin >> n;
    int res = 0;
    while (n > 1) {
      if (!(n % 2)) ++res, n /= 2;
      else if (!(n % 3)) res += 2, n /= 3;
      else if (!(n % 5)) res += 3, n /= 5;
      else {
        res = -1;
        break;
      }
    }
    cout << res << '\n';
  }
}