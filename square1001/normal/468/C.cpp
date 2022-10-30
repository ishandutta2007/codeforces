#include <random>
#include <vector>
#include <iostream>
using namespace std;
const long long limit = 50000000000000000;
mt19937 mt(128687459);
long long rand_rng(long long l, long long r) {
	uniform_int_distribution<long long> p(l, r - 1);
	return p(mt);
}
long long sum(long long r) {
	// digit(1) + digit(2) + digit(3) + ... + digit(r - 1)
	long long ret = 0, mul = 1;
	for (int i = 0; i < 18; i++) {
		ret += ((r / (mul * 10)) * 45 + (r / mul % 10) * (r / mul % 10 - 1) / 2) * mul + (r % mul) * (r / mul % 10);
		mul *= 10;
	}
	return ret;
}
vector<long long> solve(long long x) {
	if (x <= 1000) x *= 1000;
	for (int i = 0; i < 3000; i++) {
		long long l = rand_rng(0, limit);
		long long pl = l, pr = limit * 2;
		while (pr - pl > 1) {
			long long pm = (pl + pr) / 2;
			if (sum(pm) - sum(l) < x) pl = pm;
			else pr = pm;
		}
		if (sum(pl + 1) - sum(l) == x) return{ l, pl };
	}
	return{ -1, -1 };
}
int main() {
	long long n;
	cin >> n;
	vector<long long> ret = solve(n);
	cout << ret[0] << ' ' << ret[1] << endl;
	return 0;
}