/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef int ll;
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
 
const ll MAXM = 1e6 + 10;
const ll MAXN = 6e3 + 100;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll pnt[MAXM] = {0};
vector<ll> R[MAXN];
ll dp[MAXN][MAXN] = {0};

ll solve() {
	ll n;
	cin >> n;
	vector<pll> v;
       	vector<ll> p;
	for (int i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		v.push_back({l, r});
		p.push_back(l);
		p.push_back(r);
	}

	sort(all(p));
	ll ind = 1;
	for (int i = 0; i < p.size(); i++) if (pnt[p[i]] < 1) pnt[p[i]] = ind, ind++;
	set<pll> st;
	for (pll e : v) {
		ll l = pnt[e.X];
		ll r = pnt[e.Y];
		R[l].push_back(r);
		st.insert({l, r});
	}

//	for (pll e : st) {debug(e.X) debug(e.Y)}

	for (int sz = 0; sz < 2 * n + 10; sz++) {
		for (int l = 0; l < 2 * n + 10 - sz; l++) {
			ll r = l + sz;
			if (r > l) dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
			for (ll e : R[l]) if (e < r) dp[l][r] = max(dp[l][r], dp[l][e] + dp[e + 1][r]);
			if (st.find({l, r}) == st.end()) continue;
			if (r > l) dp[l][r] = max(dp[l][r], 1 + max(dp[l][r - 1], dp[l + 1][r]));	
			else dp[l][r] = 1;
			
			for (ll e : R[l]) if (e < r) dp[l][r] = max(dp[l][r], dp[l][e] + dp[e + 1][r] + 1);
		}
	}
	
	cout << dp[0][2 * n + 2] << endl;
	
	for (int i = 0; i < 2 * n + 100; i++) {
		R[i].clear();
		for (int j = 0; j < 2 * n + 100; j++) dp[i][j] = 0;
	}

	for (ll e : p) pnt[e] = 0;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) solve();
}