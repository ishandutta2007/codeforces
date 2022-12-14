//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ll n;
	cin >> n;
	ll ans = 0;
	for(int i = 0; i < n;i++) {
		ll x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ans += (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
	}
	cout << ans <<'\n';
	return 0;
}