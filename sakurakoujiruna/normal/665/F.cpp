#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector <ll>;
#define pb push_back

unordered_map<ll, ll> cache; ll sz; vl pi, pl;
void ini(ll n = 30000000) {
  sz = n; pi.assign(n + 1, 1); pi[0] = pi[1] = 0;
  for (ll i = 2; i <= n; ++i) if (pi[i]) { pl.pb(i);
    if (n/i >= i) for (ll j=i*i; j<=n; j+=i) pi[j] = 0; }
  partial_sum(pi.begin(), pi.end(), pi.begin()); }
ll phi(ll x, ll a) {
  if (a == 1 || !x) return (x + 1) / 2;
  ll &r = cache[(x << 10) + a]; if (r) return r;
  return r = phi(x, a - 1) - phi(x / pl[a - 1], a - 1); }
ll get_pi(ll n) { // n = 1E12  4.2sec
  if (n < sz) return pi[n];
  ll a = get_pi(sqrt(sqrt(n))), b = get_pi(sqrt(n));
  ll c = get_pi(cbrt(n));
  ll r = phi(n, a) + (b + a - 2) * (b - a + 1) / 2;
  for (int i = a + 1; i <= b; ++i) {
    ll w = n / pl[i - 1]; r -= get_pi(w);
    if (i <= c) { int upp = get_pi(sqrt(w));
      for (int j = i; j <= upp; ++j)
        r += j - 1 - get_pi(w / pl[j - 1]); }} return r; }

int main() {
  ini();
  ios :: sync_with_stdio(0);
  ll n; cin >> n;
  ll ans = 0;
  for(ll i : pl)
    if(i * i * i <= n) ans ++;
    else break;
  for(ll i : pl) if(i * i <= n)
    ans += get_pi(n / i) - get_pi(i);
  cout << ans << '\n';
}