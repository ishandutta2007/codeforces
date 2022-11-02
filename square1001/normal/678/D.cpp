#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
const int mod = 1000000007;
int binpow(int a, long long b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int binpowsum(int a, long long b) {
	if (b == 1) return 1;
	if (b & 1) return (1LL * binpowsum(a, b - 1) * a + 1) % mod;
	return 1LL * binpowsum(a, b >> 1) * (binpow(a, b >> 1) + 1) % mod;
}
int A, B, X; long long N;
int main() {
	cin >> A >> B >> N >> X;
	cout << (1LL * binpow(A, N) * X + 1LL * binpowsum(A, N) * B) % mod << endl;
	return 0;
}