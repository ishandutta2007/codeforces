#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    s += '0';
    V<lint> dp0(n + 1, 1e18), dp1(n + 1, 1e18);
    dp0[0] = b;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0' and s[i + 1] == '0') {
        dp0[i + 1] = min(dp0[i + 1], dp0[i] + b + a);
        dp1[i + 1] = min(dp1[i + 1], dp0[i] + 2 * b + 2 * a);
        dp0[i + 1] = min(dp0[i + 1], dp1[i] + b + 2 * a);
        dp1[i + 1] = min(dp1[i + 1], dp1[i] + 2 * b + a);
      } else {
        dp1[i + 1] = min(dp1[i + 1], dp0[i] + 2 * b + 2 * a);
        dp1[i + 1] = min(dp1[i + 1], dp1[i] + 2 * b + a);
      }
    }
    cout << dp0.back() << '\n';
  }
}