#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

ll mpow(ll b, ll e) {
	ll res = 1;
	for(ll k = 1; k <= e; k *= 2) {
		if(k & e) res = (res * b) % MOD;
		b = (b * b) % MOD;
	}
	return res;
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	if(k == -1) {
		if(n % 2 != m % 2) {
			cout << "0\n";
			return 0;
		}
	}
	ll res = mpow(2, m - 1);
	cout << mpow(res, n - 1) << '\n';
}