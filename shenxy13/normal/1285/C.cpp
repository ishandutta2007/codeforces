#include <cstdio>
#include <algorithm>
using namespace std;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	long long X, a = 1000000000000LL, b = 1000000000000LL;
	scanf("%lld", &X);
	for (long long i = 1; i * i <= X; ++i) {
		if (X % i == 0 && gcd(i, X / i) == 1) a = i, b = X / i;
	}
	printf("%lld %lld", a, b);
	return 0;
}