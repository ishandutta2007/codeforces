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

ll n;
vector<pll> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		char c;
		cin >> c;
		if (c == '+') v.push_back({1, 0});
		else {
			ll x;
			cin >> x;
			v.push_back({-1, x});
		}
	}

	reverse(all(v));
	set<ll> st;
	vector<ll> ans;
	for (pll e : v) {
		if (e.X == 1) {
			if (st.empty()) return cout << "NO" << endl, 0;
			else ans.push_back(*st.begin()), st.erase(st.begin());
		} else {
			if (!st.empty() && e.Y > *st.begin()) return cout << "NO" << endl, 0;
			else st.insert(e.Y);
		}
	}	

	cout << "YES" << endl;
	reverse(all(ans));
	for (ll e : ans) cout << e << sep;
	cout << endl;
	return 0;
}