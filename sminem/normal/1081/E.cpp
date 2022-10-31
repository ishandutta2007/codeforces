#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[200005];

ll koren(ll x) {
	if (x <= 0) return 0;
	ll l = max((ll)sqrt(x) - 2, 1ll), r = sqrt(x) + 2;
	ll o = 0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (m*m <= x) {
			o = m;
			l = m + 1;
		} else{
			r = m - 1;
		}
	}
	return o;
}

bool je_kv(ll x) {
	ll k = koren(x);
	return k*k == x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i+=2)
		cin >> a[i];

	ll zbir = 0;
	for (int i=2; i<=n; i+=2) {
		bool found = false;
		for (ll q = koren(zbir) + 1; q < 1231231ll; q++) {
			ll x = q*q - zbir;
			if (je_kv(zbir + x + a[i])) {
				a[i-1] = x;
				zbir += a[i-1] + a[i];
				found = true;
				break;
			}
		}
		if (!found) {
			cerr << i << '\n';
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}