#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;

ll calc(ll l, ll r, ll k) {
	return (r >> k) - ((l - 1) >> k);
}

vector<pll> find(ll l, ll r, ll k) {
	ll num = calc(l, r, k) - calc(l, r, k + 1);
	ll mx = (1ll << k) - 1;
	vector<pll> ans(0);
	if (num > 2) {
		ans.pb(mp(mx, mx));
		return ans;
	}
	if (num == 0) {
		return ans;
	}
	ll d = (1ll << k);
	ll lq = (l / d) * d - 2 * d;
	while (lq < l || ((lq >> k) & 1) == 0) {
		lq += d;
	}
	ans.pb(mp(min(lq - l, mx), min(r - lq, mx)));
	ll rq = (r / d) * d + 2 * d;
	while (rq > r || ((rq >> k) & 1) == 0) {
		rq -= d;
	}
	ans.pb(mp(min(rq - l, mx), min(r - rq, mx)));
	return ans;
}

int main() {
	ll l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	ll mx = 0;
	forn (i, 30) {
		vector<pll> f1 = find(l1, r1, (ll)i);
		vector<pll> f2 = find(l2, r2, (ll)i);
		forn (i, f1.size()) {
			forn (j, f2.size()) {
				mx = max(mx, min(f1[i].fs, f2[j].fs) + 1 + min(f1[i].sc, f2[j].sc));
			}
		}
	}
	cout << mx;
	return 0;
}