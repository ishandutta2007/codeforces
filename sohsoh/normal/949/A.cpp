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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<vector<ll>> v;
	set<ll> O, Z;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') Z.insert(i + 1);
		else O.insert(i + 1);
	}

	while (!Z.empty()) {
		ll x = *Z.begin();
		Z.erase(Z.begin());
		vector<ll> t;
		t.push_back(x);
		while (true) {
			if (O.empty() || O.lower_bound(x) == O.end()) break;
			ll y = *O.lower_bound(x);
			if (Z.empty() || Z.lower_bound(y) == Z.end()) break;
			t.push_back(y);
			x = *Z.lower_bound(y);
			t.push_back(x);
			O.erase(y);
			Z.erase(Z.lower_bound(y));
		}

		v.push_back(t);	
	}

	if (!O.empty()) return cout << -1 << endl, 0;
	cout << v.size() << endl;
	for (vector<ll> t : v) {
		cout << t.size() << sep;
		for (ll e : t) cout << e << sep;
		cout << endl;
	}
	return 0;
}