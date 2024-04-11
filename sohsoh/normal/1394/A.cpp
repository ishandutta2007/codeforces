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
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll ps_b[MAXN] = {0}, ps_s[MAXN] = {0}, n, d, m, sum = 0;
vector<ll> b, s;

int main() {
	fast_io;
	cin >> n >> d >> m;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x > m) b.push_back(x);
		else s.push_back(x);
	}

	sort(all(b));
	sort(all(s));
	reverse(all(b));
	reverse(all(s));
	
	ll cnt = b.size(), p = 1;
	for (ll e : b) ps_b[p] = ps_b[p - 1] + e, p++;
	p = 1;
	for (ll e : s) ps_s[p] = ps_s[p - 1] + e, p++;
	while (p < MAXN) ps_s[p] = ps_s[n - cnt], p++;

	if (cnt == 0) return cout << ps_s[n] << endl, 0;
	ll ans = 0;
	
	for (ll i = 1; i <= cnt; i++) {
		if ((i - 1) * (d + 1) + 1 > n) continue;
		ll tans = ps_b[i];
		tans += ps_s[n - (i - 1) * (d + 1) - 1];
		ans = max(ans, tans);
	}

	cout << ans << endl;
}