#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const ll MAXN = 1e5 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 40; 

int ps[LOG];

inline int solve() {
	memset(ps, 0, sizeof ps);
	int j = 1;
	ll a, b;
	cin >> a >> b;
	if (a > b) return cout << "NO" << endl, 0;
	while (a) {
		ps[j] = ps[j - 1];
		if (a & 1ll) ps[j]++;
		a >>= 1ll;
		j++;

	}	

	while (j < LOG) ps[j] = ps[j - 1], j++;
	
	j = 1;
	int ps2 = 0;
	while (b) {
		if (b & 1ll) ps2++;
		if (ps2 > ps[j]) return cout << "NO" << endl, 0;
		b >>= 1ll;
		j++;
	}

	cout << "YES" << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}