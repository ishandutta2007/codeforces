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

ll n, k;
ll X;
int it = 0;

ll rnd(ll md) {
	ll x = 0;
	ll mx = 2e6;
	for (int i = 0; i < 3; i++) {
		x = x * mx + rand() % mx;
	}
	return x % md;
}

void init() {
	X = rand() % n;
	it = 0;
}

void move() {
	ll mn = max(0ll, X - k);
	ll mx = min(n - 1, X + k);
	X = mn + rnd(mx - mn + 1);
}

bool isInSeg(ll l, ll r) {
	it++;
	if (D) {
		return (l <= X && X <= r);
	} else {
		cout << l + 1 << " " << r + 1 << endl;
		string res;
		cin >> res;
		return (res == "Yes");
	}
}

void solve() {
	cin >> n >> k;
	if (n == -1) n = 1e18;
	init();

	ll l = 0;
	ll r = n - 1;
	while (true) {		
		l = max(0ll, l - k);
		r = min(n - 1, r + k);
		//cout << it << " " << l << " " << r << "\n";

		if (r - l < 100) {
			ll x = l + rnd(r - l + 1);
			if (isInSeg(x, x)) {
				break;
			}
		} else {
			ll m = (l + r) / 2;
			if (isInSeg(l, m)) r = m;
			else l = m + 1;
		}
	}
	if (D) {
		cerr << "Ok in " << it << " iterations!\n";
	}
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	//D = true;	
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}