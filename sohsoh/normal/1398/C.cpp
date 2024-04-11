/*
    Soheil Mohammadkhani
    OK, im back :)
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

ll A[MAXN], ps[MAXN];

ll solve() {
	ll n;
	cin >> n;
	ps[0] = 0;
	map<ll, ll> mp;
	mp.insert({0, 1});
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		ll x = c - '0';
	
		//x -= i;
		ps[i] = x;
		ps[i] += ps[i - 1];
		if (mp.find(ps[i] - i) == mp.end()) mp.insert({ps[i] - i, 0});
		mp[ps[i] - i]++;
	}
	
//	alog(ps, n + 1)

	ll ans = 0;
	for (pll e : mp) {
		ans += e.Y * (e.Y - 1);
	}

	cout << ans / 2 << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}