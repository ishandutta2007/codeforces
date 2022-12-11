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
	/*int n = 123;
	for (int a = 0; a < n; a++) {
		int num = 0;
		for (int x = 0; x <= a; x++) {
			if (a - (a ^ x) - x == 0) num++;
		}
		cout << a << " " << num << " " << (1ll << __builtin_popcount(a)) << "\n";
	}*/
	ll x;
	cin >> x;
	cout << (1ll << __builtin_popcount(x)) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	cin >> tst;
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