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

set<ll> diff, st;

ll pref_mx[MAXN] = {0}, suff_mx[MAXN] = {0};

int main() {
	fast_io;
	ll n;
	cin >> n;
	vector<ll> v1;
	vector<pll> v2;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x > 0) v1.push_back(1 + n - x);
	}

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x > 0) {
			if (x > i + 1) v1.push_back(i + 2 + n - x);
		       	else v2.push_back({i + 1 - x, 1 + i + 1 + n - x});	
		}
	}

	ll mx_1 = 0;
	if (!v1.empty()) mx_1 = *max_element(all(v1));
	if (v2.empty()) return cout << mx_1 << endl, 0;
	
	for (pll e : v2) {
		pref_mx[e.X] = max(pref_mx[e.X], e.Y);	
		suff_mx[e.X] = max(suff_mx[e.X], e.Y);	
	}

	for (int i = 1; i < MAXN; i++) pref_mx[i] = max(pref_mx[i - 1], pref_mx[i]);
	for (int i = MAXN - 10; i >= 0; i--) suff_mx[i] = max(suff_mx[i + 1], suff_mx[i]);

	if (mx_1 <= 0 && suff_mx[1] <= 0) return cout << 0 << endl, 0;
	ll ans;
	for (int i = 1; i < MAXN - 10; i++) {
		ans =  max(max(mx_1, pref_mx[i - 1]), suff_mx[i + 1]);
		if (ans <= i) return cout << i << endl, 0;
	
	}

	cout << ans << endl;


	return 0;
}