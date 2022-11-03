#include <cstdio>

int main(){
	long long n, i, s = 1;
	scanf("%I64d", &n);
	for (i = 2; i * i <= n; ++i)
		if (n % i == 0){
			for (s *= i ;n % i == 0; n /= i);
		}
	printf("%I64d\n", s *= n);
	return 0;
}