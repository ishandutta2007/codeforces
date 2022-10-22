#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const ll INF = 1e9 + 7;

void solve() {
	ll p, q;
	cin >> p >> q;
	ll res = 1;
	ll d = q;
	for (ll i = 2; i * i <= q; ++i) {
		if (d % i) continue;
		ll x = p;
		while (x % d == 0 && x % i == 0) {
			x /= i;
		}
		while (d % i == 0) {
			d /= i;
		}
		if (x % q) {
			res = max(res, x);
		}
	}
	if (d != 1) {
		ll x = p;
		while (x % d == 0) {
			x /= d;
		}
		if (x % q) {
			res = max(res, x);
		}
	}
	cout << res << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}

}