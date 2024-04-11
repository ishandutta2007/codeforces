#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios :: sync_with_stdio(false);
	ll a, c; cin >> a >> c;
	ll b = 0;
	for(ll t = 1; t < 1e10; t *= 3) {
		ll ba = a % (t * 3) / t;
		ll bc = c % (t * 3) / t;
		ll bb = (bc - ba + 3) % 3;
		b += bb * t;
	}
	cout << b << '\n';
	return 0;
}