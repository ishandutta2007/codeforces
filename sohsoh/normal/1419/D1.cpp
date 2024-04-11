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
	set<ll> st;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		st.insert(x);
	}

	ll x = 0;
	ll a = 0;
	vector<ll> ans;
	while (!st.empty()) {
		if (x % 2 == 0) ans.push_back(*st.rbegin()), st.erase(*st.rbegin());
		else ans.push_back(*st.begin()), st.erase(st.begin());
		if (x & 1 && !st.empty()) a++;
		x++;
	}

	cout << a << endl;
	for (int i = 0; i < n; i++) cout << ans[i] << sep;
	cout << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t = 1;
	while (t--) solve();
	return 0;
}