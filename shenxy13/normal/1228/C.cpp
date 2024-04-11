#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bitset<32001> bs;
vector<long long> primes;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= 32000; ++i) {
		if (bs[i]) {
			primes.push_back(i);
			for (long long j = i * i; j <= 32000; j += i) bs[j] = 0;
		}
	}
}
long long expo(long long base, long long exp) {
	if (exp == 0) return 1;
	long long ans = expo(base, exp / 2);
	ans = (ans * ans) % 1000000007;
	if (exp % 2) ans = (ans * base) % 1000000007;
	return ans;
}
int main() {
	sieve();
	long long x, n, ans = 1;
	vector<long long> factors;
	scanf("%lld %lld", &x, &n);
	for (long long i: primes) {
		if (x % i == 0) factors.push_back(i);
		while (x % i == 0) x /= i;
	}
	if (x != 1) factors.push_back(x);
	for (long long i: factors) {
		long long j = n / i, k = i;
		while (j > 0) {
			ans *= expo(k, j);
			ans %= 1000000007;
			j /= i;
		}
	}
	printf("%lld", ans);
	return 0;
}