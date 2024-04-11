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

#define int 		long long


ll calc(int n, int t) {
	ll x = 0;
	while (n % t == 0) {
		n /= t;
		x++;
	}

	return x;
}

int solve() {
	ll n;
	cin >> n;
	ll sq = sqrt(n);
	pll b = {1, n};
	for (int i = 2; i <= sq; i++) {	
		if (n % i == 0) {
			b = max(b, {calc(n, i), i});
			b = max(b, {calc(n, n / i), n / i});
		}	
	}

	ll a = 1;
	cout << b.X << endl;
	for (int i = 0; i < b.X - 1; i++) {
		cout << b.Y << sep;
		a *= b.Y;
	}

	n /= a;
	cout << n << sep << endl;
	return 0;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();	
	return 0;
}