#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  string a, b; cin >> a >> b;
  V<> dp(n + 1);
  dp[1] = a[0] != b[0];
  for (int i = 1; i < n; i++) {
    if (a[i] == b[i]) dp[i + 1] = dp[i];
    else if (a[i - 1] != b[i - 1] and a[i] != a[i - 1]) dp[i + 1] = dp[i - 1] + 1;
    else dp[i + 1] = dp[i] + 1;
  }
  cout << dp[n] << '\n';
}