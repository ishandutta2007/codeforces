#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n), c(101);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ++c[a[i]];
  }
  int t = 0;
  for (int i = 1; i < 101; ++i) t += !!c[i];
  if (t <= 2) return cout << n << '\n', 0;
  int res = 1;
  for (int x = 1; x < 101; ++x) if (c[x] > res) {
    for (int k = c[x]; k > res; --k) {
      V< bitset<10001> > dp(k + 1);
      dp[0][0] = true;
      for (int i = 0; i < n; ++i) if (a[i] != x) {
        for (int j = k; j > 0; --j) dp[j] |= dp[j - 1] << a[i];
      }
      for (int _ = 0; _ < k - 1; ++_) {
        for (int j = k; j > 0; --j) dp[j] |= dp[j - 1] << x;
      }
      if (!dp[k][k * x]) {
        res = max(res, k);
        break;
      }
    }
  }
  cout << res << '\n';
}