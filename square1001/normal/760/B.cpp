#include <iostream>
using namespace std;
long long n, m, p;
long long g(long long x) {
	return x * (x + 1) / 2;
}
long long f(long long x, long long t) {
	// max(x-t+1, 1) + max(x-t+1, 1) + max(x-t+2, 1) + ... + max(x, 1)
	if (x >= t) return g(x) - g(x - t);
	return g(x) + (t - x);
}
long long solve(long long x) {
	return f(x, p + 1) + f(x, n - p) - x;
}
int main() {
	cin >> n >> m >> p; p--;
	long long l = 0, r = 1 << 30;
	while (r - l > 1) {
		long long mid = (l + r) >> 1;
		if (solve(mid) > m) r = mid;
		else l = mid;
	}
	cout << l << endl;
	return 0;
}