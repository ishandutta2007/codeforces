#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = static_cast<ll>(1e18) + 41;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> p(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> p[i + 1];
    p[i + 1] += p[i];
  }

  vector<ll> ice(m);
  for (ll &x : ice) {
    cin >> x;
  }
  sort(ice.begin(), ice.end());
  ice.push_back(INF);

  int curIce = -1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll cur = i * 100;
    while (ice[curIce + 1] <= cur) {
      curIce++;
    }
    if (ice[curIce] == cur) continue;

    ll pos = (curIce == -1 ? ice[curIce + 1] : min(cur * 2 - ice[curIce], ice[curIce + 1]));
    ll mx = (pos + ice[curIce + 1] - 1) / 2;

    ans = max(ans, p[min(static_cast<ll>(n), mx / 100 + 1)] - p[i]);
  }

  cout << ans << "\n";
}

#ifdef SERT
bool D = true;
#else
bool D = false;
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  if (D) {
    freopen("../a.in", "r", stdin);
    t = 4;
  }
  //cin >> t;
  while (t--) {
    solve();
  }
}