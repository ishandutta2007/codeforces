#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 1e6 + 10;
const ll INF = 1e9 + 10;

inline ll sq(ll n) {
	ll l = 0, r = 2 * INF;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		if (mid * mid > n) r = mid - 1;
		else l = mid;
	}

	return l;
}

inline ll f(ll n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;


	ll x = sq(n);
	if (x * (x + 1) > n) return 3 * (x - 1) + 1;
	if (x * (x + 2) > n) return 3 * (x - 1) + 2;
	return 3 * x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << f(r) - f(l - 1) << endl;
	}
	return 0;
}