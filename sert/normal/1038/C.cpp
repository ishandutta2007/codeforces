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

int a[N], b[N];
void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	sort(a, a + n);
	sort(b, b + n);
	int ca = n - 1, cb = n - 1;
	ll ans = 0;
	while (ca >= 0 || cb >= 0) {
		//cout << ca << " " << cb << " " << ans << "\n";
		if ((ca + cb) % 2 == 0) {
			if (cb == -1 || (ca >= 0 && a[ca] >= b[cb])) {
				ans += a[ca--];
			} else {
				cb--;
			}
		} else {
			if (cb == -1 || (ca >= 0 && a[ca] >= b[cb])) {
				ca--;
			} else {
				ans -= b[cb--];
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) solve();
#else
	while (tst--) solve();
#endif
}