#include <cstdio>

int main(){
	long long n;
	scanf("%I64d", &n);
	printf("%I64d\n", 2 - n % 2);
	return 0;
}