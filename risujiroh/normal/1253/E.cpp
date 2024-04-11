#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

constexpr int inf = 0x3f3f3f3f;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  struct LR { 
    int l, r; 
    bool operator<(const LR& rhs) const { return r < rhs.r; }
  };
  V<LR> v;
  for (int i = 0; i < n; ++i) {
    int x, s; cin >> x >> s, --x;
    v.emplace_back(LR{max(x - s, 0), min(x + s + 1, m)});
  }
  sort(begin(v), end(v));
  V<> dp(m + 1, inf);
  dp[0] = 0;
  for (const auto& e : v) {
    for (int x = e.l + 1; x <= e.r; ++x) {
      dp[x] = min(dp[x], dp[e.l]);
    }
    for (int d = 0; d < m; ++d) {
      dp[min(e.r + d, m)] = min(dp[min(e.r + d, m)], dp[max(e.l - d, 0)] + d);
    }
    for (int x = m - 1; x >= 0; --x) {
      dp[x] = min(dp[x], dp[x + 1]);
    }
  }
  cout << dp[m] << '\n';
}