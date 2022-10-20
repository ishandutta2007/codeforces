#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    lint n, k; cin >> n >> k;
    lint res = 0;
    while (n) {
      if (n % k) {
        res += n % k;
        n -= n % k;
      } else {
        n /= k;
        ++res;
      }
    }
    cout << res << '\n';
  }
}