#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ZZQ, BS;
ll qprod(ll a, ll b) {
	ll res = 0;
	while (b) {
		if (b & 1) res = (res + a) % ZZQ;
		a = a * 2 % ZZQ;
		b >>= 1;
	}
	return res;
}
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = qprod(res, a);
		a = qprod(a, a);
		b >>= 1;
	}
	return res;
}
int main() {
	int q = 100;
	cin >> ZZQ;
	BS = ZZQ - qprod(4500, qpow(10, 99)) - 1;
	cout << BS + 1 << endl;
	ll tmp = BS;
	while (tmp) tmp /= 10, q--;
	cout << 1;
	while (q--) printf("0");
	if (BS) cout << BS << endl;
	return 0;
}