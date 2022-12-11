#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

void solve() {
	ll n, m, q;
	cin >> n >> m >> q;
	ll g = __gcd(n, m);
	ll pn = n / g;
	ll pm = m / g;

	while (q--) {
		ll t, x, y;
		cin >> t >> x;
		x--;
		if (t == 1) x /= pn;
		else x /= pm;

		cin >> t >> y;
		y--;
		if (t == 1) y /= pn;
		else y /= pm;

		cout << (x == y ? "YES\n" : "NO\n");
	}
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}