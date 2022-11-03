#include <cstdio>

int main(){
	long long n;
	scanf("%I64d", &n);
	printf("%I64d\n", 3 * n * (n + 1) + 1);
	return 0;
}