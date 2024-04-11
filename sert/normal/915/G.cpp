#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const int N = (int)2e6 + 34;

ll step(ll a, ll deg) {
  if (deg == 0) return 1;
  if (deg % 2) return step(a, deg - 1) * a % MD;
  ll q = step(a, deg / 2);
  return q * q % MD;
}

void solve() {
  ll n, k;
  cin >> n >> k;

  vector<ll> powN(N);
  powN[0] = 0;
  for (int i = 1; i < N; i++)
    powN[i] = step(i, n);

  vector<ll> add(k + 1, 0);

  vector<vector<int>> div(k + 1);
  for (int d = 2; d <= k; d++)
    for (int x = d; x <= k; x += d)
      div[x].push_back(d);
  
  vector<ll> koef(k + 1, 0);
  for (int mx = 1; mx <= k; mx++) {
    ll ad = 0;

    ll cnt = 0;
    for (int d : div[mx])
      cnt += koef[d];
    koef[mx] = 1 - cnt;

    for (int d : div[mx]) {      
      int t = mx / d;
      ad += koef[d] * (powN[t] - powN[t - 1]);
    }    

    add[mx] = (add[mx - 1] + ad + MD * MD) % MD;
  }

  ll ans = 0;
  for (int mx = 1; mx <= k; mx++) {    
    ll cur = (powN[mx] - add[mx] + MD) % MD;
    ans += mx ^ cur;
  }

  cout << ans % MD << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;  

#ifdef SERT
  t = 2;
#endif

  for (int i = 0; i < t; i++)
    solve();
}