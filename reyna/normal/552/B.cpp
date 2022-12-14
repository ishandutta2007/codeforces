//In the name of God
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
	ll n;
	cin >> n;
	ll cur = 9;
	ll o = 10;
	ll add = 1;
	ll ans = 0;
	while(n) {
		if(n < o) {
			n -= (o / 10) - 1;
			ans += n * add;
			break;
		}
		ans += cur * add;
		cur *= 10;
		o *= 10;
		add++;
	}
	cout << ans << '\n';
	return 0;
}