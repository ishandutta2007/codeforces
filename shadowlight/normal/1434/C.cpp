#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

ll a, b, c, d;
ll val;

const ll INF = 1e12 + 7;
const int MAXN = 1e9 + 7; 
const ll INFF = 1e18 + 7;

ll f1(ll l) {
	ll t = (l - 1) * l / 2 * d;
	if (t < INF) {
		t *= b;
	} else {
		return -INF;
	}
	return a * l - t;
}

ll f2(ll l) {
	ll t = a * l;
	ll tt = (l - val) * b;
	if (tt < INFF / c) {
		tt *= c;
	} else {
		tt = INFF;
	}
	t -= tt;
	t -= (val - 1) * val / 2 * d * b;
	return t;
}

void solve() {
	cin >> a >> b >> c >> d;

	if (a > b * c) {
		cout << "-1\n";
		return;
	}

	ll val = c / d;
	if (c % d) {
		++val;
	}

	ll l = 0, r = val + 1;
	for (int it = 0; it < 50; ++it) {
		ll m1 = l + (r - l) / 3;
		ll m2 = l + 2 * (r - l) / 3;
		if (f1(m1) == -INF || f1(m2) == -INF) {
			r = m2;
		} else if (f1(m1) > f1(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	ll res = 0;
	for (int i = l; i <= r; ++i) {
		res = max(res, f1(i));
	}

	l = val + 1, r = MAXN;
	for (int it = 0; it < 50; ++it) {
		ll m1 = l + (r - l) / 3;
		ll m2 = l + 2 * (r - l) / 3;
		if (f2(m1) == -INF || f2(m2) == -INF) {
			r = m2;
		} else if (f1(m1) > f2(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	for (int i = l; i <= r; ++i) {
		res = max(res, f2(i));
	}

	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}