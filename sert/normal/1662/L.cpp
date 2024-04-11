#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll INF = static_cast<ll>(5e18) + 41;

pair<ll, ll> convert(ll a, ll t, ll v) {
  return {t * v + a, t * v - a};
}

ll solve() {
  int n;
  ll v;
  cin >> n >> v;
  vector<pair<ll, ll>> a(n);
  auto st = convert(0, 0, v);

  vector<ll> c(n), t(n);
  for (ll &x : t) cin >> x;
  for (ll &x : c) cin >> x;
  for (int i = 0; i < n; i++) {
    a[i] = convert(c[i], t[i], v);
  }

  sort(a.begin(), a.end());

  vector<ll> dp(n + 2, INF);
  dp[0] = -INF;
  dp[1] = st.second;
  ll ans = 1;

  for (auto q : a) {
    ll val = q.second;
    if (val < st.second || q.first < st.first) continue;
    auto pos = upper_bound(dp.begin(), dp.end(), val) - dp.begin();
    dp[pos] = val;
    ans = max(ans, static_cast<long long>(pos));
  }
  return ans - 1;
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
    //test();
    freopen("../a.in", "r", stdin);
    t = 4;
  }
  //cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }
}