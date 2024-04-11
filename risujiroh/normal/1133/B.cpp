#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> c(k);
  for (int i = 0; i < n; ++i) {
    int d; cin >> d;
    ++c[d % k];
  }
  int res = c[0] >> 1 << 1;
  for (int i = 1; 2 * i < k; ++i) {
    res += 2 * min(c[i], c[k - i]);
  }
  if (~k & 1) res += c[k / 2] >> 1 << 1;
  cout << res << '\n';
}