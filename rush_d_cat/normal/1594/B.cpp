#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll mpow(ll a, ll x) {
	if (x == 0) return 1;
	ll t = mpow(a, x>>1);
	if (x%2==0)
		return t*t%mod;
	return t*t%mod*a%mod;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		ll ans = 0;
		for (int i = 0; i < 30; i ++)
			if (k >> i & 1)
				(ans += mpow(n, i)) %= mod;
		cout << ans << "\n";
	}
}
/*
1
3
1+3

1,2,3,4

*/