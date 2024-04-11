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
	vector<ll> num(m, 0);

	if (m == 1) {
		cout << n * n << "\n";
		return;
	}

	for (int i = 1; i <= m; i++) {
		num[i * i % m]++;		
	}

	for (int i = 0; i < m; i++) {
		num[i] *= n / m;
	}

	for (ll i = n; i % m != 0; i--) {
		num[i * i % m]++;
	}

	/*for (int i = 0; i < m; i++) {
		cout << num[i] << " ";
	}
	cout << "\n";*/

	ll ans = 0;
	for (int i = 0; i < m; i++) {
		if (i == 0) ans += num[0] * num[0];
		else ans += num[m - i] * num[i];
	}

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
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}