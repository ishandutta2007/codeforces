#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int q;
ll a, b, m;


ll fib[55];

const ll inf = 1000000000000000000;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> q;


	fib[0] = fib[1] = 1LL;
	for (int i = 2; i < 55; i++) {
		fib[i] = fib[i-1]*2LL;
		fib[i] = min(fib[i], inf);
	}

	while (q--) {
		cin >> a >> b >> m;

		vector<ll> stuff;
		stuff.push_back(a);
		ll csum = a;
		ll cval = a;
		while (cval <= b) {
			cval = csum + 1LL;
			csum += cval;
			if (cval <= b) stuff.push_back(cval);
			else break;
		}
		ll cdiff = b - stuff.back();
		ll nterms = stuff.size();
		ll nextra = (nterms-1)*(m-1LL);

		// cout << cdiff << " - " << nextra << '\n';

		ll cinc = 0;
		vector<ll> res;
		res.push_back(a);
		csum = a;
		for (int i = 1; i < stuff.size(); i++) {
			ll cval = csum + 1LL;
			ll ccont = fib[stuff.size()-1-i];
			ll ntake = cdiff / ccont;
			ntake = min(ntake, m-1LL);

			// cout << i << " " << ccont << endl;

			cval += ntake;
			cdiff -= ntake * ccont;
			csum += cval;
			res.push_back(cval);


		}

		// cout << "CDIFF: " << cdiff << endl;
		if (res.back() != b) {
			//
			// for (ll v : res) {
			// 	cout << v << " ";
			// }

			cout << -1 << '\n';
			continue;
		}
		cout << res.size();
		for (ll vv : res) cout << " " << vv;

		cout << '\n';
		// cout << "fin: " << cdiff << '\n';
	}
	cout.flush();
}