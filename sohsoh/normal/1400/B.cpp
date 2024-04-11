/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll solve() {
	ll p, f, n, m, s, w;
	cin >> p >> f >> n >> m >> s >> w;
	ll mx = min(n, p / s);
	ll ans = 0;
	ll pp = p, pf = f, pn = n, pm = m;
	for (int i = 0; i <= mx; i++) {
		ll tans = i;
		p -= i * s;
		n -= i;
		ll x = min(p / w, m);
		m -= x;
		tans += x;

		if (s < w) {
			ll x = min(n, f / s);
			tans += x;
			f -= x * s;
			tans += min(m, f / w);	
		} else {
			ll x = min(m, f / w);
			tans += x;
			f -= x * w;
			tans += min(n, f / s);
		}

		ans = max(tans, ans);
		p = pp;
		f = pf;
		n = pn;
		m = pm;
	}	

	cout << ans << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}