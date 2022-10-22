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
const ll LOG = 20;

ll Z[MAXN] = {0};

void solve() {
	memset(Z, 0, sizeof Z);
	string s;
	cin >> s;

	ll tm = 0;
	for (int i = 0; i < s.size(); i++) {
		Z[i] = tm;
		tm++;
		if (s[i] == '1') tm = 0;
	}

	ll ans = 0;
	for (int sz = 1; sz < LOG; sz++) {
		for (int L = 0; L <= ll(s.size()) - sz; L++) {
			if (s[L] == '0') continue;
			ll val = 0;
			for (int i = 0; i < sz; i++) {
				if (s[L + i] == '1') val += (1 << (sz - i - 1));
			}

			if (val == sz) ans++;
			if (val > sz && Z[L] >= (val - sz)) ans++; 
		}

	}

	cout << ans << endl;	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}