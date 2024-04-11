#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<lint> dp(10, -1e18);
  dp[0] = 0;
  while (n--) {
    int k; cin >> k;
    VV<> a(4);
    while (k--) {
      int c, d; cin >> c >> d;
      a[c].push_back(d);
    }
    for (auto&& v : a) sort(rbegin(v), rend(v));
    V<> c, d;
    for (int i = 0; i < min<int>(a[1].size(), 3); ++i) {
      c.push_back(1);
      d.push_back(a[1][i]);
    }
    if (!a[2].empty()) {
      c.push_back(2);
      d.push_back(a[2][0]);
    }
    if (!a[3].empty()) {
      c.push_back(3);
      d.push_back(a[3][0]);
    }
    int m = c.size();
    auto ndp = dp;
    for (int bit = 0; bit < 1 << m; ++bit) {
      int sc = 0, mx = 0;
      lint sd = 0;
      for (int i = 0; i < m; ++i) if (bit >> i & 1) {
        sc += c[i];
        sd += d[i];
        mx = max(mx, d[i]);
      }
      if (sc > 3) continue;
      for (int x = 0; x < 10; ++x) {
        int pc = __builtin_popcount(bit);
        if (x + pc >= 10) {
          ndp[x + pc - 10] = max(ndp[x + pc - 10], dp[x] + sd + mx);
        } else {
          ndp[x + pc] = max(ndp[x + pc], dp[x] + sd);
        }
      }
    }
    swap(dp, ndp);
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
}