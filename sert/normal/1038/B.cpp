#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = (int)1e6 + 34;
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false, E = false;

void solve() {
	ll n;
	cin >> n;
	ll sum = (n + 1) * n / 2;
	ll q = -1;
	for (ll i = 2; i * i <= sum; i++) {
		if (q == -1 && sum % i == 0) q = i;
	}

	if (q == -1) {
		cout << "No\n";
		return;
	}

	cout << "Yes\n";
	cout << "1 " << q << "\n";
	cout << n - 1;
	for (int i = 1; i <= n; i++) {
		if (i != q) cout << " " << i;
	}
	cout << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}