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

ll solve() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v;
	set<pll> st;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		v.push_back(x);
	}
	
	sort(all(v));
	for (int i = 0; i < n; i++) st.insert({v[i], i});
	
	ll poker_face;
	for (int i = 0; i < n; i++) cin >> poker_face;
	
	vector<pair<pll, ll>> A;
	for (pll e : st) {
		auto it = st.lower_bound({e.X + k + 1, -1});
		it--;
		A.push_back({{e.X, it -> X},  it -> Y - e.Y + 1});
	}

	sort(all(A));

	vector<pll> mx;
	mx.push_back({INF, 0});
	for (int i = n - 1; i >= 0; i--) {
		mx.push_back({A[i].X.X, max(mx.back().Y, A[i].Y)});
	}
	
	reverse(all(mx));	/*
	for (pll e : mx) {
		debug(e.X) debug(e.Y)}*/

	ll ans = 0;
	for (pair<pll, ll> e : A) {
		ans = max(ans, e.Y + lower_bound(all(mx), make_pair(e.X.Y + 1, -1ll)) -> Y);
	}

	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}