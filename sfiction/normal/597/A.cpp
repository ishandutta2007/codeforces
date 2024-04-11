#include <cstdio>

typedef long long ll;

int main(){
	ll k, a, b;
	scanf("%I64d%I64d%I64d", &k, &a, &b);
	a = (a >= 0 ? (a + k - 1) : a) / k;
	b = (b >= 0 ? b : (b - k + 1)) / k;
	printf("%I64d\n", b - a + 1);
	return 0;
}