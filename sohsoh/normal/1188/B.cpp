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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, k, p;
map<ll, ll> mp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	cin >> n >> p >> k;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		x = (x * x % p * x % p * x % p - (k * x % p) + 100ll * p) % p;
		if (mp.find(x) == mp.end()) mp.insert({x, 0});
		mp[x]++;
	}

	ll ans = 0;
	for (pll e : mp) ans += e.Y * (e.Y - 1) / 2; 
	cout << ans << endl;
	return 0;
}