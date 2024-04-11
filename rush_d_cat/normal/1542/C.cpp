#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 200000 + 10;
const ll mod = 1e9 + 7;
ll gcd(ll x, ll y) {
	return y==0?x:gcd(y,x%y);
}
ll lcm(ll x, ll y) {
	return x / gcd(x, y) * y;
}
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		ll n;
		cin >> n;
		// >=2 lcm(1)  n
		// >=3 lcm(1,2)
		vector<ll> f(202, 0);
		ll s = 1, las = 0, ans = 0;
		for (int i = 2; i <= 200; i ++) {
			s = lcm(s, ++las);
			f[i] = n / s;
			if (s > n) break;
		}
		for (int i = 2; i <= 200; i ++) {
			ans += (f[i] - f[i+1]) % mod * i;
			ans %= mod;
			if (f[i] == 0) break;
		}
		ans = (ans % mod + mod) % mod;
		cout << ans << endl;
	}
}