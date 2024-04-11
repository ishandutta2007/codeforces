#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main() {
	ll m, b;
	cin >> m >> b;
	ll x, y;
	ll ans = 0;
	x = 0;
	y = b;
	while (y >= 0) {

		ll cur = ((y+1)*y/2)*(x+1) + ((x+1)*x/2)*(y+1);
		ans = max(ans, cur);
		y-=1;
		x+=m;
	}
	cout << ans << endl;
	// cin >> m;
}