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

ll a[N];
void solve() {
	ll n, m, l;
	cin >> n >> m >> l;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > l && (i == 0 || a[i - 1] <= l)) ans++;
	}
	while (m--) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << ans << "\n";
			continue;
		}

		ll p, x;
		cin >> p >> x;
		p--;
		if (a[p] <= l && a[p] + x > l) {
			ans++;
			if (p > 0 && a[p - 1] > l) ans--;
			if (p + 1 < n && a[p + 1] > l) ans--;
		}
		a[p] += x;		
	}
}

int main() {
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