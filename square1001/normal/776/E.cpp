#include <iostream>
using namespace std;
const int mod = 1000000007;
long long f(long long n) {
	long long ret = n;
	for (int i = 2; 1LL * i * i <= n; i++) {
		if (n % i == 0) {
			ret = ret / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n != 1) ret = ret / n * (n - 1);
	return ret;
}
long long solve(long long n, long long k, int depth) {
	if (depth >= 100) return n;
	if (k == 1) return f(n);
	if (k % 2 == 1) return f(solve(n, k - 1, depth + 1));
	return solve(n, k - 1, depth + 1);
}
long long N, K;
int main() {
	cin >> N >> K;
	cout << solve(N, K, 0) % mod << endl;
	return 0;
}