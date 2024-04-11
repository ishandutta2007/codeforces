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

ll go(ll a1, ll b1, ll a2, ll b2) {
	return max(0ll, min(b1, b2) - max(a1, a2) + 1);
}

void solve() {
	ll a1, b1, tt1;
	ll a2, b2, tt2;
	cin >> a1 >> b1 >> tt1;
	cin >> a2 >> b2 >> tt2;
	ll g = __gcd(tt1, tt2);

	ll ans = 0;

	a2 += g * INF;
	b2 += g * INF;

	ll t1 = (a2 - a1) / g;
	ll t2 = (b2 - b1) / g;

	ans = max(ans, go(a1 + t1 * g, b1 + t1 * g, a2, b2));
	ans = max(ans, go(a1 + t1 * g + g, b1 + t1 * g + g, a2, b2));
	ans = max(ans, go(a1 + t2 * g, b1 + t2 * g, a2, b2));
	ans = max(ans, go(a1 + t2 * g + g, b1 + t2 * g + g, a2, b2));

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 2;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}