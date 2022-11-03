#include <cstdio>

int main(){
	unsigned long long a, b;
	scanf("%I64u%I64u", &a, &b);
	printf("%I64d", a >= b && (a - b & (~b << 1)) == a - b ? (1ll << __builtin_popcountll(b)) - 2 * (a == b) : 0ll);
	return 0;
}