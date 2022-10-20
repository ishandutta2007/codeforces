#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  int m = (n - k) / 2 + 1;
  string res(n, '0');
  if (k == 1) res[0] = '1';
  else {
    for (int i = 0; i < n; i += m) {
      res[i] = '1';
    }
  }
  cout << res << '\n';
}