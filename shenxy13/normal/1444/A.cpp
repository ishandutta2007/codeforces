#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
bitset<32001> bs;
vector<int> primes;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 32000; ++i) {
		if (bs[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= 32000; j += i) bs[j] = 0;
		}
	}
}
int main() {
	sieve();
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		long long p, q, lcd, ans;
		scanf("%lld %lld", &p, &q);
		ans = lcd = p;
		for (int i: primes) {
			int pp = 0, qq = 0;
			while (p % i == 0) ++pp, p /= i;
			while (q % i == 0) ++qq, q /= i;
			if (qq == 0) continue;
			long long fix = 1;
			for (int j = 0; j <= pp - qq; ++j) fix *= i;
			lcd = min(lcd, fix);
		}
		if (q != 1) {
			long long fix = 1;
			while (p % q == 0) fix *= q, p /= q;
			lcd = min(lcd, fix);
		}
		ans /= lcd;
		printf("%lld\n", ans);
	}
	return 0;
}