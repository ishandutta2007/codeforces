#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long a, b, n, x;

long long expmod(long long a, long long b) {
	long long rlt = 1, x = a % mod;
	while (b) {
		if (b & 1) rlt = rlt * x % mod;
		x = x * x % mod, b >>= 1;
	}
	return rlt;
}

long long calc() {
	long long rlt = expmod(a, n) * x % mod;
	if (a == 1) {
		rlt = (rlt + (n % mod) * b) % mod;
		return rlt;
	}
	rlt = (rlt + ((expmod(a, n) - 1) * expmod(a - 1, mod - 2) % mod) * b) % mod;
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	cin >> a >> b >> n >> x;
	cout << calc() << endl;
	return 0;
}