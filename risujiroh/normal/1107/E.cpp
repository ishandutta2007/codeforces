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
  int n; cin >> n;
  string s; cin >> s;
  V<> a(n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];
  VV< V<lint> > memo; assign(memo, n, n, n, -1);
  // [l, r]  x  max
  auto rec = [&](const auto& rec, int l, int r, int x) -> lint {
    if (l > r) return a[x];
    if (memo[l][r][x] != -1) return memo[l][r][x];
    lint res = a[x + 1] + rec(rec, l + 1, r, 0);
    for (int i = l + 1; i <= r; ++i) if (s[i] == s[l]) {
      res = max(res, rec(rec, l + 1, i - 1, 0) + rec(rec, i, r, x + 1));
    }
    return memo[l][r][x] = res;
  };
  cout << rec(rec, 0, n - 1, 0) << '\n';
}