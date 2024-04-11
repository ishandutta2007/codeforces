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
	ll n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);

	if (n == 1) {
		ll n2 = m / 3;
		ll n1 = (m + 1) / 3;
		ll n0 = (m + 2) / 3;
		cout << n0 / 2 * 2 + n1 / 2 * 2 + n2 / 2 * 2 << "\n";
		return;
	}

	if (n == 2) {
		if (m < 3) cout << "0\n";
		else if (m == 3 || m == 7) cout << 2 * m - 2 << "\n";
		else cout << m * 2 << "\n";
		return;
	}

	cout << n * m - (n * m) % 2 << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 9;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}