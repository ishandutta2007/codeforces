#include <cstdio>
#include <algorithm>
using namespace std;
long long expo(long long base, long long exp) {
	if (exp == 0) return 1;
	long long ans = expo(base, exp / 2);
	ans = (ans * ans) % 1000000007;
	if (exp % 2) ans = (ans * base) % 1000000007;
	return ans;
}
int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	long long k = expo(2, m) - 1;
	if (k < 0) k += 1000000007;
	k = expo(k, n);
	printf("%lld", k);
	return 0;
}