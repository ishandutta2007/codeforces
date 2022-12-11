#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v(m);
  for (auto &[a, b] : v) cin >> a >> b;
  sort(v.begin(), v.end());
  vector<ll> suf(m + 1, 0ll);
  for (int i = m - 1; i >= 0; i--) suf[i] = suf[i + 1] + v[i].first;
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int top_sz = v.end() - lower_bound(v.begin(), v.end(), make_pair(v[i].second, -1));
    top_sz = min(n, top_sz);
    ll cur = suf[m - top_sz];
    if (top_sz < n) {
      if (i + top_sz < m) cur += v[i].first + (n - top_sz - 1) * 1ll * v[i].second;
      else cur += (n - top_sz) * 1ll * v[i].second;
    }
    if (cur > ans) ans = cur;
    // cout << i << " " << v[i].first << " " << v[i].second << " " << cur << endl;
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}