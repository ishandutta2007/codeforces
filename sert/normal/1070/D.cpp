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
	ll n, k;
	cin >> n >> k;
	ll rem = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		if (x + rem < k && x + rem > 0 && rem > 0) {
			rem = 0;
			ans++;
		} else {
			ans += (x + rem) / k;
			rem = (x + rem) % k;
		}
	}
	if (rem > 0) ans++;
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
	tst = 4;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}