#include <bits/stdc++.h>
using namespace std;
inline unsigned long long modpow(unsigned long long a, unsigned long long b, unsigned m) {
	unsigned ret = 1; a %= m;
	while (b) {
		if (b & 1) ret = 1ULL * ret * a % m;
		a = 1ULL * a * a % m;
		b >>= 1;
	}
	return ret;
}
int n;
int main() {
	cin >> n;
	cout << modpow(1378, n, 10) << endl;
	return 0;
}