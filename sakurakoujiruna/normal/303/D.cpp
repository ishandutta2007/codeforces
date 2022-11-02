#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll qpow(ll a, ll b, ll mod) {
	ll r = 1 % mod;
	for(; b; b /= 2) {
		if(b & 1)
			r = r * a % mod;
		a = a * a % mod;
	}
	return r;
}

bool prime(int x) {
	if(x < 2) return 0;
	for(int i = 2; i * i <= x; i ++)
		if(x % i == 0) return 0;
	return 1;
}

bool root(int x, int p) {
	if(x % p == 0 || x % p == 1 && p != 2) return 0;
	for(int i = 2; i * i <= p - 1; i ++) if((p - 1) % i == 0) {
		if(qpow(x, (p - 1) / i, p) == 1 ||
			qpow(x, i, p) == 1) return 0;
	}
	return 1;
}

int main() {
	ios :: sync_with_stdio(0);
	int n, x; cin >> n >> x;
	if(!prime(n + 1))
		cout << "-1\n";
	else {
		for(int i = x - 1; i > 1; i --)
			if(root(i, n + 1)) return cout << i << '\n', 0;
		cout << "-1\n";
	}
}