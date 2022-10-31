#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll l, r, x, y;
	cin >> l >> r >> x >> y;

	set<ll> d;
	for (ll i=1; i*i<=y; i++) {
		if (y % i == 0) {
			d.insert(i);
			d.insert(y / i);
		}
	}

	ll c = 0;

	for (ll a : d) {
		for (ll b : d) {
			ll g = gcd(a, b);
			if (g == x && a*b/g == y && l <= a && a <= r && l <= b && b <= r)
				c++;
		}
	}

	cout << c;
}