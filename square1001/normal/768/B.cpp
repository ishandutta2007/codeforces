#include <map>
#include <vector>
#include <iostream>
using namespace std;
long long n, l, r, b;
long long solve(long long x) {
	long long ret = 0;
	for (int i = 0; i < b; i++) {
		if (n & (1LL << i)) ret += (x >> (b - i - 1)) - (x >> (b - i));
	}
	return ret;
}
int main() {
	cin >> n >> l >> r;
	while (1LL << b <= n) b++;
	cout << solve(r) - solve(l - 1) << endl;
	return 0;
}