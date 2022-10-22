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
	ll n;
	cin >> n;
	ll a1 = 0, a2 = INF, b1 = 0, b2 = INF;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		vector<pll> ans;
		for (int j = 0; j < 5; j++) {
			if (x + j == a1) ans.push_back({b2 + j * y, x + j});
			else ans.push_back({b1 + j * y, x + j});
		}

		sort(all(ans));
		a1 = ans[0].Y;
		b1 = ans[0].X;
		a2 = ans[1].Y;
		b2 = ans[1].X;
	}

	cout << b1 << endl;
	return 0;
}

int main() {
	fast_io;
	ll t = 1;
	cin >> t;
	while (t--) {
		solve();	
	}

	return 0;
}