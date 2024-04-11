#include <cstdio>

int main(){
	long long n;
	scanf("%I64d", &n);
	n = (n % 360 + 404) % 360;
	printf("%I64d", n / 90 * !!(n - 359));
	return 0;
}