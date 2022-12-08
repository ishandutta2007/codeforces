#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	ll n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	ll dc = k*l/(nl*n);
	ll sc = c*d/n;
	ll gc = p/(n*np);
	ll ans = min(dc, min(sc, gc));
	cout << ans << endl;
	// cin >> n;
}