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

vector<pll> v;
int solve() {
	int n, k;
	cin >> n >> k;
	v.clear();
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	
	for (pll e : v) {
		bool tok = true;
		for (pll e2 : v) {
			if (abs(e.X - e2.X) + abs(e.Y - e2.Y) > k) tok = false;
		}

		if (tok) return cout << 1 << endl, 0;
	}

	cout << -1 << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}	
	return 0;
}