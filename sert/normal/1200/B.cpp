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
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];

	for (int i = 0; i < n - 1; i++) {		
		if (h[i] + k < h[i + 1]) m -= h[i + 1] - (h[i] + k);
		else m += h[i] - max(0ll, h[i + 1] - k);

		// cout << m << " ";
		if (m < 0) {
			cout << "NO\n";
			return;
		}			
	}
	cout << "YES\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
#ifdef MADE_BY_SERT
	D = true;	
	tst = 5;
	while (tst--) {
		solve();
	}
#else
	cin >> tst;
	while (tst--) solve();
#endif
}