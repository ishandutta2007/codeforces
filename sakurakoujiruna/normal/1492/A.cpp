#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	int t; cin >> t;
	while(t --) {
		ll p; cin >> p;
		ll ans = 1e18L;
		for(int i = 0; i < 3; i ++) {
			ll a; cin >> a;
			ll b = (a - p % a) % a;
			ans = min(ans, b);
		}
		
		cout << ans << '\n';
	}
}