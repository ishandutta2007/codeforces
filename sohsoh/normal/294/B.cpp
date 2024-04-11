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

vector<ll> o, t;
ll ps_o[MAXN], ps_t[MAXN];

int main() {
	fast_io;
	ll n;
	cin >> n;
	ll k1 = 0, k2 = 0;
	for (int i = 0; i < n; i++) {
	 	ll th, w;
		cin >> th >> w;
		if (th == 1) o.push_back(w), k1++;
		else t.push_back(w), k2++;
	}

	sort(all(o));
	sort(all(t));

	ps_o[0] = ps_t[0] = 0;
	for (int i = 1; i <= k1; i++) ps_o[i] = ps_o[i - 1] + o[i - 1];
	for (int i = 1; i <= k2; i++) ps_t[i] = ps_t[i - 1] + t[i - 1];

	ll ans = INF;
	for (int i = 0; i <= k1; i++) {
		for (int j = 0; j <= k2; j++) {
			ll tans = i + 2 * j;
			if (ps_o[k1 - i] + ps_t[k2 - j] <= tans) ans = min(ans, tans);	
		}
	}

	cout << ans << endl;

	return 0;
}