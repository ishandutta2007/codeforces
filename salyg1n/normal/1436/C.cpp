#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll mod = 1e9 + 7;

int main() {
	ll n, x, pos;
	cin >> n >> x >> pos;
	ll bol = 0, men = 0, l = 0, r = n;
	while (l < r) {
		ll m = (r + l) / 2;
		if (m < pos) {
			men++;
			l = m + 1;
		}
		else if (m > pos) {
			bol++;
			r = m;
		}
		else {
			l = m + 1;
		}
	}
	if (bol > n - x || men > x - 1) {
		cout << 0;
		return 0;
	}
	ll ans = 1;
	for (ll i = n - x; i > n - x - bol; --i) {
		ans *= i;
		ans %= mod;
	}
	for (ll i = x - 1; i > x - 1 - men; --i) {
		ans *= i;
		ans %= mod;
	}
	for (ll i = 1; i <= n - men - bol - 1; ++i){
		ans *= i;
		ans %= mod;
	}
	cout << ans;
	return 0;
}