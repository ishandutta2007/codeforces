#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, c; cin >> n >> c, --c;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
  V<> cc(n + 1);
  for (int i = 0; i < n; ++i) cc[i + 1] = cc[i] + (a[i] == c);
  VV<> ids(500'000);
  for (int i = 0; i < n; ++i) ids[a[i]].push_back(i);
  int res = 0;
  for (int x = 0; x < 500'000; ++x) if (x != c) {
    int m = ids[x].size();
    if (!m) continue;
    V<> dp(m);
    dp[0] = 1;
    for (int i = 1; i < m; ++i) {
      dp[i] = max(dp[i - 1] + 1 - (cc[ids[x][i]] - cc[ids[x][i - 1]]), 1);
    }
    res = max(res, *max_element(begin(dp), end(dp)));
  }
  cout << cc[n] + res << '\n';
}