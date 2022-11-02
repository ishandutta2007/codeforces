#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int binpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main() {
	int x, y;
	cin >> x >> y;
	if (y % x != 0) {
		cout << "0\n";
	}
	else {
		int n = y / x, t = n;
		vector<int> divpri;
		for (int i = 2; i * i <= t; ++i) {
			if (t % i == 0) {
				divpri.push_back(i);
				while (t % i == 0) t /= i;
			}
		}
		if (t != 1) divpri.push_back(t);
		int ret = 0;
		for (int i = 0; i < 1 << divpri.size(); ++i) {
			int mul = n, f = 0;
			for (int j = 0; j < divpri.size(); ++j) {
				if ((i >> j) & 1) mul /= divpri[j], f ^= 1;
			}
			int delta = binpow(2, mul - 1);
			if (f == 0) ret = (ret + delta) % mod;
			else ret = (ret + mod - delta) % mod;
		}
		cout << ret << '\n';
	}
	return 0;
}