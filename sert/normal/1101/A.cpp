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
	ll d, l, r;
	cin >> l >> r >> d;
	if (l > d) {
		cout << d << "\n";
	} else {
		cout << (r + d) - (r + d) % d << "\n";
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
	cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	//tst = 1;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}