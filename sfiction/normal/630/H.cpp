#include <cstdio>

int main(){
	long long n;
	scanf("%I64d", &n);
	long long t = n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
	printf("%I64d\n", t / 120 * t);
	return 0;
}