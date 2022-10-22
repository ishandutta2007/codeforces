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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

set<ll> O, T2, T3;
set<pll> T2t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> v3;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (x == 1) O.insert(i);
		if (x == 2) T2.insert(i);
		if (x == 3) T3.insert(i), v3.push_back(i);
	}

	vector<pll> ans;
	ll r = n;
	for (ll e : T2) {
		if (O.lower_bound(e) == O.end()) return cout << -1 << endl, 0;
		else {
			auto it = O.lower_bound(e);
			ans.push_back({r, e});
			ans.push_back({r, *it});	
			O.erase(it);
		}

		r--;
	}

	
	reverse(all(v3));
	for (ll e : v3) {
		if (T3.upper_bound(e) == T3.end()) {
			if (O.lower_bound(e) != O.end()) {
				auto it = O.lower_bound(e);
				ans.push_back({r - 1, e});
				ans.push_back({r - 1, *it});
				ans.push_back({r, *it});
				r -= 2;
				O.erase(it);
			} else if (!T2.empty() && (*T2.rbegin()) > e) {
				ans.push_back({r, e});
				ans.push_back({r, (*T2.rbegin())});
				r--;
			} else return cout << -1 << endl, 0;
		} else {
			auto it = T3.upper_bound(e);
			ans.push_back({r, e});
			ans.push_back({r, *it});
			r--;
			T3.erase(it);	
		}
	}

	for (ll e : O) ans.push_back({r, e}), r--;
	
	cout << ans.size() << endl;
	for (pll e : ans) cout << e.X << sep << e.Y << endl;
	return 0;
}