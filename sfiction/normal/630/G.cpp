#include <cstdio>

int main(){
	long long n;
	scanf("%I64d", &n);
	printf("%I64d\n", (n + 2) * (n + 1) * n / 6 * ((n + 4) * (n + 3) * (n + 2) * (n + 1) * n / 120));
	return 0;
}